#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main ( int argc, char *argv[] )
{	
	if ( argc == 1 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "%s ERROR \n", argv[0] );
    }
	else
	{
	int j=0,lines=0,next,file_desc,temp_line=0,flag=0,flag_set=0;
	char convert,a[500],enter=0;
	const char* inputfile;
		
		for (next=0;argv[1][next]!='\0';next++)
		{
		
		convert=argv[1][next];
		
		lines=(lines*10)+((int)convert-48);
		
		}
		if(lines==0||lines==' ')
		{
		printf("Error \n");
		return 0;
		}
		
		if(argc>1){
				for(j=2;j<argc;j++)
					{
					
						inputfile=argv[j];
						
				file_desc=open(inputfile,O_RDWR);
				
				if ( file_desc == -1)//no such file
					{
					    printf( "ERROR %s \n",inputfile );
					}
					else //if file present 
					{
						if(argc>3)
						{
						printf("\n ::::::::::::::");
						printf("%s",inputfile);
						printf(":::::::::::::: \n");
						}
					
						int check=0,i=0,flag_set_inc=1;
						
           					while  ( (check=read(file_desc,a,500)) > 0 )
						{	flag=0;i=0;
							for(i;i<check;i++)
							{ 
								
								if(a[i]!='\n' && temp_line<lines)
								{
								
									printf("%c",a[i]);
									
								}
								else if(a[i]=='\n'&& temp_line<lines)
								{	flag_set_inc++;
									//printf("\n");
									//flag=0;
									if(temp_line==0)
									{printf("\n");
									}
									temp_line++;
									//flag setting to avoid new line first time
									if(flag_set_inc==lines+1)
									{
										
										flag_set=1;
									}
									else
									{
									flag_set=0;
									}
								
								}
								else if(temp_line==lines)
								{
									//if user input is required it need to b in enter variable
									scanf("%c",&enter);
									flag=1;
									//printf("%d",flag);
									if(enter==' ')
									{
									flag=0;//flag for new line logic
									temp_line=1;
									
									}
									else if(enter==10)
									{
									
									temp_line--;
									}
									else if(enter=='q'||enter=='Q')
									{
									return 0;
									}
									else
									{
									printf("ERROR");
									return 0;
									}
									i--;
								}
								
								if(a[i]=='\n'&&flag!=1&&temp_line!=1&&flag_set==0)//logic for new line
								{

									printf("\n");
									flag_set=0;
								}
								

							
							}
													
						}
					}
				
					}
			}
			  
	
	}
return 0;
}

