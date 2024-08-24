#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int count;
pthread_mutex_t control;

void  *funcion(void *arg)
{
  pthread_mutex_lock(&control);
  int i;
  i = 0;
  while (i < 1000000)
  {
  
   count++;
   
    i++;
  }
  pthread_mutex_unlock(&control);
  return NULL;
}
 
int main(void)
{
  pthread_t thread1;
  pthread_t thread2;
  
  count = 0;
  pthread_mutex_init(&control, NULL);
  pthread_create(&thread1, NULL, funcion, NULL);
  pthread_create(&thread2, NULL, funcion, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_mutex_destroy(&control);
  printf("%d \n", count);
  return (0);
}
