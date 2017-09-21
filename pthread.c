#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREDS 3

int sum = 0; /*  this data is shared by the thread(s) */
void *runner(void *param); /*  threads call this function */

int main(int argc, char *argv[])
{
  char num[3][100];
  printf("input to tid1: ");
  scanf("%s", num[0]);
  printf("input to tid2: ");
  scanf("%s", num[1]);
  printf("input to tid3: ");
  scanf("%s", num[2]);
  
  pthread_t tid[NUM_THREDS]; /* the thread identifier */
  pthread_attr_t attr; /* set of thread attributes */

  pthread_attr_init(&attr);
  /* create the thread */
  for(int i = 0 ; i < NUM_THREDS ; i++)
  {
    pthread_create(&tid[i], &attr, runner, num[i]);
  }
  for(int i = 0 ; i < NUM_THREDS ; i++)
  {
    pthread_join(tid[i],NULL);
  }
  printf("sum = %d\n",sum);
}
/* The thread will begin control in this function */
void *runner(void *param)
{
   int i, upper = atoi(param);
   for (i = 1; i <= upper; i++) {
    printf("num from tid = %s, i = %d\n", param, i);
     sum += i;
   }
  pthread_exit(0);
}
