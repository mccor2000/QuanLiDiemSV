CC=g++

CFLAG=-c 

all: dssv dsdk dsltc dsmh dslcq modules 
	$(CC) *.o -o app ; rm *.o

dssv: ../../include/DSSV/dssv.cpp
	$(CC) $(CFLAG) ../../include/DSSV/dssv.cpp 

dsdk: ../../include/DSDK/dsdk.cpp
	$(CC) $(CFLAG) ../../include/DSDK/dsdk.cpp

dsltc: ../../include/DSLTC/dsltc.cpp
	$(CC) $(CFLAG) ../../include/DSLTC/dsltc.cpp

dslcq: ../../include/DSLCQ/dslcq.cpp
	$(CC) $(CFLAG) ../../include/DSLCQ/dslcq.cpp

dsmh: ../../include/DSMH/dsmh.cpp
	$(CC) $(CFLAG) ../../include/DSMH/dsmh.cpp 

modules: *.cpp
	$(CC) $(CFLAG) *.cpp
