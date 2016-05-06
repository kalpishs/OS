#include <sys/types.h>
 #include <sys/shm.h>
 #include <sys/ipc.h>
 #include <stdio.h>
 #include <sys/wait.h>
 #define size 100
struct Memory
{
	int sync_status;//used for syncroniztion
	int data;//data to be shared
	
};
int main(int argc, char const *argv[])
{
	key_t keyshm;
	int id_shared_memory,i,data_put,loop_until,flag;
	struct Memory *pntr_shared_memory;
	int argv1 = atoi(argv[1]);//(int)(argv[1][0] - '0');
	int argv2 = atoi(argv[2]);//(int)(argv[2][0] - '0');
	//printf("%d %d\n",argv1,argv2 );
	keyshm=ftok("./",'a');
	if (keyshm!=-1)//check key_t is not a failure
	{
		id_shared_memory=shmget(keyshm,size,IPC_CREAT|0666);
		if(id_shared_memory<0)
        {
            perror("shmget");
            return 1;
        }
  		pntr_shared_memory=(struct Memory *) shmat(id_shared_memory,NULL,0);
  		while (pntr_shared_memory->sync_status!=0)
			{	sleep(1);}


			data_put=argv1;
			pntr_shared_memory->data=data_put;
			pntr_shared_memory->sync_status=1;
			if (argv2%2==0)
			{
				loop_until=argv2/2;	/* code */
			}
			else
			{
				loop_until=argv2+1;
				loop_until=loop_until/2;
				loop_until=loop_until-1;
				flag=1;
			}
		for (i = 1; i < loop_until; ++i)
		{
			while (pntr_shared_memory->sync_status!= 0)
			//while (pntr_shared_memory-­>sync_status!= 0)
			{	//sshmdt((void*)pntr_shared_memory);
				sleep(1);}
			
			printf("Received %d from Producer.\n",pntr_shared_memory->data);
			data_put=pntr_shared_memory->data+data_put;
				pntr_shared_memory->data=data_put;
			printf("Sending %d to Producer. \n",pntr_shared_memory->data);
			pntr_shared_memory->sync_status=1;
		}
		if(flag==1)
		{
			while (pntr_shared_memory->sync_status!= 0)
			
			{	
				sleep(1);}
				printf("Received %d from Producer.\n",pntr_shared_memory->data);
		}
	shmdt((void*)pntr_shared_memory);
  	}
	
	//shmctl(id_shared_memory, IPC_RMID, NULL);
	return 0;
}