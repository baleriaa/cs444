#include <pthread.h>
#include <stdio.h>

void *print_numbers(void* arg) {
  for (int i = 0; i < 5; i++){
    printf("%s: %i\n", (char*) arg, i);

  }
    pthread_exit(NULL);
}

int main(void) {
  pthread_t thread1;
  pthread_t thread2;
  
  char *thread_name = "thread 1";
  char *thread2_name = "thread 2";

  pthread_create(&thread1, NULL, print_numbers, (void*) thread_name);
  pthread_create(&thread2, NULL, print_numbers, (void*) thread2_name);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  return 0;
}