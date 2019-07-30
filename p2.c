//Wade Colby Roundy
//Project 2
//Details for this project
/*Your program will call the fork system call at the very start. 
The parent process will display a message indicating it has started and will then wait 
for a specific child process ID to complete. Once the child process has completed, the 
parent process will display a message indicating that the child is complete and the 
parent will now terminate.  The child process will display a message indicating that 
it has started. If one or more arguments were provided on the command line, the child 
process will perform the appropriate exec system call to load the new executable into 
memory with the appropriate arguments if provided. It should call execlp if there is one 
argument and execvp if there is more than one argument. The child process should print a 
message saying which version of exec it is calling, as in the examples below. If no arguments 
were provided, the child process will display a message indicating that it will terminate.
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>




int main(int argc, char *argv[])
{
 int args = argc-1;
 //argv[argc+1] = NULL;
 pid_t childpid = fork();
//error
 if(childpid < 0)
 {
  perror("fork() error");
  exit(-1);
 }
//parent process
 if(childpid != 0)
 {
  printf("Parent Process started, now waiting for ID: %d\n",childpid);
  wait(NULL);
  printf("Parent Process resumeed. Child exit code 0. Now terminating\n");
  exit(0);
 }
//child process
  if(args > 0)
  {
   printf("Child process has begun.  %d argument/s provided\n",args);
   //execvp(argv[1],  argv);
   int i;
   for(i = 1; i <= argc; i++)
   {
     if(argc <= 2)
     {
        execlp(argv[i] ,argv[i], NULL);
     }
     else
     {
        //execpv(argv[i], argv);
        execvp(argv[i], &argv[i]);
     }
   }
  }
  else
  {
   printf("No arguments provided, terminating child\n");
  }
 return 0;
}
