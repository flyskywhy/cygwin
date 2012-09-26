/* $Id: gg.h,v 1.33 2005/09/19 20:08:50 cegger Exp $
******************************************************************************

   LibGG - API header file

   Copyright (C) 1998-1999 Marcus Sundberg	[marcus@ggi-project.org]

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   THE AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

******************************************************************************
*/

#ifndef _GGI_GG_H
#define _GGI_GG_H

#include <ggi/errors.h>
#include <ggi/system.h>
#include <ggi/gg-defs.h>

#include <stdio.h>	/* needed for FILE structure */


__BEGIN_DECLS
/*
******************************************************************************
 Initialize/Deinitialize library
******************************************************************************
*/

GGAPIFUNC int ggInit(void);

GGAPIFUNC int ggExit(void);

/*
******************************************************************************
 Time functions
******************************************************************************
*/

GGAPIFUNC int ggCurTime(struct timeval *tv);

GGAPIFUNC int ggUSleep(int32_t usecs);

GGAPIFUNC void ggUSlumber(int32_t usecs);

/*
******************************************************************************
 Functions for adding and removing cleanup callbacks
******************************************************************************
*/

typedef void (ggcleanup_func)(void *);

GGAPIFUNC int ggRegisterCleanup(ggcleanup_func *func, void *arg);

GGAPIFUNC int ggUnregisterCleanup(ggcleanup_func *func, void *arg);

/* Try to force _exit() when a handler is triggered */
GGAPIFUNC void ggCleanupForceExit(void);


/*
******************************************************************************
 Functions and structures for using the task scheduler
******************************************************************************
*/

/* Scheduler tick counter wraps at this value */
#define GG_SCHED_TICK_WRAP      32768

#define GG_SCHED_TICKS2USECS(ticks) ((ticks) * ggTimeBase())
#define GG_SCHED_USECS2TICKS(usecs) ((usecs) / ggTimeBase())

struct gg_task;
typedef int (gg_task_callback_fn)(struct gg_task *task);

struct gg_task {
	gg_task_callback_fn	*cb;    /* Function to call to run task	     */
	void			*hook;  /* Task data can be hung here        */
	int                     pticks; /* Run once every pticks ticks.      */
	int                     ncalls; /* Run ncalls times (0 = infinite)   */

/* The rest of this structure is private/internal, do not touch.
 * It should be initialized to all NULL before adding the task.
 */
	void                    *exelock;   /* Prevents reentry              */
	int                     lasttick;   /* # of tick when task last run  */

/* Double-linked, reorderable ring-list of all registered tasks.             */
	struct gg_task          *next;
	struct gg_task          *last;

/* Double-linked ordered linear-list of tasks with expired deadlines         */
	struct gg_task          *nextdl;
	struct gg_task          *lastdl;
};

GGAPIFUNC int ggAddTask(struct gg_task *task);
GGAPIFUNC int ggDelTask(struct gg_task *task);
GGAPIFUNC uint32_t ggTimeBase(void);


/*
******************************************************************************
 Misc functions
******************************************************************************
*/

/* Get the users "home" directory, or whatever the equivalent is under the
   system we are running on. */
GGAPIFUNC const char *ggGetUserDir(void);

/*
******************************************************************************
 Safe string handling functions
******************************************************************************
*/

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
GGAPIFUNC size_t ggstrlcpy(char *dst, const char *src, size_t siz);

/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(src) + MIN(siz, strlen(initial dst)).
 * If retval >= siz, truncation occurred.
 */
GGAPIFUNC size_t ggstrlcat(char *dst, const char *src, size_t siz);

/*
******************************************************************************
 Iterators definitions
******************************************************************************
*/

struct gg_iter;

typedef int  (ggfunc_iter_next)(struct gg_iter *);
typedef void (ggfunc_iter_done)(struct gg_iter *);

struct gg_iter {
	ggfunc_iter_next    *next;
	ggfunc_iter_done    *done;
};

#define ITER_DONE  0 /* end of iteration reached */
#define ITER_YIELD 1 /* got a result             */

#define GG_AS_ITER(i) ((struct gg_iter *)i)
#define GG_ITER_PREPARE(i, n, d) do {                  \
	GG_AS_ITER(i)->next = (ggfunc_iter_next*)n;    \
	GG_AS_ITER(i)->done = (ggfunc_iter_done*)d;    \
} while(0)
#define GG_ITER_FOREACH(i) while(GG_AS_ITER(i)->next(GG_AS_ITER(i)))
#define GG_ITER_DONE(i) if(GG_AS_ITER(i)->done) GG_AS_ITER(i)->done(GG_AS_ITER(i))


/*
******************************************************************************
 Simple observer framework
******************************************************************************
*/

#include <ggi/gg-queue.h>

/*
**  return non zero to delete this observer form the callback.
*/
typedef int (ggfunc_observer_update)(void *arg, int flag, void *data);

struct gg_observer {
	ggfunc_observer_update     *update;
	void                       *arg;
	GG_LIST_ENTRY(gg_observer) _others;
};

struct gg_publisher {
	GG_LIST_HEAD(gg_observer_list,  gg_observer)  observers;
};

#define INIT_PUBLISHER(pub) GG_LIST_INIT(&((pub)->observers))

GGAPIFUNC struct gg_observer * ggAddObserver(struct gg_publisher *,
					     ggfunc_observer_update *, void *);

GGAPIFUNC void ggDelObserver(struct gg_observer *);

GGAPIFUNC void ggNotifyObservers(struct gg_publisher *, int, void *);

GGAPIFUNC void ggClearPublisher(struct gg_publisher *);



/*
******************************************************************************
 Configuration file handling
******************************************************************************
*/

typedef void *gg_config;

GGAPIFUNC int  ggLoadConfig(const char *file, gg_config *conf);

GGAPIFUNC void ggFreeConfig(gg_config);

struct gg_location_iter {
	struct gg_iter       iter;

	/* These must be set by the caller before calling
	 * ggConfigIterLocation
	 */
	gg_config            config;
	const char           *name;

	/* Placeholders for results */
	char                 *location;
	const char           *symbol;

	/* Internal */
	void                 *_state;
};

/* Prepare the given iterator to generate pattern matches */
GGAPIFUNC int ggConfigIterLocation(struct gg_location_iter * iter);

struct gg_target_iter {
	struct gg_iter iter;

	/* These must be set by the caller before calling
	 * ggConfigIterTarget
	 */
	gg_config             config;
	const char            *input;

	/* Placeholders for results */
	char                  *target;
	char                  *options;

	/* Internal */
	void                  *nested;
};

/* Prepare the given iterator to generate target specifications */
GGAPIFUNC int ggConfigIterTarget(struct gg_target_iter *iter);

/******* Legacy interface. DEPRECATED ********/

/* This will return the first found location */
GGAPIFUNC const char *ggMatchConfig(const void *conf, const char *name,
				    const char *version);

/*
 * The function will always fail currently, but the symbol is there
 * to not break builds
 */
GGAPIFUNC int ggConfigExpandAlias(const void *confhandle, const char *list_in,
				  char *list_out, size_t outmax);

/*
******************************************************************************
 Dynamic module and other scope look-up abstraction
******************************************************************************
*/

typedef void *gg_scope;

typedef void *(ggfunc_scope_get)(void *handle, const char *symbol);
typedef void  (ggfunc_scope_del)(void *handle);

/* Get a scope by its location */
GGAPIFUNC gg_scope ggGetScope(const char *location);

/* Call when a scope is not used anymore */
GGAPIFUNC void     ggDelScope(gg_scope scope);

/* Get a symbol from the scope */
GGAPIFUNC void    *ggFromScope(gg_scope scope, const char *symbol);

/* Register a new custom scope */
GGAPIFUNC gg_scope ggNewScope(const char * location, void *handle,
			      ggfunc_scope_get *get,
			      ggfunc_scope_del *del);



typedef int (ggfunc_target_open)(void *, gg_scope, void *,
				 const char *, const char *, void *);

/* This function is a helper that will perform the location and target
 * lookup internally. The caller provides a callback for initializing
 * (whatever it means) the target when a hook function is retreived.
 * it will be given a user specified argument, the scope to which the
 * hook function belong, the hook, the target name, argument string,
 * and the argument pointer if any.
 * If the callback returns non-zero, the call is considered failed,
 * and libgg will take care of releasing the scope.  On success,
 * the scope reference is 'given' to the user, which must keep it
 * somewhere to release it later.
 *
 * If flags is 0, libgg will try to open all targets that can be
 * derived from the target spec and config handle. Otherwise it will
 * stop once the first target is successfuly opened.
 *
 * The function returns the number of target that were successfuly
 * opened.
 */
GGAPIFUNC int ggOpenTarget(const char *targetspec,
			   gg_config conf, const char *defaultsym,
			   ggfunc_target_open *func, void *arg,
			   void *tgtargptr, int flags);

/******* Legacy interface. DEPRECATED ********/

typedef void *gg_module;

#define GG_MODULE_NULL	NULL
#define GG_MODULE_GLOBAL 1

/* Dynamicly load file */
GGAPIFUNC gg_module ggLoadModule(const char *filename, int flags);

/* Try to match name in conf and load the resulting filename */
GGAPIFUNC gg_module ggMLoadModule(const void *conf, const char *name,
				  const char *version, int flags);

/* Get Address of symbol in module */
GGAPIFUNC void *ggGetSymbolAddress(gg_module module, const char *symbol);

/* Unload a module and free resources */
GGAPIFUNC void ggFreeModule(gg_module module);

/*
******************************************************************************
 Parsing functions
******************************************************************************
*/

/* Read the first matching option from an option file into the corresponding
   result entry */
GGAPIFUNC int ggGetFileOpt(FILE *fp, const char **optnames,
			   char **results, int ressize);

GGAPIFUNC const char *ggParseTarget(const char *str, char *target, int max);

#define GG_MAX_OPTION_NAME    32
#define GG_MAX_OPTION_RESULT  256

typedef struct gg_option
{
	char name[GG_MAX_OPTION_NAME];
	char result[GG_MAX_OPTION_RESULT];
} gg_option;

GGAPIFUNC const char *ggParseOptions(const char *str, gg_option *optlist,
				     int count);


/*
******************************************************************************
 Debug output
******************************************************************************
*/

GGAPIFUNC void ggDPrintf(int _sync, const char *subsys,
			 const char *form, ...);

/*
******************************************************************************
 Mutex locking
******************************************************************************
*/

GGAPIFUNC void *ggLockCreate(void);

GGAPIFUNC int ggLockDestroy(void *lock);

GGAPIFUNC void ggLock(void *lock);

GGAPIFUNC void ggUnlock(void *lock);

GGAPIFUNC int ggTryLock(void *lock);

/*
******************************************************************************
 CPU Identification and SIMD disable/enable
******************************************************************************
*/

/* There's a reason not to use enums:
 *
 * All versions of the C standard contain this wording:
 * "The expression that defines the value of an enumeration
 * constant shall be an integer constant expression that has
 * a value representable as an int."
 */

#ifdef GG_HAVE_INT64
typedef uint64_t gg_swartype;
#else
typedef uint32_t gg_swartype;
#endif

#define GG_SWAR_NONE		0x00000001 /* Vanilla C implementation */
#define	GG_SWAR_32BITC		0x00000002 /* Fast 32b math vs 16b */
#define	GG_SWAR_ALTIVEC		0x00000004
#define	GG_SWAR_SSE		0x00000008
#define	GG_SWAR_SSE2		0x00000010
#define	GG_SWAR_MMX		0x00000020
#define	GG_SWAR_MMXPLUS		0x00000040 /* Cyrix. */
#define	GG_SWAR_3DNOW		0x00000080 /* Implies MMX enhancements */
#define	GG_SWAR_ADV3DNOW	0x00000100 /* Implies MMX enhancements */
#define	GG_SWAR_MAX		0x00000200
#define	GG_SWAR_SIGD		0x00000400 /* 32b or 64b?? */
#define	GG_SWAR_SSE3		0x00000800


#ifdef GG_HAVE_INT64

#ifdef _MSC_VER
#define GG_INT64_C(x) x ## i64
#define GG_UINT64_C(x) x ## ui64
#else
#define GG_INT64_C(x) x ## LL
#define GG_UINT64_C(x) x ## ULL
#endif

#define	GG_SWAR_64BITC		GG_INT64_C(0x0000000100000000) /* Fast 64b vs 32b    */
#define	GG_SWAR_MVI		GG_INT64_C(0x0000000200000000) /* avail in 32b mode? */
#define	GG_SWAR_MAX2		GG_INT64_C(0x0000000400000000)
#define	GG_SWAR_MDMX		GG_INT64_C(0x0000000800000000) /* avail in 32b mode? */
#define	GG_SWAR_MAJC		GG_INT64_C(0x0000001000000000)
#define	GG_SWAR_VIS		GG_INT64_C(0x0000002000000000)


#define	GG_SWAR_ALL		GG_INT64_C(0xffffffffffffffff)
#else
#define	GG_SWAR_ALL		0xffffffff

#endif



GGAPIFUNC gg_swartype ggGetSwarType(void);

__END_DECLS

#endif /* _GGI_GG_H */

