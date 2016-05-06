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
	int id_shared_memory,i,data_put,loop_until;
	struct Memory *pntr_shared_memory;
	int argv1 = atoi(argv[1]);//converting to int
	int argv2 = atoi(argv[2]);//converting to int 
	keyshm=ftok("./",'a');
		if (keyshm!=-1)//check key_t is not a failure
		{
			id_shared_memory=shmget(keyshm,size,IPC_CREAT|0666);
			if(id_shared_memory<0)
            {
                perror("shmget");
                return 1;
            }
            //first time puting the data
			pntr_shared_memory=(struct Memory *) shmat(id_shared_memory,NULL,0);
			pntr_shared_memory->sync_status=1;//used for sync 
			 data_put=argv1;
			pntr_shared_memory->data=data_put;//put data in shared memory 
			pntr_shared_memory->sync_status=0;//now ready to be consumed
			while (pntr_shared_memory->sync_status!= 1)
					sleep(1);
				if (argv2%2==0)//logic for odd and even input 
				{
					loop_until=argv2/2;	/* code */
				}
				else
				{
					loop_until=argv2+1;
					loop_until=loop_until/2;
					//loop_until=loop_until-1;
				}


			for (i = 1; i < loop_until; ++i)//process the same till argv[2]
			{
				while (pntr_shared_memory->sync_status!= 1)
					sleep(1);
			printf("Received %d from consumer.\n",pntr_shared_memory->data);
			data_put=pntr_shared_memory->data+data_put;
				pntr_shared_memory->data=data_put;
			printf("Sending %d to consumer. \n",pntr_shared_memory->data);
			pntr_shared_memory->sync_status=0;
			}
		}

	shmdt((void*)pntr_shared_memory);//detach memory
	shmctl(id_shared_memory, IPC_RMID, NULL);
	return 0;
}
