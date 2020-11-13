/* signal_fpe_handler.c */
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handler_dividebyzero(int signum);

int main() {
   int result;
   int v1, v2;
   
   if (signal(SIGFPE, handler_dividebyzero) == SIG_ERR) {
      perror("Signal Error: ");
      return 1;
   }
   v1 = 121;
   v2 = 0;
   result = v1/v2;
   printf("Result of Divide by Zero is %d\n", result);
   return 0;
}

void handler_dividebyzero(int signum) {
   if (signum == SIGFPE) {
      printf("Received SIGFPE, Divide by Zero Exception\n");
      exit (0);
   } 
   else
      printf("Received %d Signal\n", signum);
      return;
}
