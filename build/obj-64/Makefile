






GPP_O = g++ -std=c++11 -Wall -o aabin

# GPP_C = g++ -Wall -c
GPP_C = g++ -std=c++11 -Wall -c
# -std=c++1 and -std=gnu++1 may be the same thing?




OBJECTS = mainf.o \
cconfig.o \
blobractorpro.o
# locerror.o \


HEADERS = \
../source/cconfig.h \
../source/blobractorpro.h
# ../source/locerror.h \







# __________________________________________________________________
aabin: ${OBJECTS} ${HEADERS}
	${GPP_O} ${OBJECTS} ${HEADERS}







# __________________________________________________________________
mainf.o : ../source/mainf.cpp ${HEADERS}
	${GPP_C} ../source/mainf.cpp


cconfig.o : ../source/cconfig.cpp ../source/cconfig.h
	${GPP_C} ../source/cconfig.cpp


blobractorpro.o : ../source/blobractorpro.cpp ../source/blobractorpro.h
	${GPP_C} ../source/blobractorpro.cpp



# locerror.o : ../source/locerror.cpp ../source/locerror.h
# 	${GPP_C} ../source/locerror.cpp







# __________________________________________________________________
# Cleanup
clean :
	-rm -f *.o
	-rm -f ../source/*~



realclean : clean
	-rm -f aabin









