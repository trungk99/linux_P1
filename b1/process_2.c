#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<fcntl.h> 
  
int main (void) 
{ 
    int fd; 
    char buf1[8] = "huyen";
    char buf2[10] = "1234567"; 
  
    fd = open("hello.txt", O_RDWR | O_CREAT , 0667);         
    if (-1 == fd) { 
	    printf("open() hello.txt failed\n");
    }      
    while (1){
        write(fd, buf1, strlen(buf1));
        write(fd, buf2, strlen(buf2));
        //printf("Write %d bytes to hello.txt\n", numb_write);
        sleep(2);
    }
    
    close(fd);
    return 0; 
} 