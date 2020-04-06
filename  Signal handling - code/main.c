//program 10A signal handling
//A)Write a program that creates a file and then goes into an infinite loop. Catch the following signals in the program:
/*a) SIGABRT, SIGFPE, SIGINT, SIGQUIT, SIGSEGV, SIGTERM: For these signals program should print a message giving details about the signal caught and then delete the file created in the beginning and finally terminate.
b) SIGALRM, SIGCHLD, SIGCONT, SIGPIPE, SIGUSR1, SIGUSR2: For these signals, print a message giving details about signal caught and then continue with program execution (don't terminate).
For testing the program create conditions (may require program modification for some signals) which generate following signals: SIGABRT, SIGINT, SIGQUIT, SIGCHLD, SIGCONT, SIGPIPE. For testing with other signals use kill command from another terminal.
*/
#include<stdio.h>
#include"apue.h"
#include<sys/wait.h>
#include<signal.h>
void rmfile();
static void sig_usr(int);
void pr_exit(int status);
char *name;
int g_flag=0; //global flag for breaking the while loop

int main(int argc,char *argv[])
{ 
//to creat a file and then go into infinite loop 
FILE *fp1;
int del_stat;
pid_t pid;
int status;
name="sample_file";
fp1=fopen(name,"wr+");//open the file with file pointer
  

  if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
     err_sys("can’t catch SIGUSR1\n");
    }
  if (signal(SIGUSR2, sig_usr) == SIG_ERR)
   {
    err_sys("can’t catch SIGUSR2\n");
   }
   if(signal(SIGCHLD,sig_usr)==SIG_ERR)
   {
    err_sys("can't catch SIGCHLD\n");
   }
   if(signal(SIGALRM,sig_usr)==SIG_ERR)
   {
    err_sys("can't catch SIGALRM\n");
   }

   if(signal(SIGCONT,sig_usr)==SIG_ERR)
   {
    err_sys("can't catch SIGCHLD\n");
   }

   if(signal(SIGPIPE,sig_usr)==SIG_ERR)
   {
    err_sys("can't catch SIGCHLD\n");
   }


  //first category:: 6 types which terminates after being caught
   if(signal(SIGINT,sig_usr)== SIG_ERR)
   {
    err_sys("can't catch SIGINT\n");
   }
  if(signal(SIGABRT,sig_usr)==SIG_ERR)
   {
     err_sys("can't catch SIGABRT\n");
   } 
  if(signal(SIGFPE,sig_usr)==SIG_ERR)
   {
     err_sys("can't catch SIGFPE\n");
   }

  if(signal(SIGQUIT,sig_usr)==SIG_ERR)
   {
     err_sys("can't catch SIGQUIT\n");
   }
  if(signal(SIGSEGV,sig_usr)==SIG_ERR)
   {
     err_sys("can't catch SIGABRT\n");
   }
  if(signal(SIGTERM,sig_usr)==SIG_ERR)
   {
     err_sys("can't catch SIGTERM\n");
   }//	sig_usr()	
	while(1)//infinite loop
	{}
	

return 0;
}


void rmfile()
{
int del_stat=1;
	del_stat=remove(name);
		if (del_stat==0)
		   printf("file %s deleted\n",name);
}

static void sig_usr(int signo)
/* argument is signal number */
{
switch(signo)
   {
     case SIGUSR1://THIS SET OF SIGNALS CONTINUES AFTER BEING CAUGHT ALSO
      printf("Received SIGUSR1 from signal number %d:\n",signo);
       break;
     case SIGUSR2:
     printf("Received SIGUSR2 from signal number %d:\n",signo);
       break;
     case SIGCHLD:
       printf("Received SIGCHLD from signal number %d:\n",signo);
       break;
     case SIGALRM:
       printf("Received SIGALRM from signal number %d:\n",signo);
       break;
     case SIGCONT:
       printf("Received SIGCONT from signal number %d:\n",signo);
       break;
     case SIGPIPE:
       printf("Received SIGPIPE from signal number %d:\n",signo);
       break;
     case SIGINT://ALL TERMINATES WHILE GIVING SIGNAL INFORMATION:
      printf("Received SIGINT from signal number %d:\n",signo);
      rmfile();
      exit(0);
     case SIGABRT:
       printf("Received SIGABRT from signal number %d:\n",signo);
       rmfile();
       exit(0);
     case SIGFPE:
       printf("Received SIGFPE from signal number %d:\n",signo);
       rmfile();
       exit(0);     
    case SIGQUIT:
       printf("Received SIGQUIT from signal number %d:\n",signo);
       rmfile();
       exit(0);
    case SIGSEGV:
       printf("Received SIGSEGV from signal number %d:\n",signo);
       rmfile();
       exit(0);
    case SIGTERM:
       printf("Received SIGTERM from signal number %d:\n",signo);
       rmfile();
       exit(0);
   default:
     err_dump("received signal %d\n", signo);
    
}
if (signo == SIGUSR1)
printf("received SIGUSR1\n");
else if (signo == SIGUSR2)
printf("received SIGUSR2\n");
else
err_dump("received signal %d\n", signo);

}



void pr_exit(int status)
{
if (WIFEXITED(status))
printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
else if (WIFSIGNALED(status))
printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
WCOREDUMP(status) ? " (core file generated)" : "");
#else
"");
#endif
else if (WIFSTOPPED(status))
printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}

/*


if (fp1==NULL)
		  	printf("File create error..File not created.");
		else
			printf("File %s is created.\n",name);
//sleep(10);
	
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		exit(7);
	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
		if ((pid = fork()) < 0)
	err_sys("fork error");
		else if (pid == 0)
	abort();
		if (wait(&status) != pid)
	err_sys("wait error");
		pr_exit(status);
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		status/= 0;
	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
		exit(0);
	*/
