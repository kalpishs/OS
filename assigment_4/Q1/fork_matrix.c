#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
int sum,temp;
int i,j,m,n;
int mat[200][200]={{0}};
scanf("%d",&m);//input for number of rows
scanf("%d",&n);//input for number of col
for (i = 0;i < m; ++i)//input of matrix
{
	for (j= 0; j < n; ++j)
	{
		scanf("%d",&mat[i][j]);
	}
	
}	
		for (i = 0; i < m; ++i)//for each row create a child
	{
		
		pid_t new_process=fork();//fork will create a child process
			sum=0;
		if (new_process==0)//check if process is a child process 
		{		
			for (j = 0; j < n ; ++j)//for each coloumn do sum
			{
				temp=mat[i][j];
				sum=sum+temp;
			}
			pid_t process_id=getpid();//getting child process id
			printf("Child pid : %d ",process_id);
			printf("Sum of row : %d is : %d \n",i,sum );
			exit(0);//exit the process once done
		}
		
	}
	return 0;
}
