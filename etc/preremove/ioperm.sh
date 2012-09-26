#!/bin/sh
#
# $Id: preremove.sh,v 1.1 2003/01/23 15:16:36 telka Exp $
#

[ -f /usr/bin/ioperm ] && /usr/bin/ioperm -u
