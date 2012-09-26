# The script name starts with 00 to ensure that it is executed before any
# other scripts because one of them may need to know where X is to run
# properly.

# Check if the PATH variable is empty or not
if ( $?PATH ) then
  # PATH is not empty

  # Check if path is already in PATH
  eval "/bin/echo ${PATH} | /bin/grep -q /usr/X11R6/bin"
  if ( $status ) then
    # Path is not already in PATH, prepend it to PATH
    setenv PATH "/usr/X11R6/bin:${PATH}"
  endif
else
  # PATH is empty
  setenv PATH "/usr/X11R6/bin"
endif
