#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define IN 1
#define OUT 0
int main ( int argc, char *argv[] )
{

    if ( argc == 1 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else 
    {
	int f=0,j,file_desc,count_word=0,line_count=0,i,char_count=0,byte_count=0,max=0,line_charcount=0;
	int l=0,L=0,m=0,c=0,w=0,k=0;
	char a[500],temp[20];
        // argv[1] is a filename to open
	const char* inputfile;
        
	//tokenizing
	if(argc>1){
	for(j=1;j<argc;j++)
		{
					
			strcpy(temp, argv[j]);
			if(temp[0]=='-')
			{		k=1;
					while (temp[k]!='\0'){ 
							//set flag for the options 
					if (temp[k]=='l')
					{
						l=1;
					}
					else if (temp[k]=='L')
					{
						L=1;
					}
					else if (temp[k]=='m')
					{
						m=1;
					}
					else if (temp[k]=='c')
					{
						c=1;
					}
					else if (temp[k]=='w')
					{
						w=1;
					}
					else{
					printf("ERROR \n");
					return 0;
						}
					k++;
					}
			}
			else //check if not options then is is file 
			{
			inputfile=argv[j];
			}
			
		}
		}	
	file_desc=open(inputfile,O_RDWR);//open command to file 
        /* open returns -1 on fail */
        if ( file_desc == -1)
        {
            printf( "ERROR\n" );
        }
        else //if file present 
        {	
          int check=0;
           while  ( ( check=read(file_desc,a,500)) > 0 )
        {
	i=0;
	byte_count=byte_count+check;
	while (i<check)
	{	
		
               if(a[i] == ' '||a[i] == '\t'||a[i]=='\n')
                       {
			f=OUT;
                       }
		else if(f==OUT)
		{
		f=IN;
		count_word++;	//counts the number of word
		}
              if(a[i] == '\n')
                       {			
			if(max < line_charcount)
			{
			max=line_charcount;
			}
			line_charcount=0;
			line_count++;//counts the number of line
	               }
			i++;
		char_count++;
		line_charcount++;
	} 
	}
	if(l==0 && w==0 && c==0 && m==0 && L==0)
	{
	printf("%d %d %d ",line_count,count_word,char_count);
	}
else{
	if (l==1)
	{
	printf("%d ",line_count);
	}
	if (w==1)
	{
	printf("%d ",count_word);
	}
	if (c==1)
	{
	printf("%d ",char_count);
	}
	if(m==1)
	{
	printf("%d ",byte_count);
	}
	if(L==1)
	{
	printf("%d ",max);	
	}
		           
   }
printf("%s \n",inputfile);
   }
    }
return 0;
}
