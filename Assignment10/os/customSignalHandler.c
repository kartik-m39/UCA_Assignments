#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

// TODO: Write your signal handler function here
void handle_sigint(int sig) {

  if(sig == SIGINT){
    signal_count++;
    printf("\nCtrl + C pressed\n");
  }

  if(signal_count == 3){
    printf("\nCtrl + C pressed thrice\nQuitting the program\n");
    exit(0);
  }
}

int main() {

  signal(SIGINT, handle_sigint);

    // TODO: Register the signal handler.
  printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

  while (1) {
    sleep(1);
  }

  return 0;
}
