BOFNAME := append
CXXFLAGS += -w
CC_x64 := x86_64-w64-mingw32-gcc

all:
	$(CC_x64) -o $(BOFNAME).x64.o -Os -c append.c -masm=intel

clean:
	rm *.o
