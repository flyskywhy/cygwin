prefix=/usr
incdir=${prefix}/include
slot=4.2

if ! update-alternatives --display db.h > /dev/nul
then
  cd /usr/lib
  rm -f libdb.a         		        libdb.dll.a     		        libdb.la        		        libdb_cxx.a     		        libdb_cxx.la    		        libdb_cxx.dll.a
  cd /usr/include
  rm -rf db.h db3 db4
fi

/usr/sbin/update-alternatives --remove db.h        ${incdir}/db${slot}/db.h
/usr/sbin/update-alternatives --remove db4 ${incdir}/db${slot}
