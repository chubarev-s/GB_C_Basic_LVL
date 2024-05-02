all: sensor.exe
sensor.exe: main.o struct.o sort.o
	gcc -o sensor main.o struct.o sort.o
main.o: main.c config_hw11.h
	gcc -c -o main.o main.c
struct.o: struct.c
	gcc -c -o struct.o struct.c
sort.o: sort.c
	gcc -c -o sort.o sort.c
clean:
	del *.o sensor.exe