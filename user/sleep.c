#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argc, char *argv[])
{
    int read = atoi(argv[1]);

    if(argc==1)
    {
        printf("Error: please input a parameter!");
        exit(1);
    }

    if(argc!=2 || argv[1]<0) 
    {
        exit(1);
    }
    else
    {
        sleep(read);
        exit(0);
    }

}
