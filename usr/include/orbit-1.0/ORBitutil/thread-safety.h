#ifndef THREAD_SAFETY_H
#define THREAD_SAFETY_H 1

#ifdef NOT_REENTRANT

#include <pthread.h>

#define DEFINE_LOCK(x) pthread_mutex_t x##_lock = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#define INIT_LOCK(x) /* We use static initialization, see above */
#define GET_LOCK(x) pthread_mutex_lock(&x##_lock)
#define RELEASE_LOCK(x) pthread_mutex_unlock(&x##_lock)
#define PARAM_LOCK(x) pthread_mutex_t x##_lock
#define LOCK_NAME(x) x##_lock
#define EXTERN_LOCK(x) extern pthread_mutex_t x##_lock
extern pthread_key_t thread_data;
#define GET_THREAD_DATA() pthread_getspecific(thread_data)
#define SET_THREAD_DATA(x) pthread_setspecific(thread_data, (x))

#else

/* stupid work around ANSI & empty semicolons. */
#define DEFINE_LOCK(x)
#define INIT_LOCK(x)
#define GET_LOCK(x)
#define RELEASE_LOCK(x)
#define PARAM_LOCK(x) gpointer x##_lock
#define LOCK_NAME(x) NULL
#define EXTERN_LOCK(x)

extern gpointer prog_data;
#define GET_THREAD_DATA() prog_data
#define SET_THREAD_DATA(x) (prog_data = (x))

#endif

#endif /* THREAD_SAFETY_H */
