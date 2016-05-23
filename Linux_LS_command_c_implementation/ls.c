#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <limits.h>
#include <time.h>
 
 char arr_check[280],mmonth_name[5];
 //char *test;
 void managemonth(int);
int main ( int argc, char *argv[] )
{	//struct dirent *reading_dir;
 
  struct passwd *get_userid;
 struct  group *get_group;
 DIR *read_dir;
struct stat getdetails;
struct stat comparedetail;
struct tm *gettime;
 char buffer[PATH_MAX + 1];
 //char arr_check[280],mmonth_name[5];
 int counting, i;
	const char *current_path="./";
	struct dirent **get_files;
	 //printf("%s\n",current_path );
	if ( argc == 1 ) //argc 1 means work neeed to b same as ls without option 
    {	
	counting = scandir(current_path,&get_files,0,alphasort);
	//current path in prog will alsways have the path of directory 
	//counting will count no of files and dir in the prog
	for (i=0;i<counting;++i)
	{
		
			print(get_files[i]->d_name,counting);//simply prints all files and dir  
	   
    }
    printf("\n");
     return 0;
    
       
    }
    else//thr is more than 1 argument means options are present 
    {
    	int f=0,j;
	 int l=0,flag=0,flagset=0,R=0,ti=0,a=0,S=0,indx=0,k=0;
	 char temp[500];
        
	 if(argc>1)//caclulating user given input through activing flag
	 	{

		 for(j=1;j<argc;j++)
			{
						
				strcpy(temp, argv[j]);
				if(temp[0]=='-')
				{		k=1;
					while (temp[k]!='\0')
					{ 
								//set flag for the options 
						if (temp[k]=='l')
						{
							l=1;
							if(flagset==0)
								{flag=1;}
							//printf("l\n" );
						}
						if (temp[k]=='R')
						{
							R=1;
							if(flagset==0)
								{flag=1;}
							
						}
						if (temp[k]=='a')
						{
							a=1;
							if(flagset==0)
								{flag=1;}
						}
						if (temp[k]=='S')
						{
							S=1;
							if(ti==1)//resetting time sort if S came in end 
							{
								S=1;
								ti=0;
							}
							if(flagset==0)
								{flag=1;}
							//printf("S\n" );
						}
						if (temp[k]=='i')
						{
							indx=1;
							if(flagset==0)
								{flag=1;}
						}
						if (temp[k]=='t')
						{
							ti=1;
							if(S==1)//resetting Size flag if time flag came in end
							{
								S=0;
								ti=1;
							}
							if(flagset==0)
								{flag=1;}
							
						}
						k++;
						
					}	
				}
				if (temp[0]!='-')//setting flag for dir/file present
				{ 
						flag=0;//once reset cannot be set bcz of flagset logic :) 
						flagset=1;
							/* code */
				}
			}

			for(j=1;j<argc;j++)//calling accoring to flag 
			{
				//flag=0;
				strcpy(temp, argv[j]);
				if (temp[0]!='-')//any file name or dir path is given
				{
							char t[2000]; //pass the path to the calld function acc to flag
							
							flag=0;

							strcpy(t,argv[j]);
							


							printf("%s\n",t);
							if (l==1)
							{
								//printf("%s\n",t );
							forl(t,l,a,indx,S,ti);
							}
							else if (indx==1&&l==0)
							{
								fori(t,l,a,indx,S,ti);/* code */
							}
							else if(a==1&&indx==0&&l==0)
							{
								fora(t,l,a,indx,S,ti);
								
							}
							else if(S==1&a==0&&indx==0&&l==0)
							{
								fors(t,l,a,indx,S,ti);
								
							}
							
							//current_path=temp;
							

				}
				if (flag==1)//only -l,a,i,s,ti given 
						
				{
					flag=0;
					if (l==1)
					{
						//printf("%s\n",current_path );
						forl(current_path,l,a,indx,S,ti);

					     
					}
					else if (indx==1&&l==0)
							{
								
								fori(current_path,l,a,indx,S,ti);/* code */
							}
							
					else if (a==1&&indx==0&&l==0)
					{
						fora(current_path,l,a,indx,S,ti);
						
					}
					else if(S==1&a==0&&indx==0&&l==0)
							{
								fors(current_path,l,a,indx,S,ti);
								
							}

				}
			}
	  	}
    }
    return 0;
}
print(char file[],int count)//works as ls with no options
{
	
	if (file[0]!='.')
	{
		printf("%s ",file );
		
	}
}
 void managemonth(int month)//doing calculation for month
 {
 	
 	if(month==0)
 	{
 		strcpy(mmonth_name,"Jan");
 		
 	}
 	if(month==1)
 	{
 		strcpy(mmonth_name,"Feb");
 	}
 	if(month==2)
 	{
 		strcpy(mmonth_name,"Mar");

 		
 	}if(month==3)
 	{
 		strcpy(mmonth_name,"Apr");

 		
 	}if(month==4)
 	{
 		strcpy(mmonth_name,"May");

 		
 	}if(month==5)
 	{
 		strcpy(mmonth_name,"June");

 		
 	}if(month==6)
 	{
 		strcpy(mmonth_name,"July");

 	}if(month==7)
 	{
 		strcpy(mmonth_name,"Aug");

 	}if(month==8)
 	{
 		strcpy(mmonth_name,"Sep");

 	}if(month==9)
 	{
 		strcpy(mmonth_name,"Oct");

 		
 	}if(month==10)
 	{
 		strcpy(mmonth_name,"Nov");

 	}if(month==11)
 	{
 		strcpy(mmonth_name,"Dec");

 	}
 
 }
forl(const char *current_path,int l,int a,int indx,int S,int ti )//this is the function manageing l flag
{ 
	
	//declarations common to fost of the function calls 
 
  struct passwd *get_userid;
 struct  group *get_group;
 

DIR *read_dir;
struct stat getdetails;
struct stat comparedetail;
struct tm *gettime;
 char buffer[PATH_MAX + 1];
 const char *absolute;
	absolute=getcwd( buffer, PATH_MAX + 1 );
 int counting, i;
	
	struct dirent **get_files;
	int x=0; long int z,y=0;
	 struct dirent *temp_get_files;
	 
	
	lstat(current_path,&getdetails);
	if ((getdetails.st_mode & S_IFMT)!=S_IFDIR)//if its not a directory then that is a file do ls-l on it
	{
		
		
			if((getdetails.st_mode & S_IFMT)==S_IFREG)
			{			//printf("%d\n",indx );
							if(indx==1)
        					{
        					   printf("%ld ",getdetails.st_ino);

        					}
							//printf( (S_ISDIR(getdetails.st_mode)) ? "d" : "-");
						    printf( (getdetails.st_mode & S_IRUSR) ? "r" : "-");
						    printf( (getdetails.st_mode & S_IWUSR) ? "w" : "-");
						    printf( (getdetails.st_mode & S_IXUSR) ? "x" : "-");
						    printf( (getdetails.st_mode & S_IRGRP) ? "r" : "-");
						    printf( (getdetails.st_mode & S_IWGRP) ? "w" : "-");
						    printf( (getdetails.st_mode & S_IXGRP) ? "x" : "-");
						    printf( (getdetails.st_mode & S_IROTH) ? "r" : "-");
						    printf( (getdetails.st_mode & S_IWOTH) ? "w" : "-");
						    printf( (getdetails.st_mode & S_IXOTH) ? "x\t" : "-\t");
						    printf("%ld ",getdetails.st_nlink);
							get_userid=getpwuid(getdetails.st_uid);
							printf("%s\t",get_userid->pw_name);
							get_group=getgrgid(getdetails.st_gid);
							printf("%s\t",get_group->gr_name);
							printf("%ld\t ",getdetails.st_size);
							gettime=localtime(&getdetails.st_mtime);
							managemonth((int)gettime[0].tm_mon);
							printf("%s\t",mmonth_name);
							printf("%d\t",gettime[0].tm_mday);
							printf("%d:%d\t",gettime[0].tm_hour,gettime[0].tm_min);
        					//printf("%s\n", get_files[0]->d_name);
							printf("%s\n",current_path );
			}
			else
			{
				printf("cannot access %s: No such file or directory \n",current_path);
			}
	}
	else {	printf("%s\n",current_path );//this means its a dir so do calculation accordingly 
		counting = scandir(current_path,&get_files,0,alphasort);			
							if (S==1)
						{
							int xx=chdir(current_path);//path of the diretory changed when user gives it
						for (i=0;i<counting-1;i++)
							{

								lstat(get_files[i]->d_name, &getdetails);
								
								y=getdetails.st_size;
								
									for (x = i+1; x < counting; x++)//computing for S flag set sorted order
									{
										lstat(get_files[x]->d_name, &getdetails);
										z=getdetails.st_size;
										
										if ( z > y)
										{
											y=z;
											
											temp_get_files=get_files[i];
											
											
											get_files[i]=get_files[x];
											
											get_files[x]=temp_get_files;
											
										}
										
									}
								}
								
						}
        					int xx=chdir(current_path);//y=strcmp(get_files[i]->d_name,"..");
							for (i = 0; i < counting; ++i)//printing accordingly 
							{
								lstat(get_files[i]->d_name, &getdetails);
								
							
        					if(get_files[i]->d_name[0]!='.'||a==1)
        					{
        						
        					if(indx==1)
        					{
        					   printf("%ld ",getdetails.st_ino);

        					}
        					printf((S_ISLNK(getdetails.st_mode))? "l" : "" );
        					printf( (S_ISDIR(getdetails.st_mode)) ? "d" : "-");
						    printf( (getdetails.st_mode & S_IRUSR) ? "r" : "-");
						    printf( (getdetails.st_mode & S_IWUSR) ? "w" : "-");
						    printf( (getdetails.st_mode & S_IXUSR) ? "x" : "-");
						    printf( (getdetails.st_mode & S_IRGRP) ? "r" : "-");
						    printf( (getdetails.st_mode & S_IWGRP) ? "w" : "-");
						    printf( (getdetails.st_mode & S_IXGRP) ? "x" : "-");
						    printf( (getdetails.st_mode & S_IROTH) ? "r" : "-");
						    printf( (getdetails.st_mode & S_IWOTH) ? "w" : "-");
						    printf( (getdetails.st_mode & S_IXOTH) ? "x " : "- ");
						    printf("%ld ",getdetails.st_nlink);
							get_userid=getpwuid(getdetails.st_uid);
							printf("%s\t",get_userid->pw_name);
							get_group=getgrgid(getdetails.st_gid);
							printf("%s\t",get_group->gr_name);
							printf("%ld\t ",getdetails.st_size);
							gettime=localtime(&getdetails.st_mtime);
							managemonth((int)gettime[0].tm_mon);
							printf("%s\t",mmonth_name);
							printf("%d\t",gettime[0].tm_mday);
							printf("%d:%d\t",gettime[0].tm_hour,gettime[0].tm_min);
        					printf("%s\n", get_files[i]->d_name);
        					}
        					
							}	
												  
					    printf("\n");
		}int xx=chdir(absolute);

}
fori(const char *current_path,int l,int a,int indx,int S,int ti )
{
	
struct stat getdetails;
 char buffer[PATH_MAX + 1];
 const char *absolute;
absolute=getcwd( buffer, PATH_MAX + 1 );
struct dirent **get_files;
struct dirent *temp_get_files;
lstat(current_path,&getdetails);
int counting,i,x;
long int y,z;
	if ((getdetails.st_mode & S_IFMT)==S_IFDIR)
	{
	counting = scandir(current_path,&get_files,0,alphasort);			
		if (S==1)
		{
			int xx=chdir(current_path);
			for (i=0;i<counting-1;i++)
							{

								lstat(get_files[i]->d_name, &getdetails);
								y=getdetails.st_size;
								
									for (x = i+1; x < counting; x++)
									{
										lstat(get_files[x]->d_name, &getdetails);
										z=getdetails.st_size;
										
										if ( z > y)
										{
											y=z;
											
											temp_get_files=get_files[i];
											get_files[i]=get_files[x];
											
											get_files[x]=temp_get_files;
											
										}
										
									}
							}

		}
		int xx=chdir(current_path);
			for (i = 0; i < counting; ++i)
							{

								lstat(get_files[i]->d_name, &getdetails);
								
							
        					if(get_files[i]->d_name[0]!='.'||a==1)
        					{
        						
        					if (indx==1)
        					{
        					   printf("%ld ",getdetails.st_ino);
        					   printf("%s\t", get_files[i]->d_name);
        					 }

        					
        				}
        			}
	}printf("\n");
int xx=chdir(absolute);
}

fora(const char *current_path,int l,int a,int indx,int S,int ti )
{
	//printf("in %s \n",current_path );
struct stat getdetails;
 char buffer[PATH_MAX + 1];
 const char *absolute;
absolute=getcwd( buffer, PATH_MAX + 1 );
struct dirent **get_files;
struct dirent *temp_get_files;
lstat(current_path,&getdetails);
int counting,i,x;
long int y,z;
	if ((getdetails.st_mode & S_IFMT)==S_IFDIR)
	{
	counting = scandir(current_path,&get_files,0,alphasort);			
		if (S==1)
		{
			int xx=chdir(current_path);
			for (i=0;i<counting-1;i++)
							{

								lstat(get_files[i]->d_name, &getdetails);
								y=getdetails.st_size;
								
									for (x = i+1; x < counting; x++)
									{
										lstat(get_files[x]->d_name, &getdetails);
										z=getdetails.st_size;
										
										if ( z > y)
										{
											y=z;
											
											temp_get_files=get_files[i];
											get_files[i]=get_files[x];
											
											get_files[x]=temp_get_files;
											
										}
										
									}
							}

		}
		int xx=chdir(current_path);
			for (i = 0; i < counting; ++i)
							{

								lstat(get_files[i]->d_name, &getdetails);
								 printf("%s\t", get_files[i]->d_name);
							}
							printf("\n");
}	int xx=chdir(absolute);		
}
fors(const char *current_path,int l,int a,int indx,int S,int ti )
{
	
struct stat getdetails;
 char buffer[PATH_MAX + 1];
 const char *absolute;
absolute=getcwd( buffer, PATH_MAX + 1 );
struct dirent **get_files;
struct dirent *temp_get_files;
lstat(current_path,&getdetails);
int counting,i,x;
long int y,z;
	if ((getdetails.st_mode & S_IFMT)==S_IFDIR)
	{
	counting = scandir(current_path,&get_files,0,alphasort);			
		if (S==1)
		{
			int xx=chdir(current_path);
			for (i=0;i<counting-1;i++)
							{

								lstat(get_files[i]->d_name, &getdetails);
								y=getdetails.st_size;
								
									for (x = i+1; x < counting; x++)
									{
										lstat(get_files[x]->d_name, &getdetails);
										z=getdetails.st_size;
										
										if ( z > y)
										{
											y=z;
											
											temp_get_files=get_files[i];
											get_files[i]=get_files[x];
											
											get_files[x]=temp_get_files;
											
										}
										
									}
									if(get_files[i]->d_name[0]!='.')
        							{
									printf("%s\t", get_files[i]->d_name);
									}
							}

		}
	}	int xx=chdir(absolute);
}