#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
   int pid;
   char grep[64];
   sprintf(grep, "ps -ef | grep %s | grep -v grep", argv[0]);
   system(grep);
   pid = fork();
   if (pid == 0) {
      printf("Child: pid is %d and ppid is %d\n",getpid(),getppid());
      sleep(5);
      printf("Child: pid is %d and ppid is %d\n",getpid(),getppid());
      system(grep);
   } else {
      printf("Parent: pid is %d and ppid is %d\n",getpid(),getppid());
      sleep(2);
      exit(0);
   }
   return 0;
}
