#include <pthread.h>

int main(void) {
  // main thread is the one running by default

  // have main thread spawn two other threads
    // both threads will run same function
      // print out nums 0-5, with thread name as prefix "thread i: x"

  // in pthread_create(), pass thread name to new thread. make it a char*.
    // first call: thread1. second call: thread2
  // use pthread_join to wait from completions
 return 0;
}