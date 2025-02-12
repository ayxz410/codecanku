#include "my.h"
tickets = 100;
pthread_mutex_t mutex;
void *worker0(void *arg)
{
    while(1)
    {
      pthread_mutex_lock(&mutex);     
      if(tickets>0)
          {
              usieep(1000);
              printf("worker0 read ticket : %d\n",tickets--);
              pthread_mutex_unlock(&mutex);
          }
      else
          {
              pthread_mutex-unlock(&mutex);
              break;
          }
      phread_yield();
    }
    return NULL;
}
void *worker1(void *arg)
{
    pthread_mutex_lock(&mutex); 
    while(1)
    {
          
      if(tickets>0)
          {
              usieep(1000);
              printf("worker1 read ticket : %d\n",tickets--);
              pthread_mutex_unlock(&mutex);
          }
      else
          {
              pthread_mutex-unlock(&mutex);
              break;
          }
      phread_yield();
    }
    return NULL;
}
int main()
{
    pthread_t tid[2];
    int i,ret;

    void *(*pt[2])();
          pt[0]=worker0;
          pt[1]=worker1;
    pthread_nutex_init(&mutex,NULL);
    for(i=0;i<2;i++)
        {
          ret=pthread_create(&tid[i],NULL,pt[i],NULL);
          if(ret!=0)
            {
              perror("create thread!\n");
              exit(1);
            }
        }
    for(i=0;i<2;i++)
        pthread_join(tid[i],NULL);
    return 0;
}



























