#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include <string.h>

void
handler(int num) {
  int i = 1;
  char buf[2] = "A";

  while (1) {
    /* Using write since printf is unsafe inside hanlder */
    write(STDOUT_FILENO, "handler\n", 9);
    write(STDOUT_FILENO, buf, sizeof(buf));
    sleep(i++);
    buf[0]++;
  }
}


int
main()
{
  signal(SIGINT, handler);
  signal(SIGTERM, handler);
  
  while (1) {
    printf("main pgm is executing; pid: %d\n", getpid());
    sleep(1);
  }
}
    
