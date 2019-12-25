#inlude "my.h"

void *fun (void *arg)
{
  struct sendval * k= (struct sendval *)arg;
  int i=0;sum=0;
  for(i=0;i<k->s;i++)
    sum+=i;
  printf("worker---%d : pthread_self return %p,sun of %d = %d\n",k->n,(void*)pthread_self(),k->s,sum);
  
  pthread_exit(NULL);
  return NULL;
}

int main()
{
  pthread_t tid[NUM];
  int ret[NUM],i;
  struct sendval d;
  for(i=0;i<NUM;i++){
  d.n=i;
  d.s=100*(i+1);
  ret[i]=pthread_create(&tid[i],NULL,fun,(void *)i);
  if (ret[i] !=0)
    {
      perror("create fail!\n");
      return -1;
    }
  pthread_join(tid,NULL);
  ret=pthread_create(&tid,NULL,fun,NULL);
  if (ret !=0)
    {
      perror("create fail!\n");
      return -1;
    }

  printf("Master %d :All Done!\n",getpid());
  return 0;
}

