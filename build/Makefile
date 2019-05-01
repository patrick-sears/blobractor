


$(info "Starting make.")

LBITS := $(shell getconf LONG_BIT)

versionfile=../version
version=`cat $(versionfile)`
$(info "Working on version $(version)")
senddir=../blobractor-$(version)

ifeq ($(LBITS),64)
	obj = obj-64
	aabin = aabin-64
else
	obj = obj-32
	aabin = aabin-32
endif


all : ${obj}/Makefile
	cd "${obj}"; make
	cp "${obj}/aabin" ${aabin}
	cp "${obj}/aabin" ${senddir}/${aabin}


${obj}/Makefile : obj-Makefile/Makefile
	cp -f obj-Makefile/Makefile ${obj}


clean : ${obj}/Makefile
	rm -f source/*~
	rm -f source/.*.swp
	cd "${obj}"; make clean


clean32 :
	cd "obj-32"; rm -f *.o
	cd "obj-32"; rm -f Makefile
	cd "obj-32"; rm -f aabin

clean64 :
	cd "obj-64"; rm -f *.o
	cd "obj-64"; rm -f Makefile
	cd "obj-64"; rm -f aabin


realclean : clean32 clean64
	rm -f source/*~
	rm -f source/.*.swp
	rm -f aabin-32
	rm -f aabin-64
	rm -f $(senddir)/aabin-32
	rm -f $(senddir)/aabin-64








