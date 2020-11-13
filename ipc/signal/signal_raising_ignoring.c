/* signal_raising_ignoring.c */
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>


int main() {

   if (signal(SIGTSTP, SIG_IGN) == SIG_ERR) {
      perror("Signal Error: ");
      return 1;
   }

   printf("Testing SIGTSTP\n");
   raise(SIGTSTP);
   printf("Signal SIGTSTP is ignored\n");

   return 0;
}
