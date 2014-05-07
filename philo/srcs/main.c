#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "philo.h"

void		philo(void *data)
{
   int i;
   pthread_exit((void*) i);
}

int main ()
{
   pthread_t thread[NUM_THREADS];
   pthread_attr_t attr;
   int rc;
   long i;
   void *status;
   t_philo	ph[NUM_THREADS];

   /* Initialize and set thread detached attribute */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for(i=0; i<NUM_THREADS; i++) {
      printf("Main: creating thread %ld\n", i);
      rc = pthread_create(&thread[i], &attr, philo, (void *)i); 
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
         }
      }

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
   for(i=0; i<NUM_THREADS; i++) {
      rc = pthread_join(thread[i], &status);
      if (rc) {
         printf("ERROR; return code from pthread_join is %d\n", rc);
         exit(-1);
         }
      printf("Main: completed join with thread %ld having a status of %ld\n",i,(long)status);
      }
 
printf("Main: program completed. Exiting.\n");
pthread_exit(NULL);
}
