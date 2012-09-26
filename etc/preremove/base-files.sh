#!/bin/sh
# base-files version 3.7-1

manifest=/etc/preremove/base-files-manifest.lst

[ -f $manifest ] || (echo "Unable to find manifest file" && exit 0)

echo "*** Removing unmodified base files."
echo "*** These will be updated by the postinstall script."
echo "*** Please wait."

while read f; do
  /bin/cmp -s "/${f}" "/etc/defaults/${f}" && \
    (echo /$f hasn\'t been modified, it will be updated ; \
     /bin/rm -f "/${f}")
done < ${manifest}
