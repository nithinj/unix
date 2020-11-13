#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
   int pid;
   char grep[64];
   sprintf(grep, "ps -ef | grep %s | grep -v grep", argv[0]);
   pid = fork();
   
   // Child process
   if (pid == 0) {
      system(grep);
      sleep(10);
      system(grep);
   } else {
      printf("child pid = %d\n", pid);
      sleep(3);
   }
   return 0;
}
