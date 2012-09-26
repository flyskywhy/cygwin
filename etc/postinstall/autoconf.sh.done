bindir=/usr/bin
wrapper=/usr/share/autotools/ac-wrapper.sh

cd ${bindir}

for prog in autoconf autoheader autom4te autoreconf autoscan autoupdate ifnames
do
	rm -f ${prog}
	ln -sfn ${wrapper} ${prog}
done
