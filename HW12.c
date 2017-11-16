#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int main () {

  printf("START\n");
  int f = fork();
  //printf("%d, also pid: %d\n", f, getpid());
  // parent
  f = 0;
  if (f) f = fork();
  // child

  
  
  if (!f) {
    int rand = 1;
    printf("Pid: %d\n", getpid());
    sleep(rand);
    printf("Child is dead\n");
    return rand;
  }

  wait(&status);
  printf("Temp: %d\n", WEXITSTATUS(status));
  
  printf("boi\n");
  
}
