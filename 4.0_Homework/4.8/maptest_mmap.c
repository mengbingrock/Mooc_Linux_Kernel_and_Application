#include<unistd.h>
#include <stdio.h>  
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/time.h>
#include <unistd.h>  
#include <sys/mman.h>  
#include <sys/types.h>  
#include <fcntl.h>  
#include <stdlib.h>  
#include <string.h>
#define LEN 4096  
#define MAX 4096  


int main(void)  
{  
    int fd,loop;
    char *vadr;  
    char array[LEN];
    struct timeval tv1,tv2;    
    char *array2 = (char *)malloc( sizeof(int)*LEN);

 
    printf("my pid and ppid is %ld %ld\n", (long)getpid(), (long)getppid());
    if ((fd = open("mmap_test", O_RDWR)) < 0) {  
	printf("failed to open\n");
        return 0;  
    }  
    
   


    vadr = mmap(0, sizeof(char)*LEN, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);       
    gettimeofday(&tv1, NULL);
    for(loop=0;loop<LEN-1;loop++){
     //vadr[loop]=4;
     strcpy(&vadr[loop],"d");
    }
    //msync( vadr, sizeof(int)*MAX, MS_SYNC );
    munmap(vadr, sizeof(char)*LEN); 
    gettimeofday(&tv2, NULL);

    close( fd );
    printf("Time of mmap: %ld ms\n", tv2.tv_usec-tv1.tv_usec );
    while(1)
    {
        sleep(1);
    }
     
}  
