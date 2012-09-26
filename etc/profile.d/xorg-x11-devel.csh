# Check if the PKG_CONFIG_PATH variable is empty or not
if ( $?PKG_CONFIG_PATH ) then
  # PKG_CONFIG_PATH is not empty

  # Check if path is already in PKG_CONFIG_PATH
  eval "/bin/echo ${PKG_CONFIG_PATH} | /bin/grep -q /usr/X11R6/lib/pkgconfig"
  if ( $status ) then
    # Path is not already in PKG_CONFIG_PATH,
    # prepend it to PKG_CONFIG_PATH
    setenv PKG_CONFIG_PATH "/usr/X11R6/lib/pkgconfig:${PKG_CONFIG_PATH}"
  endif
else
  # PKG_CONFIG_PATH is empty
  setenv PKG_CONFIG_PATH "/usr/X11R6/lib/pkgconfig"
endif
