/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int go_on = 1; 
int num_of_alarms = 0;
time_t start, end;


void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  go_on = 0;
  num_of_alarms +=1;
}

void handler_interrupt(int signum){
  end = time(NULL);
  printf("caught SIGINT Signal!\n");
  printf("Time taken to execute the program: %1f seconds\n",(double)(end-start));
  printf("Number of alarms that occured: %d\n" ,num_of_alarms);
  exit(1);
}

int main(int argc, char * argv[])
{
  start = time(NULL);
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  signal(SIGINT, handler_interrupt);
  while (1) {
    alarm(1); //Schedule a SIGALRM for 1 second
    while(go_on); 
    printf("Turning was right!\n");
    go_on = 1;
  }
  return 0; //never reached
}