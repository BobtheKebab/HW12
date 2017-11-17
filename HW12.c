#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int main () {

  printf("START\n");
  printf("pid: %d\n", getpid());

  // Child 1
  int f = fork();
  // Child 2
  if (f) {
    //reset, so both children will have f=0
    f = 0;
    f = fork();
  }

  //if child...sleep for rand num and return it
  if (!f) {
    printf("Child pid: %d\n", getpid());
    //rand() % 16 yields 0-15; 0-15 + 5 overall yields 5-20 inclusive
    int r;
    srand(getpid()); //creds to kyle
    r = (rand() % 16) + 5;
    sleep(r);
    printf("Child is dead\n");
    return r;
  }
  //parent...wait for child; retrieve info on rand using int status
  else {
    int status;
    wait(&status);
    printf("Child cooked for %d seconds\n", WEXITSTATUS(status));
    printf("END\n");
  }
  
}
