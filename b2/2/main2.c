#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>

//tạo ra 2 file A,B .txt, ghi từ 1 đến 500 vào mỗi file, sau đó in ra thời gian thực thi của tiến trình

void write_to_file(const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    
    char buffer[20];
    for (int i = 1; i <= 500; i++) {
        snprintf(buffer, sizeof(buffer), "%d\n", i);
        if (write(fd, buffer, strlen(buffer)) == -1) {
            perror("write");
            close(fd);
            exit(1);
        }
    }
    
    close(fd);
}

int main() {
    struct timeval start, end;
    
    // start time
    gettimeofday(&start, NULL);
    
    // write data
    write_to_file("fileA.txt");
    write_to_file("fileB.txt");
    
    // end time
    gettimeofday(&end, NULL);
    
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    printf("time execute: %.6f seconds\n", elapsed);

    return 0;
}
