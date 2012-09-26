
							Jim Grishaw
							7/1/02

							Abe Backus
							7/10/03

							Dr. Volker Zell
							3/9/2008
University of Washington IMAP 4rev1 server for Cygwin
-----------------------------------------------

     This is a port of the UW IMAP Server to the Cygwin platform.  Cygwin
is a UNIX overlay for Windows 98/NT/XP/2000 (see www.cygwin.com).

Lines starting with # are from the original port and do not apply anmore.

IMAPD Installation/Setup Tips:
-----------------------------

#(1)  Make sure the following lines exist in your /etc/passwd file:
#Everyone:*:0:0:,S-1-1-0::
#SYSTEM:*:18:18:,S-1-5-18::

(1)  Make sure you have created your /etc/passwd file with 
     /usr/bin/mkpasswd.

(2)  If you do NOT want to use md5 authentication (NOT recommended under
     windows because the passwords are stored in unencrypted format),
     make sure the file "/etc/cram-md5.pwd" does NOT exist.

(3)  All directories where you have mail MUST be mounted as "binmode".
     Otherwise, your mail folders will be corrupted.  imapd.exe cannot
     deal with the extra ^M's that come from text-mounted filesystems.

#(4)  Likewise, do not use "inetlisn.exe" because you will again have
#     trouble with the ^M's at the end of each line.

#(5)  Make sure that your /etc/inetd.conf file contains the following line:
#imap stream tcp nowait root /usr/sbin/imapd
#     Also make sure that the Cygwin inetd daemon is properly running (refer
#     to the Cygwin inetd installation instructions in
#     /usr/share/doc/Cygwin/inetutils-*.README).

(5)  Setup inetd or xinetd according to the documentation in docs/SSLBUILD.

#(6)  Make sure that the file /cygdrive/C/WINNT/system32/drivers/etc/SERVICES
#     contains the line:
#imap              143/tcp

(6)  Configure /cygdrive/<Drive-Letter>/<WINDOWS-Directory>/system32/drivers/etc/SERVICES
     according to servies setup in docs/SSLBUILD.
     Setup certificates according to STEP 4: certificates setup in 
     docs/SSLBUILD. But change all references in that doc from 
     /usr/local/ssl/certs -> /usr/ssl/certs.

(7)  NOTE: Abe hasn't experienced this, so I can't confirm whether this is
	 still a problem.
	 If you are running Win2K and want to run Netscape on the server
     to access imapd, you could end up with performance problems.  When
     I tried I ended up having to wait up to 30 seconds just to open
     a mailbox!  The problem is that Netscape utilizes 100% of the CPU
     while it is waiting for responses from imapd, and unfortunately the
     way the default process priorities are set up on Win2K, Netscape
     can starve the imapd daemon so it can't get any CPU resources.
     This can be fixed by using nice to invoke Netscape with a lower
     process priority, i.e.:
run nice --adjustment=1 "//D/Program Files/Netscape/Communicator/Program/netscape.exe"
     (You can get the "run.exe" program from the CygUtils web site.)

     Again this should only be a problem if you are running Netscape on
     the same machine that you are running imapd, and this problem was only
     observed on Windows 2000 (Windows NT seemed to work fine).

(8)  Folks wanting to implement a complete mail server are encouraged to
     consider the EXIM "Mail Transfer Agent" (MTA) to handle incoming
     and outgoing SMTP.  For more information see http://www.exim.org.

#     The UW IMAP Server will expect new mail to be delivered to the user's
#     inbox at /var/mail/<username>.
     The UW IMAP Server will expect new mail to be delivered to the user's
     inbox at /var/spool/mail/<username>.

(9)  Abe uses imap as a personal storage because he has experienced the pain
     of machine upgrades and migrations too many times.  Having a single
	 mail store is very nice for these situations.
	 A useful combination to facilitate this is to use fetchmail and pipe
	 messages to imap using the "tmail" utility.  As you gain more experience,
	 you can pipe the messages to procmail, which can be used to sort email
	 into subfolders.
	 Migration from an existing local mailbox in most email clients (I did this
	 with Microsoft Outlook Express) is as simple as drag and drop.

(10) That's it!  Enjoy.




Acknowledgements:
-----------------
     This port to the Cygwin platform is based Adrian Hall's port.
Special thanks to Adrian Hall for his original work.

     Thank you very much to Jim Grishaw and anyone else contributing to the
cygwin port.

     Thank you tremendously to Mark Crispin (the UW IMAP maintainer) for
getting the cygwin code in the main code base.


Revision log, starting with Adrian Hall's port:
-------------------------------------

Aug 24, 2001 (Revision "A0"):
(1)  Fixed various problems with flock():
     (a)  Changed to fcntl_flock() instead of flock() since flock() is
	  not POSIX and does not exist in Cygwin.
     (b)  Made changes to compensate for the different behavior of the
	  Cygwin fcntl_flock() vs the standard UNIX fcntl_flock().
     (c)  Removed flockbsd.c from compilation since Cygwin can't compile it.
(2)  Since setuid() and setgid() do not work with Cygwin (or at least
     they don't work with ntsec turned off), patched calling routines
     so that they would at least return "success" codes.

Jan 12 2002 (Revision "A1"):
(1)  Made changes in env_unix.c so that uid 18 ("SYSTEM" user) is treated
     as "root", and it is no longer necessary to change the "SYSTEM" user
     to uid 0 in the /etc/passwd file.

Apr  8 2002 (Revision "A2"):
(2)  Made changes in tz_cyg.c to fix imapd.exe crashes that were occurring
     at startup on some systems.

July 1 2002 (Revision "A3"):
(1)  Changed CRXTYPE from "nfs" to "std" so that lock files would be
     properly created on FAT file systems.

Present:
Upgraded from 2000 series of uw-imap to 2002.
