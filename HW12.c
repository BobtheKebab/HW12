#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int main () {

  printf("START\n");

  // Child 1
  int f = fork();
  // Child 2
  if (f) f = fork();
  
  if (!f) {
    int rand = 1;
    printf("Pid: %d\n", getpid());
    sleep(rand);
    printf("Child is dead\n");
    return rand;
  } else {
    int status;
    wait(&status);
    printf("Child %d cooked for %d seconds\n", f, WEXITSTATUS(status));
  
    printf("END\n");
  }
  
}
