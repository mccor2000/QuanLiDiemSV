CC=g++

CFLAG=-c 

all: main dssv dsdk dsltc dsmh
	$(CC) main.o SinhVien.o DangKy.o dsltc.o dsmh.o -o app

main: src/main.cpp
	$(CC) $(CFLAG) src/main.cpp

dssv: include/SinhVien/SinhVien.cpp
	$(CC) $(CFLAG) include/SinhVien/SinhVien.cpp 

dsdk: include/DangKy/DangKy.cpp
	$(CC) $(CFLAG) include/DangKy/DangKy.cpp

dsltc: include/DSLTC/dsltc.cpp
	$(CC) $(CFLAG) include/DSLTC/dsltc.cpp

dsmh: include/DSMH/dsmh.cpp
	$(CC) $(CFLAG) include/DSMH/dsmh.cpp 

clean: 
	rm *.o
