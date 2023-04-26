#include <stdlib.h>
#include <stdio.h>
#include "eventbuf.c"
#include <semaphore.h>
#include <pthread.h>

sem_t *sem_open_temp(const char *name, int value)
{
    sem_t *sem;

    // Create the semaphore
    if ((sem = sem_open(name, O_CREAT, 0600, value)) == SEM_FAILED)
        return SEM_FAILED;

    // Unlink it so it will go away after this process exits
    if (sem_unlink(name) == -1) {
        sem_close(sem);
        return SEM_FAILED;
    }

    return sem;
}

void *producer(void *arg) {
// event = waitForEvent()

// spaces.wait()
// mutex.wait()
// buffer.add(event)
// mutex.signal()
// items.signal()
}

void *consumer(void *arg) {
// items.wait()
// mutex.wait()
// event = buffer.get()
// mutex.signal()
// spaces.signal()
// event.process()
}

int main(int argc, char *argv[]) {
  
}
// Parse the command line

// Create the event  buffer
// This should be a global variable so all threads can see it
// Start the correct number of producer threads
// Each thread will be passed a pointer to an int, its ID number
// Start the correct number of consumer threads
// Each thread will be passed a pointer to an int, its ID number
// Wait for all producer threads to complete
// Notify all the consumer threads that they're done
// This should cause them to exit
// Wait for all consumer threads to complete
// Free the event buffer