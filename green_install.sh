find /bin -name "*.exe" | xargs file | grep 012 | sed "s/:.*//g" | xargs attrib +s
find /usr -name "*.exe" | xargs file | grep 012 | sed "s/:.*//g" | xargs attrib +s
