{ rts-config.inc.  Generated automatically from rts-config.h.  }
{ rts-config.h.  Generated automatically by configure.  }
{ rts-config.in.  Generated automatically from configure.in by autoheader 2.13.  }

{ Define if you have <sys/wait.h> that is POSIX.1 compatible.  }
{ #undef HAVE_SYS_WAIT_H }

{ Define if you don't have tm_zone but do have the external array
   tzname.  }
{ #undef HAVE_TZNAME }

{ Define if you have the ANSI C header files.  }
{$define STDC_HEADERS 1}

{ Define if `sys_siglist' is declared by <signal.h>.  }
{ #undef SYS_SIGLIST_DECLARED }

{ Define if you can safely include both <sys/time.h> and <time.h>.  }
{$define TIME_WITH_SYS_TIME 1}

{ Define if struct passwd in <pwd.h> contains a pw_gecos field.  }
{ #undef HAVE_PW_GECOS }

{ Define if struct passwd in <pwd.h> contains a pw_passwd field.  }
{ #undef HAVE_PW_PASSWD }

{ Define if struct utsname in <sys/utsname.h> contains a domainname field.  }
{ #undef HAVE_DOMAINNAME }

{ Define if struct tm in <time.h> contains a tm_isdst field.  }
{$define HAVE_TM_ISDST 1}

{ Define if struct tm in <time.h> contains a tm_gmtoff field.  }
{ #undef HAVE_TM_GMTOFF }

{ Define if type ssize_t is declared in <stdlib.h> or <sys/types.h>.  }
{$define HAVE_SSIZE_T 1}

{ Define if type off_t is declared in <stdlib.h> or <sys/types.h>.  }
{$define HAVE_OFF_T 1}

{ Define if type off64_t is declared in <stdlib.h> or <sys/types.h>.  }
{ #undef HAVE_OFF64_T }

{ Define if type __off64_t is declared in <stdlib.h> or <sys/types.h>.  }
{ #undef HAVE___OFF64_T }

{ Define if type loff_t is declared in <stdlib.h> or <sys/types.h>.  }
{ #undef HAVE_LOFF_T }

{ Define if type offset_t is declared in <stdlib.h> or <sys/types.h>.  }
{ #undef HAVE_OFFSET_T }

{ Define if type struct stat64 is declared in <sys/stat.h>.  }
{ #undef HAVE_STRUCT_STAT64 }

{ Define if you have an errno variable.  }
{ #undef HAVE_ERRNO }

{ Define if you have an environ variable.  }
{ #undef HAVE_ENVIRON }

{ Define if you have an __environ variable.  }
{ #undef HAVE___ENVIRON }

{ Define if you have a sys_siglist variable.  }
{ #undef HAVE_SYS_SIGLIST }

{ Define if you have a _sys_siglist variable.  }
{ #undef HAVE__SYS_SIGLIST }

{ Define if you have a _sys_nsig variable.  }
{ #undef HAVE__SYS_NSIG }

{ Define if you have a tzname variable.  }
{ #undef HAVE_TZNAME }

{ Define if you have a timezone variable.  }
{ #undef HAVE_TIMEZONE }

{ Define if you have a _timezone variable.  }
{ #undef HAVE__TIMEZONE }

{ Define if mkdir accepts two arguments.  }
{ #undef MKDIR_TWOARG }

{ Define if getpgrp takes an argument.  }
{$define GETPGRP_ARG 1}

{ Define if the errno variable is declared in <errno.h>.  }
{$define ERRNO_DECLARED 1}

{ Define if the environ variable is declared in <unistd.h>.  }
{ #undef ENVIRON_DECLARED }

{ Define if the __environ variable is declared in <unistd.h>.  }
{ #undef __ENVIRON_DECLARED }

{ Define if the _sys_siglist variable is declared in <signal.h> or <unistd.h>.  }
{ #undef _SYS_SIGLIST_DECLARED }

{ Define if the _sys_nsig variable is declared in <signal.h>.  }
{ #undef _SYS_NSIG_DECLARED }

{ Define if the tzname variable is declared in <time.h>.  }
{$define TZNAME_DECLARED 1}

{ Define if the timezone variable is declared in <time.h>.  }
{$define TIMEZONE_DECLARED 1}

{ Define if the _timezone variable is declared in <time.h>.  }
{$define _TIMEZONE_DECLARED 1}

{ Define if the sinl function is declared in <math.h>.  }
{$define SINL_DECLARED 1}

{ Define if the cosl function is declared in <math.h>.  }
{$define COSL_DECLARED 1}

{ Define if the sqrtl function is declared in <math.h>.  }
{$define SQRTL_DECLARED 1}

{ Define if the logl function is declared in <math.h>.  }
{$define LOGL_DECLARED 1}

{ Define if the expl function is declared in <math.h>.  }
{$define EXPL_DECLARED 1}

{ Define if the powl function is declared in <math.h>.  }
{$define POWL_DECLARED 1}

{ Define if the asinl function is declared in <math.h>.  }
{$define ASINL_DECLARED 1}

{ Define if the acosl function is declared in <math.h>.  }
{$define ACOSL_DECLARED 1}

{ Define if the atanl function is declared in <math.h>.  }
{$define ATANL_DECLARED 1}

{ Define if the frexpl function is declared in <math.h>.  }
{$define FREXPL_DECLARED 1}

{ Define if the isinfl function is declared in <math.h>.  }
{ #undef ISINFL_DECLARED }

{ Define if the isnanl function is declared in <math.h>.  }
{ #undef ISNANL_DECLARED }

{ Define if the sleep function is declared in <unistd.h>.  }
{ #undef SLEEP_DECLARED }

{ Define if the llseek function is declared in <unistd.h>.  }
{ #undef LLSEEK_DECLARED }

{ Define if the usleep function is declared in <unistd.h>.  }
{ #undef USLEEP_DECLARED }

{ Define if the setenv function is declared in <stdlib.h>.  }
{ #undef SETENV_DECLARED }

{ Define if the setregid function is declared in <unistd.h>.  }
{ #undef SETREGID_DECLARED }

{ Define if the setreuid function is declared in <unistd.h>.  }
{ #undef SETREUID_DECLARED }

{ Define if the unsetenv function is declared in <stdlib.h>.  }
{ #undef UNSETENV_DECLARED }

{ Define if the fstat64 function is declared in <sys/stat.h>.  }
{ #undef FSTAT64_DECLARED }

{ Define if the ftruncate64 function is declared in <unistd.h>.  }
{ #undef FTRUNCATE64_DECLARED }

{ Define if the lseek64 function is declared in <unistd.h>.  }
{ #undef LSEEK64_DECLARED }

{ Define if the lstat64 function is declared in <sys/stat.h>.  }
{ #undef LSTAT64_DECLARED }

{ Define if the open64 function is declared in <fcntl.h>.  }
{ #undef OPEN64_DECLARED }

{ Define if the stat64 function is declared in <sys/stat.h>.  }
{ #undef STAT64_DECLARED }

{ Define if the strsignal function is declared in <string.h> or <signal.h>.  }
{ #undef STRSIGNAL_DECLARED }

{ Define if __builtin_return_address supports a non-zero argument.  }
{$define HAVE_RETURN_ADDRESS_NON_ZERO 1}

{ Define if you have the _sleep function.  }
{$define HAVE__SLEEP 1}

{ Define if you have the abort function.  }
{$define HAVE_ABORT 1}

{ Define if you have the acosl function.  }
{$define HAVE_ACOSL 1}

{ Define if you have the alarm function.  }
{ #undef HAVE_ALARM }

{ Define if you have the asinl function.  }
{$define HAVE_ASINL 1}

{ Define if you have the atanl function.  }
{$define HAVE_ATANL 1}

{ Define if you have the chdir function.  }
{$define HAVE_CHDIR 1}

{ Define if you have the chmod function.  }
{$define HAVE_CHMOD 1}

{ Define if you have the chown function.  }
{ #undef HAVE_CHOWN }

{ Define if you have the cosl function.  }
{$define HAVE_COSL 1}

{ Define if you have the dup2 function.  }
{$define HAVE_DUP2 1}

{ Define if you have the endpwent function.  }
{ #undef HAVE_ENDPWENT }

{ Define if you have the executable_path function.  }
{ #undef HAVE_EXECUTABLE_PATH }

{ Define if you have the expl function.  }
{$define HAVE_EXPL 1}

{ Define if you have the fcntl function.  }
{ #undef HAVE_FCNTL }

{ Define if you have the fnmatch function.  }
{ #undef HAVE_FNMATCH }

{ Define if you have the frexpl function.  }
{$define HAVE_FREXPL 1}

{ Define if you have the fstat function.  }
{$define HAVE_FSTAT 1}

{ Define if you have the fstat64 function.  }
{ #undef HAVE_FSTAT64 }

{ Define if you have the fsync function.  }
{ #undef HAVE_FSYNC }

{ Define if you have the ftruncate function.  }
{ #undef HAVE_FTRUNCATE }

{ Define if you have the ftruncate64 function.  }
{ #undef HAVE_FTRUNCATE64 }

{ Define if you have the getegid function.  }
{ #undef HAVE_GETEGID }

{ Define if you have the getenv function.  }
{$define HAVE_GETENV 1}

{ Define if you have the geteuid function.  }
{ #undef HAVE_GETEUID }

{ Define if you have the getgid function.  }
{ #undef HAVE_GETGID }

{ Define if you have the getpgid function.  }
{ #undef HAVE_GETPGID }

{ Define if you have the getpgrp function.  }
{ #undef HAVE_GETPGRP }

{ Define if you have the getpid function.  }
{$define HAVE_GETPID 1}

{ Define if you have the getpwent function.  }
{ #undef HAVE_GETPWENT }

{ Define if you have the getpwnam function.  }
{ #undef HAVE_GETPWNAM }

{ Define if you have the getpwuid function.  }
{ #undef HAVE_GETPWUID }

{ Define if you have the getrusage function.  }
{ #undef HAVE_GETRUSAGE }

{ Define if you have the gettimeofday function.  }
{ #undef HAVE_GETTIMEOFDAY }

{ Define if you have the gettmpdir function.  }
{ #undef HAVE_GETTMPDIR }

{ Define if you have the getuid function.  }
{ #undef HAVE_GETUID }

{ Define if you have the glob function.  }
{ #undef HAVE_GLOB }

{ Define if you have the hypot function.  }
{$define HAVE_HYPOT 1}

{ Define if you have the isatty function.  }
{$define HAVE_ISATTY 1}

{ Define if you have the isinfl function.  }
{ #undef HAVE_ISINFL }

{ Define if you have the isnanl function.  }
{$define HAVE_ISNANL 1}

{ Define if you have the kill function.  }
{ #undef HAVE_KILL }

{ Define if you have the llseek function.  }
{ #undef HAVE_LLSEEK }

{ Define if you have the log1p function.  }
{$define HAVE_LOG1P 1}

{ Define if you have the logl function.  }
{$define HAVE_LOGL 1}

{ Define if you have the lseek function.  }
{$define HAVE_LSEEK 1}

{ Define if you have the lseek64 function.  }
{ #undef HAVE_LSEEK64 }

{ Define if you have the lstat function.  }
{ #undef HAVE_LSTAT }

{ Define if you have the lstat64 function.  }
{ #undef HAVE_LSTAT64 }

{ Define if you have the malloc_init function.  }
{ #undef HAVE_MALLOC_INIT }

{ Define if you have the mkdir function.  }
{$define HAVE_MKDIR 1}

{ Define if you have the mmap function.  }
{ #undef HAVE_MMAP }

{ Define if you have the munmap function.  }
{ #undef HAVE_MUNMAP }

{ Define if you have the open64 function.  }
{ #undef HAVE_OPEN64 }

{ Define if you have the powl function.  }
{$define HAVE_POWL 1}

{ Define if you have the putenv function.  }
{$define HAVE_PUTENV 1}

{ Define if you have the readlink function.  }
{ #undef HAVE_READLINK }

{ Define if you have the realpath function.  }
{ #undef HAVE_REALPATH }

{ Define if you have the rename function.  }
{$define HAVE_RENAME 1}

{ Define if you have the rmdir function.  }
{$define HAVE_RMDIR 1}

{ Define if you have the select function.  }
{ #undef HAVE_SELECT }

{ Define if you have the setenv function.  }
{ #undef HAVE_SETENV }

{ Define if you have the setgid function.  }
{ #undef HAVE_SETGID }

{ Define if you have the setlocale function.  }
{$define HAVE_SETLOCALE 1}

{ Define if you have the setpgid function.  }
{ #undef HAVE_SETPGID }

{ Define if you have the setpwent function.  }
{ #undef HAVE_SETPWENT }

{ Define if you have the setregid function.  }
{ #undef HAVE_SETREGID }

{ Define if you have the setreuid function.  }
{ #undef HAVE_SETREUID }

{ Define if you have the setuid function.  }
{ #undef HAVE_SETUID }

{ Define if you have the sigaction function.  }
{ #undef HAVE_SIGACTION }

{ Define if you have the sigblock function.  }
{ #undef HAVE_SIGBLOCK }

{ Define if you have the siginterrupt function.  }
{ #undef HAVE_SIGINTERRUPT }

{ Define if you have the signal function.  }
{$define HAVE_SIGNAL 1}

{ Define if you have the sigprocmask function.  }
{ #undef HAVE_SIGPROCMASK }

{ Define if you have the sigsetmask function.  }
{ #undef HAVE_SIGSETMASK }

{ Define if you have the sigvec function.  }
{ #undef HAVE_SIGVEC }

{ Define if you have the sinl function.  }
{$define HAVE_SINL 1}

{ Define if you have the sleep function.  }
{$define HAVE_SLEEP 1}

{ Define if you have the sqrtl function.  }
{$define HAVE_SQRTL 1}

{ Define if you have the stat function.  }
{$define HAVE_STAT 1}

{ Define if you have the stat64 function.  }
{ #undef HAVE_STAT64 }

{ Define if you have the statfs function.  }
{ #undef HAVE_STATFS }

{ Define if you have the statvfs function.  }
{ #undef HAVE_STATVFS }

{ Define if you have the strerror function.  }
{$define HAVE_STRERROR 1}

{ Define if you have the strftime function.  }
{$define HAVE_STRFTIME 1}

{ Define if you have the strsignal function.  }
{ #undef HAVE_STRSIGNAL }

{ Define if you have the tcgetattr function.  }
{ #undef HAVE_TCGETATTR }

{ Define if you have the tcgetpgrp function.  }
{ #undef HAVE_TCGETPGRP }

{ Define if you have the tcsetattr function.  }
{ #undef HAVE_TCSETATTR }

{ Define if you have the tcsetpgrp function.  }
{ #undef HAVE_TCSETPGRP }

{ Define if you have the time function.  }
{$define HAVE_TIME 1}

{ Define if you have the ttyname function.  }
{ #undef HAVE_TTYNAME }

{ Define if you have the umask function.  }
{$define HAVE_UMASK 1}

{ Define if you have the uname function.  }
{ #undef HAVE_UNAME }

{ Define if you have the unlink function.  }
{$define HAVE_UNLINK 1}

{ Define if you have the unsetenv function.  }
{ #undef HAVE_UNSETENV }

{ Define if you have the usleep function.  }
{ #undef HAVE_USLEEP }

{ Define if you have the utime function.  }
{$define HAVE_UTIME 1}

{ Define if you have the vfork function.  }
{ #undef HAVE_VFORK }

{ Define if you have the waitpid function.  }
{ #undef HAVE_WAITPID }

{ Define if you have the <bsd/signal.h> header file.  }
{ #undef HAVE_BSD_SIGNAL_H }

{ Define if you have the <ctype.h> header file.  }
{$define HAVE_CTYPE_H 1}

{ Define if you have the <dirent.h> header file.  }
{$define HAVE_DIRENT_H 1}

{ Define if you have the <errno.h> header file.  }
{$define HAVE_ERRNO_H 1}

{ Define if you have the <fcntl.h> header file.  }
{$define HAVE_FCNTL_H 1}

{ Define if you have the <fnmatch.h> header file.  }
{$define HAVE_FNMATCH_H 1}

{ Define if you have the <glob.h> header file.  }
{ #undef HAVE_GLOB_H }

{ Define if you have the <limits.h> header file.  }
{$define HAVE_LIMITS_H 1}

{ Define if you have the <locale.h> header file.  }
{$define HAVE_LOCALE_H 1}

{ Define if you have the <math.h> header file.  }
{$define HAVE_MATH_H 1}

{ Define if you have the <ndir.h> header file.  }
{ #undef HAVE_NDIR_H }

{ Define if you have the <os-hacks.h> header file.  }
{$define HAVE_OS_HACKS_H 1}

{ Define if you have the <process.h> header file.  }
{$define HAVE_PROCESS_H 1}

{ Define if you have the <pwd.h> header file.  }
{ #undef HAVE_PWD_H }

{ Define if you have the <signal.h> header file.  }
{$define HAVE_SIGNAL_H 1}

{ Define if you have the <stdio.h> header file.  }
{$define HAVE_STDIO_H 1}

{ Define if you have the <sys/dir.h> header file.  }
{ #undef HAVE_SYS_DIR_H }

{ Define if you have the <sys/file.h> header file.  }
{$define HAVE_SYS_FILE_H 1}

{ Define if you have the <sys/mman.h> header file.  }
{ #undef HAVE_SYS_MMAN_H }

{ Define if you have the <sys/mount.h> header file.  }
{ #undef HAVE_SYS_MOUNT_H }

{ Define if you have the <sys/ndir.h> header file.  }
{ #undef HAVE_SYS_NDIR_H }

{ Define if you have the <sys/param.h> header file.  }
{$define HAVE_SYS_PARAM_H 1}

{ Define if you have the <sys/resource.h> header file.  }
{ #undef HAVE_SYS_RESOURCE_H }

{ Define if you have the <sys/select.h> header file.  }
{ #undef HAVE_SYS_SELECT_H }

{ Define if you have the <sys/stat.h> header file.  }
{$define HAVE_SYS_STAT_H 1}

{ Define if you have the <sys/statvfs.h> header file.  }
{ #undef HAVE_SYS_STATVFS_H }

{ Define if you have the <sys/time.h> header file.  }
{$define HAVE_SYS_TIME_H 1}

{ Define if you have the <sys/types.h> header file.  }
{$define HAVE_SYS_TYPES_H 1}

{ Define if you have the <sys/utime.h> header file.  }
{$define HAVE_SYS_UTIME_H 1}

{ Define if you have the <sys/utsname.h> header file.  }
{ #undef HAVE_SYS_UTSNAME_H }

{ Define if you have the <sys/vfs.h> header file.  }
{ #undef HAVE_SYS_VFS_H }

{ Define if you have the <termio.h> header file.  }
{ #undef HAVE_TERMIO_H }

{ Define if you have the <termios.h> header file.  }
{ #undef HAVE_TERMIOS_H }

{ Define if you have the <unistd.h> header file.  }
{$define HAVE_UNISTD_H 1}

{ Define if you have the <utime.h> header file.  }
{$define HAVE_UTIME_H 1}

{ Define if you have the iconv library (-liconv).  }
{$define HAVE_LIBICONV 1}

{ Define if you have the intl library (-lintl).  }
{$define HAVE_LIBINTL 1}

{ Define if you have the m library (-lm).  }
{$define HAVE_LIBM 1}

{ Define if you have the os-hacks library (-los-hacks).  }
{ #undef HAVE_LIBOS_HACKS }
