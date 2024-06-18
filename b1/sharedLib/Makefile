

shared:
	gcc -shared obj/helloKhanh.o obj/helloWorld.o -o lib/shared/libShared.so

install:
	install lib/shared/libShared.so /usr/lib

link: all shared install 
	gcc obj/main.o -Llib/shared -lShared -o bin/statically-linked
 
all: 
	gcc -c main.c -o obj/main.o -I./inc
	gcc -c -fPIC src/helloKhanh.c -o obj/helloKhanh.o -I./inc
	gcc -c -fPIC src/helloWorld.c -o obj/helloWorld.o -I./inc
	
clean:
	rm -rf obj/* bin/*
	rm -rf lib/shared/*
	sudo rm -rf /usr/lib/libShared.so
