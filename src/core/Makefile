CC=g++

CFLAG=-c 

all: dssv dsdk dsltc dsmh moduleA moduleB moduleC moduleC moduleD moduleE moduleF moduleG moduleH moduleI moduleJ 
	$(CC) *.o -o app ; rm *.o

dssv: ../../include/DSSV/dssv.cpp
	$(CC) $(CFLAG) ../../include/DSSV/dssv.cpp 

dsdk: ../../include/DSDK/dsdk.cpp
	$(CC) $(CFLAG) ../../include/DSDK/dsdk.cpp

dsltc: ../../include/DSLTC/dsltc.cpp
	$(CC) $(CFLAG) ../../include/DSLTC/dsltc.cpp

dsmh: ../../include/DSMH/dsmh.cpp
	$(CC) $(CFLAG) ../../include/DSMH/dsmh.cpp 

moduleA: moduleA.cpp
	$(CC) $(CFLAG) moduleA.cpp

moduleB: moduleB.cpp
	$(CC) $(CFLAG) moduleB.cpp

moduleC: moduleC.cpp
	$(CC) $(CFLAG) moduleC.cpp

moduleD: moduleD.cpp
	$(CC) $(CFLAG) moduleD.cpp

moduleE: moduleE.cpp
	$(CC) $(CFLAG) moduleA.cpp

moduleF: moduleF.cpp
	$(CC) $(CFLAG) moduleF.cpp

moduleG: moduleG.cpp
	$(CC) $(CFLAG) moduleG.cpp

moduleH: moduleH.cpp
	$(CC) $(CFLAG) moduleH.cpp

moduleI: moduleI.cpp
	$(CC) $(CFLAG) moduleI.cpp

moduleJ: moduleJ.cpp
	$(CC) $(CFLAG) moduleJ.cpp

