linux: mppew.c
	gcc -static -o mppew mppew.c
win: mppew.c
	x86_64-w64-mingw32-gcc -static -o mppew.exe mppew.c
all: linux win
