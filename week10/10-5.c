#include "my.h"
void pr_exit(int status,pid_t pid){

  int sig;
  if(WIFEXITED(status))
    printf("process %d normal termination,exit status= %d\n",pid,WEXITSTATUS(status));
  else if(WIFSIGNGNALED(status)){

      sig=WIERMSIG(status)){
      printf("process %d abnormal termination,signal number = %d %s:\n",pid,sig,
      #ifdef WCORREDUMP
             WCORREDUMP(status)?"(core file generated)":"");
      #else
            "");
      #endif
         psignal(sig,"");
      else if(WIFSTOPPED(status)){
             sig=WSTOPSIG(status);
             printf("
