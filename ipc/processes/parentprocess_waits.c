#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
   int pid;
   int status;
   char grep[64];
   sprintf(grep, "ps -ef | grep %s | grep -v grep", argv[0]);
   pid = fork();
   
   // Child process
   if (pid == 0) {
      system(grep);
      sleep(10);
      system(grep);
      return 3; //exit status is 3 from child process
   } else {
      sleep(3);
      wait(&status);
      printf("In parent process: exit status from child is decimal %d, hexa %0x\n", status, status);
   }
   return 0;
}
