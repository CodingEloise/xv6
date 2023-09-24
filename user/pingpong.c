#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, const char *argv[])
{
    int fd_p2c[2], fd_c2p[2];
    int status;
    char *a = "a";
    int pid = fork();
    pipe(fd_c2p);
    pipe(fd_p2c);

    if(pid==0)
    {
        char buff[64];
        while(1)
        {
            read(fd_p2c[1],buff,sizeof(buff));
	        if(sizeof(buff))
            {
                printf("%d: received ping\n", getpid());
                write(fd_c2p[1],a,1);
                exit(0);
            }
        }    
    }

    else
    {
        char buff[64];
        write(fd_p2c[1],a,1);
        while(1)
        {
            read(fd_c2p[1],buff,1);
            if(sizeof(buff))
            {
                wait(&status);
                printf("%d: received pong\n", pid);
		        break;
            }
	    }
	    exit(0);
    }
}
