#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NTHREADS 5


int array[5] = { 2, 3, 5, 7, 11 };


void *Fatorial(void *pos)
{
    int res = 1, fat;
    int *postion = (int *)pos; 
    printf("Enter the factorial function %d***\n", *postion);
    
    for(fat = array[*postion]; fat > 1; fat--)
    {
         res *= fat;
    }
 
    array[*postion] = res;
    pthread_exit(NULL);
}

int main()
{
  printf("Start of function\n");
  int i = 0,rc = 0, pos[NTHREADS]; 
  pthread_t tid[NTHREADS]; 
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  printf("Before the FOR\n");

  
  for(i = 0; i < NTHREADS; i++)
  {
    
    pos[i] = i;
    rc = pthread_create(&tid[i], &attr, &Fatorial, (void *)&pos[i]);
    if (rc)
    {
      printf("ERROR - return code from pthread_create() is %d\n", rc);
    }
  }


  for(i = 0; i < NTHREADS; i++)
  {
    rc = pthread_join(tid[i], NULL);
    if (rc)
    {
        printf("ERROR; return code from pthread_join() is %d\n", rc);
    }
  }
  printf("Array[] = ");
  for(i = 0; i < NTHREADS; i++)
  {
    printf("%d ",array[i]);
  }
  pthread_attr_destroy(&attr);
  pthread_exit(NULL);
  return 0;
}
