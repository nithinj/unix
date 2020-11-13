#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
   int pid;
   char grep[64];
   sprintf(grep, "ps -ef | grep %s | grep -v grep", argv[0]);
   pid = fork();
   if (pid == 0) {
      system(grep);
      printf("Child: pid is %d and ppid is %d\n",getpid(),getppid());
      exit(0);
   } else {
      printf("Parent: pid is %d and ppid is %d\n",getpid(),getppid());
      sleep(10);
      system("ps aux|grep Z");
   }
   return 0;
}
