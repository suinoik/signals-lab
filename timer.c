/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

bool cont = true; 
int num_of_alarms = 0;
time_t start, end;


void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
    cont = false;
  // exit(1); //exit after printing
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
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, handler_interrupt);
  while (true) {
    alarm(1); //Schedule a SIGALRM for 1 second
    pause();
    while(cont); 
    printf("Turning was right!\n");
    cont = true;
    num_of_alarms +=1;


  
  }
  return 0; //never reached
}