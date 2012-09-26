#!/bin/bash

SYSCONFDIR=/etc
DEFAULTSDIR=/etc/defaults

remove_default() {
  local fn
  if [ -n "$1" ]
  then
    fn=$1
  else
    return
  fi

  if [ -f "${DEFAULTSDIR}/$fn" -a -f "$fn" ]
  then
    if cmp -s "${DEFAULTSDIR}/$fn" "$fn"
    then
      rm -f "$fn"
    fi
  fi
}

remove_default "${SYSCONFDIR}/hosts.allow"
remove_default "${SYSCONFDIR}/hosts.deny"

