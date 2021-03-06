# dbg-pre.inc - Bourne Again Shell Debugger Global Variables
#   Copyright (C) 2002, 2003, 2004 Rocky Bernstein
#
#   Bash is free software; you can redistribute it and/or modify it under
#   the terms of the GNU General Public License as published by the Free
#   Software Foundation; either version 2, or (at your option) any later
#   version.
#
#   Bash is distributed in the hope that it will be useful, but WITHOUT ANY
#   WARRANTY; without even the implied warranty of MERCHANTABILITY or
#   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
#   for more details.
#   
#   You should have received a copy of the GNU General Public License along
#   with Bash; see the file COPYING.  If not, write to the Free Software
#   Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA.

# We put definiitions common to both the script debugger and bash
# --debugger. In contrast to other routines this is sourced early --
# before most of the bashdb script is run. The other routines are
# done near the end of the bashdb script. In this way the script can
# has access to definitions that --debugger has without duplicating code.

# Note: the trend now is to move initializations which are generally
# used in only one sub-part (e.g. variables for break/watch/actions) to 
# the corresponding file.

typeset -r _Dbg_release='bash-3.1-0.09'

# This is put at the so we have something at the end to stop at 
# when we debug this. By stopping at the end all of the above functions
# and variables can be tested.
typeset -r _Dbg_pre_ver=\
'$Id: dbg-pre.inc.in,v 1.1.1.1 2006/01/02 23:34:22 rockyb Exp $'

# Expand filename given as $1.
# we echo the expanded name or return $1 unchanged if a bad filename.
# Return is 0 if good or 1 if bad.
# File globbing is handled. 
# Note we don't check that the file exists, just that the format is 
# valid; we do check that we can "search" the directory implied in the 
# filename.

_Dbg_expand_filename() {
  local -r filename="$1"

  # Break out basename and dirname
  local -r basename=${filename##*/}
  local dirname=${filename%/*}

  # No slash given in filename? Then use . for dirname
  [[ $dirname == $basename ]] && dirname="."

  # Dirname is ''? Then use / for dirname
  dirname=${dirname:-/}

  # Handle tilde expansion in dirname
  local glob_cmd="dirname=`expr $dirname`"
  eval $glob_cmd 2>/dev/null

  local long_path;
  long_path=`(cd $dirname && pwd) 2>/dev/null`
  if (( $? == 0 )) ; then
    if [[ $long_path == '/' ]] ; then
      echo "/$basename"
    else
      echo "$long_path/$basename"
    fi
    return 0
  else
    echo $filename
    return 1
  fi
}

#;;; Local Variables: ***
#;;; mode:shell-script ***
#;;; eval: (sh-set-shell "bash") ***
#;;; End: ***
