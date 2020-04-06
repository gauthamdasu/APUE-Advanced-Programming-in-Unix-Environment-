#include <errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "apue.h"
#include<string.h>
#include<time.h>
#define maxi 20

int main(int argc, char * argv[])
  {
	char name[20],numb[20],nam[20];
	char entry[100];
	int size,ch=10,ent;
	int fd,fd1,i=0,l3=0;
	time_t t;
        struct tm * timeinfo;
	system("clear");
	//fd-for the user and fd1 for the log file.
	//first we create a log file and write into it.
	fd1=(openat(AT_FDCWD,"Logfile.txt",O_RDWR|O_CREAT|O_APPEND,0644));//creating a file if not existing for reading and writing the file
		/*write (fd,"helloworld",20);
		read (fd,nam,20);
		printf("Name of the entry: %s\n ",nam);				
		*/	
	while(ch!=0)
  {	
	printf("			Please enter the name of the file to be created..\nName::");
	scanf("%s",name);
	if((fd=(openat(AT_FDCWD, name,O_RDWR|O_CREAT|O_EXCL,0644)))==-1)//creating a file if not existing for reading and writing the file
		printf("File already exists give another name\n");         //giving permissions for the file to be opened.
	else
	{	printf("Please enter the no. of entries you want in the telbook\n");	
		scanf("%d",&size);
		if (size>maxi)
		printf("Entries number excceded the maximum value......\nPlease enter the value less than 20.\n");	
		else
		{//write the time at which the file is opened
		printf("File(Telbook) with Name::%s created with %d entries in it.\n",name,size);
 		time(&t);
                timeinfo = localtime(&t);                    			
		strcat(entry,"Opened File: ");
		strcat(entry,name);
		strcat(entry,"  ");
                strcat(entry,asctime(timeinfo));
                write(fd1,entry,strlen(entry));
                write(fd1,"\n",1);
		}    
	while(ch!=0) 
      {		
	printf("\n\n                   Enter the choice \n1.To Read the entries of the Telbook\n2.To write in Telbook\n0.To exit...\n");	
		scanf("%d",&ch);
				switch(ch)
				{
			
					case 1 : printf("Please enter the location for the entry\n");
						scanf("%d",&ent);
						if (ent>maxi || ent>size)
							{printf("entry size exceeded !......\n");
							break;
							}
														
						lseek (fd,((ent-1)*40),SEEK_SET);//move to the desired location.	  
						if(read (fd,nam,20)>0)
							{
						read (fd,numb,20);
						l3=strlen(numb);
						printf("Name of the entry:%s\nPhone No.: %s\n ",nam,numb);						}
						else if (l3==0){
							printf("No entries in the current location in telbook.Please enter the values....\n");
							break;//ch=0;
							}	
					//If a read occurs then write that in the file
					time(&t);
                     			timeinfo = localtime(&t);                    			
					strcat(entry,"Read File: ");
					strcat(entry,name);	
					strcat(entry,"  ");                                    			
					strcat(entry,asctime(timeinfo));
                    			write(fd1,entry,strlen(entry));
                    			write(fd1,"\n",1);
						break;
			
					case 2:printf("Please enter the location for the entry\n");
						scanf("%d",&ent);
						if (ent>maxi || ent>size)
							{printf("entry size exceeded....!\n");
							break;	}								
						lseek (fd,((ent-1)*40),SEEK_SET);//move to the desired location.	
						printf("Enter the name(not more than 20 chars)::\n");scanf("%s",nam);
						printf("Enter the no.(not more than 20 chars)::\n");scanf("%s",numb);
							if(write (fd,nam,20)!=-1)
								write (fd,numb,20);
							//if (lseek(fd, 20, SEEK_CUR) == -1) /* offset now = 40 */
									//perror("lseek");
							   printf("File wirtten succesfully in location %d\n",ent);			
						time(&t);
 	                    			timeinfo = localtime(&t);                    			
						strcat(entry,"Written into: ");
						strcat(entry,name);
        	             			strcat(entry,"  ");
                				strcat(entry,asctime(timeinfo));
        	            			write(fd1,entry,strlen(entry));
        	            			write(fd1,"\n",1);					          
						break;
					 
				}			

	
//	printf("%s",name);

	//close the opened file
	 }	
	}
	close(fd);
}













   }
