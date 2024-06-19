#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// từ process A tạo ra B qua lệnh fork(), tiến trình A thực hiện việc tạo ra 1 file vào folder có sẵn ./log/, ghi dữ liệu vào
// tiến trình B thực hiện việc đọc dữ liệu ra

#define BUFFER_SIZE 50

void main()
{
    pid_t child_pid;

    child_pid = fork();
    if (0 == child_pid) {       /* Process con */
        sleep(2);
        printf("\nIm the B\n");
        printf("My PID is: %d, my parent PID is: %d", getpid(), getppid());
        printf("\n");

        int fd2 = open("./log/hello.txt", O_RDONLY);
        ssize_t bytes_read;
        char buffer[BUFFER_SIZE];
        bytes_read = read(fd2, buffer, BUFFER_SIZE - 1);
        buffer[bytes_read] = '\0';
        printf("Data read from file:\n%s\n", buffer);

        // Đóng file
        close(fd2);

    } else {                    /* Process cha */
        printf("\nIm the A\n");
        printf("My PID is: %d, child_pid = %d\n", getpid(), child_pid);

        char buffer[30] = "trung dep trai";
        int fd2 = open("./log/hello.txt", O_WRONLY | O_CREAT, 0666);
        write(fd2, buffer, strlen(buffer));
        close(fd2);

        while (1);
    }

}