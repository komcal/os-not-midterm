#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0; /*  this data is shared by the thread(s) */
void *runner(void *param); /*  threads call this function */

int main(int argc, char *argv[])
{
  char num[100], num2[100];
  printf("input to tid1: ");
  scanf("%s", num);
  printf("input to tid2: ");
  scanf("%s", num2);
  pthread_t tid; /* the thread identifier */
  pthread_t tid2; /* the thread identifier */
  pthread_attr_t attr; /* set of thread attributes */

  pthread_attr_init(&attr);
  /* create the thread */
  pthread_create(&tid, &attr, runner, num); /* wait for the thread to exit */
  pthread_create(&tid2, &attr, runner, num2); /* wait for the thread to exit */
  pthread_join(tid,NULL);
  pthread_join(tid2,NULL);
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
