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
    
    gettimeofday(&tv1, NULL );
   
    if(sizeof(int)*LEN != read(fd, (void *)array2, sizeof(int)*LEN)){
        printf( "Reading data failed...\n" );
        //return -1;

    }
    
    gettimeofday( &tv2, NULL );
    printf("Time of read: %ld ms\n", tv2.tv_usec-tv1.tv_usec );


    //vadr = mmap(0, LEN, PROT_READ, MAP_PRIVATE | MAP_LOCKED, fd, 0);       
    for(loop=0;loop<LEN;loop++){
        //printf("a",vadr+4096*loop,vadr+4096*loop);
	//strcpy(array[loop],"a");
	strcpy(&array2[loop], "1");
	//++array2[loop];
    }

    gettimeofday(&tv1, NULL);
    write(fd,(void *)array2,sizeof(int)*LEN);
    gettimeofday(&tv2,NULL);
    printf("write complete\n");
    printf("Time of write: %ld ms\n", tv2.tv_usec-tv1.tv_usec );

    close( fd );
    while(1)
    {
        sleep(1);
    }
     
}  
