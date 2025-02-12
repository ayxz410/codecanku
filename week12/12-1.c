#include "my.h"

int main()
{
  pid_t p;
  int fd[2],rn,wn;
  char rbuf[30],wbuf[30];
  memset (rbuf,0,sizeof(rbuf));
  memset (wbuf,0,sizeof(wbuf));
  pipe(fd);
  p=fork();
  if(p<0)
    {
      perror("fork failed.\n");
      return -1; 
    }
  else if(p==0)
    {
      close(fd[0]);
      sprintf(wbuf,"[child %d] is running.\n",getpid());
      while(1)
      {
        wn=write(fd[1],wbuf,sizeof(wbuf));
        printf("[child] write to pipe %d byte.\n",wn);
        if(wn==-1)
          {
            printf("[child] write errror.\n");
            break;
          }
      }
      close(fd[1]);

      exit(0);
    }
  else{
      close(fd[1]);
      while(1)
        {
        rn=read(fd[0],rbuf,sizeof(rbuf));
        printf("[parent] read from pipe %d byte.Conten of pipe is %s\n",rn,rbuf);
        if(rn==0)
          {
            printf("[parent] read errror.\n");
            break;
          }
        }
      close(fd[0]);
      return 0;
      }

}
