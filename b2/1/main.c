#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
// in ra màn hình các thông tin của file như dạng file(regular hoặc loại khác), kích thước, thời gian chỉnh sửa
int main() {
    int fd;
    char *data = "anything data 123";
    struct stat fileStat;
    
    fd = open("filesystem.txt", O_WRONLY | O_CREAT, 0667);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    if (write(fd, data, strlen(data)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }
    close(fd);
    
    if (stat("filesystem.txt", &fileStat) == -1) {
        perror("stat");
        return 1;
    }
    
    printf("type: %s\n", S_ISREG(fileStat.st_mode) ? "Regular file" : "Other");
    printf("time edit: %s", ctime(&fileStat.st_mtime));
    printf("size: %ld bytes\n", fileStat.st_size);

    return 0;
}
