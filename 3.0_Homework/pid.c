#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
pid_t pid = getpid(); /* get current processes PID */
printf("My pid: %d\n", pid);
exit(0);
}
