# The script name starts with 00 to ensure that it is executed before any 
# other scripts because one of them may need to know where X is to run
# properly.

# Check if the PATH variable is empty or not
if test -n "${PATH}"; then
  # PATH is not empty

  # Check if path is already in PATH
  if ! /bin/echo ${PATH} | /bin/grep -q /usr/X11R6/bin ; then
    # Path is not already in PATH, prepend it to PATH
    export PATH="/usr/X11R6/bin:${PATH}"
  fi
else
  # PATH is empty
  export PATH="/usr/X11R6/bin"
fi
