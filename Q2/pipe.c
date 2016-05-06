#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	pid_t new_process_id;
	int return_pipe_status;
	char buffer[200];
	int pipefd[2],p,n=1;
	return_pipe_status=pipe(pipefd);

	char *Temp[200]; 
	char *cmd1[200];
	char *cmd2[200];
	int i;
	for (i = 0; i < 200; ++i)
	{
		cmd1[i]=(char *)malloc(100*sizeof(char));
		cmd2[i]=(char *)malloc(100*sizeof(char));
		Temp[i]=(char *)malloc(100*sizeof(char));
	}
	
	
	if (argc<2)//if number of arguments are less than 2
	{
		printf("Error\n");
		return 1;
	}
			p=1;

			Temp[0]=strtok(argv[1],"|");
			while((Temp[p]=strtok(NULL,"|"))!=NULL)
				p++;
				Temp[p]=NULL;
  			
  			


	if (return_pipe_status!=-1)
	{
		new_process_id=fork();
		if(new_process_id==-1)
		{
			perror("fork Error");
			exit(1);
		}
		else if(new_process_id!=0)
		{

			close(pipefd[1]);//Parent close the Write end first
			dup2(pipefd[0], 0);//connect Std input to pipe read end
			cmd2[0]=strtok(Temp[1]," ");
			if(strcmp(cmd2[0],"grep")==0)
			{
				n=1;
				strcpy(cmd2[n],"--color=auto");
				n=2;
			}
			else{n=1;}
  			for(n;(cmd2[n]=strtok(NULL," "))!=NULL;n++);
  			cmd2[n]=NULL;
			close(pipefd[0]);//close the given file descriptior as not needed
			execvp(cmd2[0], cmd2);//execute the piped command by 
			
		}
	
		else if(new_process_id==0)
		{

			close(pipefd[0]);//Child 
			dup2(pipefd[1], 1);//connet standard ouptput of pipe write end
			cmd1[0]=strtok(Temp[0]," ");
  			for(n=1;(cmd1[n]=strtok(NULL," "))!=NULL;n++);
  			cmd1[n]=NULL;
			close(pipefd[1]);//close the given file descriptior as not needed
			execvp(cmd1[0], cmd1);

			
		}
	}
	else
	{
		perror("Pipe Error");//error encountered 
		return 1;
	}


	return 0;
}