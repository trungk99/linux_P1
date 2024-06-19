#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// tạo ra 1 cặp process cha con thông qua system call fork()

int main(int argc, char const *argv[])   /* Cấp phát stack frame cho hàm main() */
{
    pid_t child_pid;                /* Lưu trong stack frame của main() */
    int counter = 2;                /* Lưu trong frame của main() */

    printf("\nGia tri khoi tao cua counter: %d\n", counter);

    child_pid = fork();         

    if (0 == child_pid) {       /* Process con */
        sleep(2);
        printf("\nIm the child process, counter: %d\n", --counter);
        printf("My PID is: %d, my parent PID is: %d\n", getpid(), getppid());
        printf("\n");
        
    } else {                    /* Process cha */
        printf("\nIm the parent process, counter: %d\n", ++counter);
        printf("My PID is: %d, child_pid = %d\n", getpid(), child_pid);
        while (1);
    }

    return 0;
}
