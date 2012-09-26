#!/bin/sh

mkdir -p /srv/www

for dir in htdocs cgi-bin; do
  if [ ! -e /srv/www/$dir ]; then
    cp -r /usr/share/apache2/$dir /srv/www/$dir
  fi
done

cd /etc/apache2/original
for cf in httpd.conf extra/httpd-*.conf; do
  if [ ! -e ../$cf ]; then
    cp $cf ../$cf
  fi
done
