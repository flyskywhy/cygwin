if ( $?MANPATH ) then
  setenv MANPATH "${MANPATH}:/usr/ssl/man"
else
  setenv MANPATH ":/usr/ssl/man"
endif
