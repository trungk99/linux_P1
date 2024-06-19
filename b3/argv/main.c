#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]) 
{   
    // int i;
    if(strcmp(argv[1], "-l") == 0)
    {
        printf("trung dep trai\n");
    }
    else if(strcmp(argv[1], "trung") == 0)
    {
        printf("trung xau trai\n");
    }
    else
    {
        printf("huyen\n");
    }
    // printf("Number of arguments: %d\n", argc);    
    // for (i = 0; i < argc; i++) {
    //     printf("argv[%d]= %s\n", i, argv[i]);
    // }
}
