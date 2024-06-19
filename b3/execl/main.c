#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    printf("run command ls -lah after 2 second\n");
    fflush(stdout);  // Flush bộ đệm để in ra màn hình ngay lập tức
    sleep(2);
    execl("/usr/bin/ls","ls","-l","-a","-h", NULL);
}