#ifndef ORBITUTIL_COMPAT_H
#define ORBITUTIL_COMPAT_H 1
#include <sys/types.h>
#include <sys/uio.h>

int g_writev(int fd, const struct  iovec *  vector,  size_t count);

#endif /*#define ORBITUTIL_COMPAT_H 1 */
