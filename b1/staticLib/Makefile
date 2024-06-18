

static:
	ar rcs lib/static/libhello.a obj/helloKhanh.o obj/helloWorld.o

link: all static
	gcc obj/main.o -Llib/static -lhello -o bin/static
 
all: 
	gcc -c main.c -o obj/main.o -I./inc
	gcc -c src/helloKhanh.c -o obj/helloKhanh.o -I./inc
	gcc -c src/helloWorld.c -o obj/helloWorld.o -I./inc
	
clean:
	rm -rf obj/* bin/*
	rm -rf lib/static/*
