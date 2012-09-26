/* GDC -- D front-end for GCC
   Copyright (C) 2004 David Friedman
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
 
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

module std.c.darwin.darwin;

import gcc.configunix;

/+
alias int time_t;
alias long off_t;

enum : int
{
    SIGHUP	= 1,
    SIGINT	= 2,
    SIGQUIT	= 3,
    SIGILL	= 4,
    SIGTRAP	= 5,
    SIGABRT	= 6,
    SIGIOT	= SIGABRT,
    SIGEMT	= 7,
    SIGFPE	= 8,
    SIGKILL	= 9,
    SIGBUS	= 10,
    SIGSEGV	= 11,
    SIGSYS	= 12,
    SIGPIPE	= 13,
    SIGALRM	= 14,
    SIGTERM	= 15,
    SIGURG	= 16,
    SIGSTOP	= 17,
    SIGTSTP	= 18,
    SIGCONT	= 19,
    SIGCHLD	= 20,
    SIGTTIN	= 21,
    SIGTTOU	= 22,
    SIGIO	= 23,
    SIGXCPU	= 24,
    SIGXFSZ	= 25,
    SIGVTALRM = 26,
    SIGPROF	= 27,
    SIGWINCH = 28,
    SIGINFO	= 29,
    SIGUSR1 = 30,
    SIGUSR2 = 31
}

enum
{
    O_RDONLY  = 0x0000,
    O_WRONLY  = 0x0001,
    O_RDWR    = 0x0002,
    O_ACCMODE = 0x0003,
    O_NONBLOCK = 0x0004,
    O_APPEND = 0x0008,
    O_SHLOCK =       0x0010,
    O_EXLOCK =       0x0020,
    O_ASYNC  =       0x0040,
    O_FSYNC  =       0x0080,
    O_NOFOLLOW = 0x0100,
    O_CREAT  =       0x0200,
    O_TRUNC  =       0x0400,
    O_EXCL   =       0x0800
    
}

struct timespec {
        time_t  tv_sec;         /* seconds */
        int     tv_nsec;        /* and nanoseconds */  
};

struct struct_stat {
	int	  st_dev;		/* inode's device */
	uint	  st_ino;		/* inode's number */
	ushort	  st_mode;		/* inode protection mode */
	ushort	  st_nlink;		/* number of hard links */
	uint	  st_uid;		/* user ID of the file's owner */
	uint	  st_gid;		/* group ID of the file's group */
	int	  st_rdev;		/* device type */
	version (None) { // #ifndef _POSIX_SOURCE
	    	timespec st_atimespec;	/* time of last access */
	    	timespec st_mtimespec;	/* time of last data modification */
	    	timespec st_ctimespec;	/* time of last file status change */
	} else {
	    time_t	  st_atime;		/* time of last access */
	    int	 	  st_atimensec;		/* nsec of last access */
	    time_t	  st_mtime;		/* time of last data modification */
	    int		  st_mtimensec;		/* nsec of last data modification */
	    time_t	  st_ctime;		/* time of last file status change */
	    int		  st_ctimensec;		/* nsec of last file status change */
	}
	off_t	  st_size;		/* file size, in bytes */
	long	  st_blocks;		/* blocks allocated for file */
	uint st_blksize;		/* optimal blocksize for I/O */
	uint st_flags;		/* user defined flags for file */
	uint st_gen;		/* file generation number */
	int	  st_lspare;
	long	  st_qspare[2];
};

enum : int
{
    S_IFIFO  = 0010000,
    S_IFCHR  = 0020000,
    S_IFDIR  = 0040000,
    S_IFBLK  = 0060000,
    S_IFREG  = 0100000,
    S_IFLNK  = 0120000,
    S_IFSOCK = 0140000,

    S_IFMT   = 0170000
}

extern (C)
{
    int open(char*, int, ...);
    int read(int, void*, size_t);
    int write(int, void*, size_t);
    int close(int);
    off_t lseek(int, off_t, int);
    int fstat(int, struct_stat*);
    int stat(char*, struct_stat*);
    int getErrno();
    int chdir(char*);
    int mkdir(char*, int);
    int rmdir(char*);
    char* getcwd(char*, int);
}

struct timeval {
	int	tv_sec;		/* seconds */
	int	tv_usec;	/* and microseconds */
};

struct tm {
	int	tm_sec;		/* seconds after the minute [0-60] */
	int	tm_min;		/* minutes after the hour [0-59] */
	int	tm_hour;	/* hours since midnight [0-23] */
	int	tm_mday;	/* day of the month [1-31] */
	int	tm_mon;		/* months since January [0-11] */
	int	tm_year;	/* years since 1900 */
	int	tm_wday;	/* days since Sunday [0-6] */
	int	tm_yday;	/* days since January 1 [0-365] */
	int	tm_isdst;	/* Daylight Savings Time flag */
	int	tm_gmtoff;	/* offset from CUT in seconds */
	char	*tm_zone;	/* timezone abbreviation */
};

extern (C)
{
    int gettimeofday(timeval*, void*);
    time_t time(time_t*);
    tm *localtime(time_t*);
}
+/
