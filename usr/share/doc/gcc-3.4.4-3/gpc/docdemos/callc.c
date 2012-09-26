/* GPC demo program. For copying conditions see the file `COPYING.DEMO'. */

#include <unistd.h>
#include "callc.h"

int foo = 1;

void bar (void)
{
  sleep (foo);
}
