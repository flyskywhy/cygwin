set LA_PREFIX=/usr
set LA_LIBDIR=${LA_PREFIX}/lib
set LA_BINDIR=${LA_LIBDIR}/lapack

# Check if the PATH variable is empty or not


if ( $?PATH ) then
  # PATH is not empty

  # Check if path is already in PATH
  eval "/bin/echo ${PATH} | /bin/grep -q ${LA_BINDIR}"
  if ( $status ) then
    # Path is not already in PATH, append it to PATH
    setenv PATH "${PATH}:${LA_BINDIR}"
  endif
else
  # PATH is empty
  setenv PATH "${LA_BINDIR}"
endif

unset LA_PREFIX
unset LA_LIBDIR
unset LA_BINDIR
