#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
   int pid;
   int pids[3];
   int status;
   int numprocesses = 0;
   int total_processes = 3;
   siginfo_t siginfo;
   while (numprocesses < total_processes) {
      pid = fork();
      
      // Child process
      if (pid == 0) {
         printf("In child process: process id is %d\n", getpid());
         sleep(5);
         return 2;
      } else {
         pids[numprocesses] = pid;
         numprocesses++;
         printf("In parent process: created process number: %d\n", pid);
      }
   }
   
   // Waiting for 3rd child process
   status = waitid(P_PID, pids[total_processes - 1], &siginfo, WEXITED);
   if (status == -1) {
      perror("waitid error");
      return 1;
   }
   printf("Info received from waitid is: ");
   printf("PID of child: %d, real user id of child: %d\n", siginfo.si_pid, siginfo.si_uid);
   return 0;
}
