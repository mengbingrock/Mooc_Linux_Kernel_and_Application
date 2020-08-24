#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
int status;
pid_t cpid, mypid, tcpid;
pid_t pid = getpid(); /* get current processes PID */
printf("Parent pid: %d\n", pid);
cpid = fork();

if (cpid > 0) { /* Parent Process */
 mypid = getpid();
 printf("[%d] parent of [%d]\n", mypid, cpid);
 tcpid = wait(&status);
 printf("[%d] bye %d(%d)\n", mypid, tcpid, status);
 } 
else if (cpid == 0) { /* Child Process */
 mypid = getpid();
 printf("[%d] child\n", mypid);
 char *args[] = {"ls", "-l", NULL};
 execv("/bin/ls", args);
 /* execv doesn’t return when it works.
 So, if we got here, it failed! */
 perror("execv");
 exit(1);
 } 
else {
 perror("Fork failed");
 }
}
