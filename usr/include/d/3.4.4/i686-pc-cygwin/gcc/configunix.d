module gcc.configunix;
private import gcc.config;

alias gcc.config.Coff_t off_t;
extern(C) {

const int NFDBITS = 32;
const int __FD_SET_SIZEOF = 8;
const int FD_SETSIZE = 64;
alias uint mode_t;

enum {
  O_RDONLY = 0,
  O_WRONLY = 1,
  O_RDWR = 2,
  O_NONBLOCK = 16384,
  O_CREAT = 512,
  O_EXCL = 2048,
  O_TRUNC = 1024,
  O_APPEND = 8,
  O_NOFOLLOW = 1048576,
}

enum {
  F_DUPFD = 0,
  F_GETFD = 1,
  F_SETFD = 2,
  F_GETFL = 3,
  F_SETFL = 4,
}

alias int time_t;
struct timespec {
    int tv_sec;
    int tv_nsec;
}

static assert(timespec.tv_sec.offsetof == 0);
static assert(timespec.tv_nsec.offsetof == 4);
static assert(timespec.sizeof == 8);


struct timeval {
    int tv_sec;
    int tv_usec;
}

static assert(timeval.tv_sec.offsetof == 0);
static assert(timeval.tv_usec.offsetof == 4);
static assert(timeval.sizeof == 8);


struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
}

static assert(timezone.tz_minuteswest.offsetof == 0);
static assert(timezone.tz_dsttime.offsetof == 4);
static assert(timezone.sizeof == 8);


struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
}

static assert(tm.tm_sec.offsetof == 0);
static assert(tm.tm_min.offsetof == 4);
static assert(tm.tm_hour.offsetof == 8);
static assert(tm.tm_mday.offsetof == 12);
static assert(tm.tm_mon.offsetof == 16);
static assert(tm.tm_year.offsetof == 20);
static assert(tm.tm_wday.offsetof == 24);
static assert(tm.tm_yday.offsetof == 28);
static assert(tm.tm_isdst.offsetof == 32);
static assert(tm.sizeof == 36);


enum {
  S_IFIFO = 4096,
  S_IFCHR = 8192,
  S_IFDIR = 16384,
  S_IFBLK = 24576,
  S_IFREG = 32768,
  S_IFLNK = 40960,
  S_IFSOCK = 49152,
  S_IFMT = 61440,
  S_IRUSR = 256,
  S_IWUSR = 128,
  S_IXUSR = 64,
  S_IRGRP = 32,
  S_IWGRP = 16,
  S_IXGRP = 8,
  S_IROTH = 4,
  S_IWOTH = 2,
  S_IXOTH = 1,
  S_IRWXG = 56,
  S_IRWXO = 7,
}

struct struct_stat {
    uint st_dev;
   ubyte[4] ___pad1;
    ulong st_ino;
    uint st_mode;
    ushort st_nlink;
   ubyte[2] ___pad2;
    uint st_uid;
    uint st_gid;
    uint st_rdev;
   ubyte[4] ___pad3;
    long st_size;
    int st_atime;
   ubyte[4] ___pad4;
    int st_mtime;
   ubyte[4] ___pad5;
    int st_ctime;
   ubyte[4] ___pad6;
    int st_blksize;
   ubyte[4] ___pad7;
    long st_blocks;
   ubyte[8] ___pad8;
}

static assert(struct_stat.st_dev.offsetof == 0);
static assert(struct_stat.st_ino.offsetof == 8);
static assert(struct_stat.st_mode.offsetof == 16);
static assert(struct_stat.st_nlink.offsetof == 20);
static assert(struct_stat.st_uid.offsetof == 24);
static assert(struct_stat.st_gid.offsetof == 28);
static assert(struct_stat.st_rdev.offsetof == 32);
static assert(struct_stat.st_size.offsetof == 40);
static assert(struct_stat.st_atime.offsetof == 48);
static assert(struct_stat.st_mtime.offsetof == 56);
static assert(struct_stat.st_ctime.offsetof == 64);
static assert(struct_stat.st_blksize.offsetof == 72);
static assert(struct_stat.st_blocks.offsetof == 80);
static assert(struct_stat.sizeof == 96);


// from <sys/signal.h>
enum {
  SIGHUP = 1,
  SIGINT = 2,
  SIGQUIT = 3,
  SIGILL = 4,
  SIGABRT = 6,
  SIGIOT = 0,
  SIGBUS = 10,
  SIGFPE = 8,
  SIGKILL = 9,
  SIGUSR1 = 30,
  SIGUSR2 = 31,
  SIGPIPE = 13,
  SIGALRM = 14,
  SIGTERM = 15,
  SIGSTKFLT = 0,
  SIGCHLD = 20,
  SIGCONT = 19,
  SIGSTOP = 17,
  SIGTSTP = 18,
  SIGTTIN = 21,
  SIGTTOU = 22,
  SIGIO = 23,
  SIGPOLL = 23,
  SIGWINCH = 28,
  SIGURG = 16,
  SIGTRAP = 5,
}
enum {
  SA_NOCLDSTOP = 1,
  SA_NOCLDWAIT = 0,
  SA_SIGINFO = 2,
  SA_ONSTACK = 0,
  SA_RESTART = 268435456,
  SA_NODEFER = 1073741824,
  SA_RESETHAND = -2147483648,
}

struct sigset_t { ubyte[4] opaque; }
alias  void function(int) __sighandler_t;
const __sighandler_t SIG_DFL = cast(__sighandler_t) 0;
const __sighandler_t SIG_IGN = cast(__sighandler_t) 1;
const __sighandler_t SIG_ERR = cast(__sighandler_t) -1;

/* siginfo_t is not finished... see gen_unix.c */
struct siginfo_t {
    int si_signo;
    int si_code;
   ubyte[8] ___pad1;
    int si_errno;
   ubyte[128] ___pad2;
}

static assert(siginfo_t.si_signo.offsetof == 0);
static assert(siginfo_t.si_code.offsetof == 4);
static assert(siginfo_t.si_errno.offsetof == 16);
static assert(siginfo_t.sizeof == 148);


struct sigaction_t {
    union {
        void function(int) sa_handler;
        void function(int, siginfo_t *, void *) sa_sigaction;
    }
    sigset_t sa_mask;
    int sa_flags;
}

static assert(sigaction_t.sa_flags.offsetof == 8);
static assert(sigaction_t.sizeof == 12);


// from <sys/mman.h>
extern(D) const void * MAP_FAILED = cast(void *) -1;
enum { PROT_NONE = 0, PROT_READ = 1, PROT_WRITE = 2, PROT_EXEC = 4 }
enum { MAP_SHARED = 0x1, MAP_PRIVATE = 0x2, MAP_ANON = 0x20,       MAP_ANONYMOUS = 0x20 }
enum { MS_ASYNC = 0x1, MS_SYNC = 0x2, MS_INVALIDATE = 0x4 }

enum {
  EPERM = 1,
  ENOENT = 2,
  ESRCH = 3,
  EINTR = 4,
  ENXIO = 6,
  E2BIG = 7,
  ENOEXEC = 8,
  EBADF = 9,
  ECHILD = 10,
  EINPROGRESS = 119,
  EWOULDBLOCK = 11,
  EAGAIN = 11,
}

struct sem_t { ubyte[4] opaque; }
alias uint pthread_t;
struct pthread_attr_t { ubyte[4] opaque; }
struct pthread_cond_t { ubyte[4] opaque; }
struct pthread_condattr_t { ubyte[4] opaque; }
struct pthread_mutex_t { ubyte[4] opaque; }
struct pthread_mutexattr_t { ubyte[4] opaque; }
alias int socklen_t;
// from <sys/socket.h>
const int SOL_SOCKET = 65535

;enum : int {
  SO_DEBUG = 1,
  SO_ACCEPTCONN = 2,
  SO_REUSEADDR = 4,
  SO_KEEPALIVE = 8,
  SO_DONTROUTE = 16,
  SO_BROADCAST = 32,
  SO_USELOOPBACK = 64,
  SO_LINGER = 128,
  SO_OOBINLINE = 256,
  SO_SNDBUF = 4097,
  SO_RCVBUF = 4098,
  SO_SNDLOWAT = 4099,
  SO_RCVLOWAT = 4100,
  SO_SNDTIMEO = 4101,
  SO_RCVTIMEO = 4102,
  SO_ERROR = 4103,
  SO_TYPE = 4104,
}

struct linger {
    ushort l_onoff;
    ushort l_linger;
}

static assert(linger.l_onoff.offsetof == 0);
static assert(linger.l_linger.offsetof == 2);
static assert(linger.sizeof == 4);



enum : int {
  SOCK_STREAM = 1,
  SOCK_DGRAM = 2,
  SOCK_RAW = 3,
  SOCK_RDM = 4,
  SOCK_SEQPACKET = 5,
}

enum : int {
  MSG_OOB = 1,
  MSG_PEEK = 2,
  MSG_DONTROUTE = 4,
}

enum : int {
  AF_UNSPEC = 0,
  AF_UNIX = 1,
  AF_INET = 2,
  AF_IPX = 0,
  AF_APPLETALK = 16,
  AF_INET6 = 0,
  AF_BOGOSITY = 0,
}

enum : int {
  PF_UNSPEC = 0,
  PF_UNIX = 1,
  PF_INET = 2,
  PF_IPX = 0,
  PF_APPLETALK = 16,
}

// from <netinet/in.h>
enum : int {
  IPPROTO_IP = 0,
  IPPROTO_ICMP = 1,
  IPPROTO_IGMP = 2,
  IPPROTO_GGP = -1,
  IPPROTO_TCP = 6,
  IPPROTO_PUP = 12,
  IPPROTO_UDP = 17,
  IPPROTO_IDP = 22,
  IPPROTO_IPV6 = -1,
}

enum : uint {
  INADDR_ANY = 0x0,
  INADDR_LOOPBACK = 0x7f000001,
  INADDR_BROADCAST = 0xffffffff,
  INADDR_NONE = 0xffffffff,
  ADDR_ANY = 0,
}
// from <netinet/tcp.h>
enum : int {
  TCP_NODELAY = 1,
}

// from <netinet6/in6.h>
enum : int {
  IPV6_UNICAST_HOPS = -1,
  IPV6_MULTICAST_IF = -1,
  IPV6_MULTICAST_HOPS = -1,
  IPV6_MULTICAST_LOOP = -1,
  IPV6_JOIN_GROUP = -1,
  IPV6_LEAVE_GROUP = -1,
}

// from <netdb.h>
struct protoent {
    char * p_name;
    char ** p_aliases;
    short p_proto;
   ubyte[2] ___pad1;
}

static assert(protoent.p_proto.offsetof == 8);
static assert(protoent.sizeof == 12);


struct servent {
    char * s_name;
    char ** s_aliases;
    short s_port;
   ubyte[2] ___pad1;
    char * s_proto;
}

static assert(servent.s_port.offsetof == 8);
static assert(servent.sizeof == 16);


struct hostent {
    char * h_name;
    char ** h_aliases;
    short h_addrtype;
    short h_length;
    char ** h_addr_list;
char* h_addr()
{
	return h_addr_list[0];
}
}

static assert(hostent.h_addrtype.offsetof == 8);
static assert(hostent.h_length.offsetof == 10);
static assert(hostent.sizeof == 16);


struct addrinfo { }
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
    int	lstat(char *, struct_stat *);
    int	chmod(char *, mode_t);
    int chdir(char*);
    int mkdir(char*, int);
    int rmdir(char*);
    char* getcwd(char*, int);

    int gettimeofday(timeval*, void*);
    time_t time(time_t*);
    tm *localtime(time_t*);

    // version( Unix_Posix_Sempahore ) ?
    int sem_init (sem_t *, int, uint);
    int sem_destroy (sem_t *);
    sem_t * sem_open (char *, int, ...);
    int sem_close(sem_t *);
    int sem_wait(sem_t*);
    int sem_post(sem_t*);
    // there are a few more..

    int sigfillset(sigset_t*);
    int sigdelset(sigset_t*, int);
    int sigaction(int, sigaction_t*, sigaction_t*);
    int sigsuspend(sigset_t*);
    
    // version ( Unix_Pthread )...
    int pthread_create(pthread_t*, void*, void* (*)(void*), void*);
    int pthread_join(pthread_t, void**);
    int pthread_kill(pthread_t, int);
    pthread_t pthread_self();
    int pthread_equal(pthread_t, pthread_t);
    int pthread_suspend_np(pthread_t);
    int pthread_continue_np(pthread_t);

    int pthread_cond_init(pthread_cond_t *, pthread_condattr_t *);
    int pthread_cond_destroy(pthread_cond_t *);
    int pthread_cond_signal(pthread_cond_t *);
    int pthread_cond_broadcast(pthread_cond_t *);
    int pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *);
    int pthread_cond_timedwait(pthread_cond_t *, pthread_mutex_t *, timespec *);
    int pthread_condattr_init(pthread_condattr_t *);
    int pthread_condattr_destroy(pthread_condattr_t *);
    int pthread_condattr_getpshared(pthread_condattr_t *, int *);
    int pthread_condattr_setpshared(pthread_condattr_t *, int);

    int pthread_mutex_init(pthread_mutex_t *, pthread_mutexattr_t *);
    int pthread_mutex_lock(pthread_mutex_t *);
    int pthread_mutex_trylock(pthread_mutex_t *);
    int pthread_mutex_unlock(pthread_mutex_t *);
    int pthread_mutex_destroy(pthread_mutex_t *);
    int pthread_mutexattr_init(pthread_mutexattr_t *);
    int pthread_mutexattr_destroy(pthread_mutexattr_t *);
    int pthread_mutexattr_getpshared(pthread_mutexattr_t *, int *);
    int pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);

    // version ( Unix_Sched )
    void sched_yield();

    // from <sys/mman.h>
    void* mmap(void* addr, size_t len, int prot, int flags, int fd, off_t offset);
    int munmap(void* addr, size_t len);
    int msync(void* start, size_t length, int flags);

    // from <fcntl.h>
    int fcntl(int fd, int cmd, int arg);

    int select(int n, fd_set *, fd_set *, fd_set *, timeval *);

    // could probably rewrite fd_set stuff in D, but for now...
    struct fd_set {
	ubyte opaque[__FD_SET_SIZEOF];
    }
    private void _d_gnu_fd_set(int n, fd_set * p);
    private void _d_gnu_fd_clr(int n, fd_set * p);
    private int  _d_gnu_fd_isset(int n, fd_set * p);
    private void _d_gnu_fd_copy(fd_set * f, fd_set * t);
    private void _d_gnu_fd_zero(fd_set * p);
    // maybe these should go away in favor of fd_set methods
    version (none)
    {
	void FD_SET(int n, inout fd_set p) { return _d_gnu_fd_set(n, & p); }
	void FD_CLR(int n, inout fd_set p) { return _d_gnu_fd_clr(n, & p); }
	int FD_ISSET(int n, inout fd_set p) { return _d_gnu_fd_isset(n, & p); }
	void FD_COPY(inout fd_set f, inout fd_set t) { return _d_gnu_fd_copy(& f, & t); }
	void FD_ZERO(inout fd_set p) { return _d_gnu_fd_zero(& p); }
    }
    void FD_SET(int n,  fd_set * p) { return _d_gnu_fd_set(n, p); }
    void FD_CLR(int n,  fd_set * p) { return _d_gnu_fd_clr(n, p); }
    int FD_ISSET(int n, fd_set * p) { return _d_gnu_fd_isset(n, p); }
    void FD_COPY(fd_set * f, inout fd_set * t) { return _d_gnu_fd_copy(f, t); }
    void FD_ZERO(fd_set * p) { return _d_gnu_fd_zero(p); }

    // The following is mostly based on std/c/linux/socket.d    

    // There doesn't seem to be a need to configure these structs beyond
    // the BsdSockets_salen bit.
    struct in_addr
    {
	uint s_addr;
    }

    struct sockaddr
    {
	version(GNU_BsdSockets_salen) {
	    ubyte  sa_len;
	    ubyte  sa_family;
	} else {
	    ushort sa_family;               
	}
	char[14] sa_data = [0];             
    }

    struct sockaddr_in
    {
	version( BsdSockets_salen ) {
	    ubyte sin_len = sockaddr_in.sizeof;
	    ubyte sin_family = AF_INET;
	} else {
	    ushort sin_family = AF_INET;
	}
	ushort sin_port;
	in_addr sin_addr;
	char[8] sin_zero = [0];
    }

    // std/socket.d
    enum: int
    {
	SD_RECEIVE =  0,
	SD_SEND =     1,
	SD_BOTH =     2,
    }

    int socket(int af, int type, int protocol);
    int bind(int s, sockaddr* name, int namelen);
    int connect(int s, sockaddr* name, int namelen);
    int listen(int s, int backlog);
    int accept(int s, sockaddr* addr, int* addrlen);
    int shutdown(int s, int how);
    int getpeername(int s, sockaddr* name, int* namelen);
    int getsockname(int s, sockaddr* name, int* namelen);
    int send(int s, void* buf, int len, int flags);
    int sendto(int s, void* buf, int len, int flags, sockaddr* to, int tolen);
    int recv(int s, void* buf, int len, int flags);
    int recvfrom(int s, void* buf, int len, int flags, sockaddr* from, int* fromlen);
    int getsockopt(int s, int level, int optname, void* optval, int* optlen);
    int setsockopt(int s, int level, int optname, void* optval, int optlen);
    uint inet_addr(char* cp);
    char* inet_ntoa(in_addr ina);
    hostent* gethostbyname(char* name);
    hostent* gethostbyaddr(void* addr, int len, int type);
    protoent* getprotobyname(char* name);
    protoent* getprotobynumber(int number);
    servent* getservbyname(char* name, char* proto);
    servent* getservbyport(int port, char* proto);
    int gethostname(char* name, int namelen);
    int getaddrinfo(char* nodename, char* servname, addrinfo* hints, addrinfo** res);
    void freeaddrinfo(addrinfo* ai);
    int getnameinfo(sockaddr* sa, socklen_t salen, char* node, socklen_t nodelen, char* service, socklen_t servicelen, int flags);

    private import std.stdint;

    version(BigEndian)
    {
	    uint16_t htons(uint16_t x)
	    {
		    return x;
	    }


	    uint32_t htonl(uint32_t x)
	    {
		    return x;
	    }
    }
    else version(LittleEndian)
    {
	    private import std.intrinsic;


	    uint16_t htons(uint16_t x)
	    {
		    return (x >> 8) | (x << 8);
	    }


	    uint32_t htonl(uint32_t x)
	    {
		    return bswap(x);
	    }
    }
    else
    {
	    static assert(0);
    }

    alias htons ntohs;
    alias htonl ntohl;
}
