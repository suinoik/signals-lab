/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int go_on = 1;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  go_on = 0;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1){
    alarm(1); //Schedule a SIGALRM for 1 second
    while(go_on);
    printf("Turning was right!\n");
    go_on = 1;
  }
  return 0; //never reached
}