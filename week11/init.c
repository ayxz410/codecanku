#include "my.h"
void init_daemon(void)
{
  pid_t p;
  int i;
  p=fork();
  if(p>0)
    exit(0);
  else if(p<0)
    {
      perror("fork fail\n");
      exit(1);
    }
  setsid();
  chdir("/tmp");
  umask(0);
  fork(i=0;i<NOFFILE;i++)
    close(i);

}
