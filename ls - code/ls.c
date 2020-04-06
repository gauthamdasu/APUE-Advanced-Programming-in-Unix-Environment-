//replication of ls command written by gautham 16006.
//takes two arguments combined arguments also
//usage : ./ls command 
//example : ./ls -a
#include "apue.h"
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include<time.h>
//#include<stdlib>   	
int count(DIR *dp,char *fulpath);
void disp_dir(char *fulpath);
int totals(DIR *dp,char *ful_path);
int disp_inode(DIR *dp,char *ful_path);
char *userNameFromId(uid_t uid);
char *groupNameFromId(gid_t gid);
void print_sorted(char *fulpat);
char ** get_file(char *fulpaths);
int modified=0;
int aflag=0;
int Aflag=0;
int iflag=0;
int lflag=0;
int nflag=0;
int Rflag=0;
int dflag=0;
int sflag=0;
int tflag=0;
int cflag=0;
int total=0;
     struct m_node
    {
        char filename[40];
        int m_time;
    };   
    //struct m_node m_node[50];
      
struct c_node
{
 char filename[40];
 int c_time;
};
//struct c_node nod[50];

struct filenode
{
char filename[40];
};

int main(int argc, char *argv[])
{
int cnt=0;
int po=0;
unsigned mtime,ctim;
int choice=0,opt=0;
int ntimes=0;
int total=0;
char opndir[1000];
struct dirent **fileList;
int n=0,i=0;//no fo files
DIR *dp;
char time[25],time1[25],**files_in; 
char curdir[1000],ch[2];
struct stat fileStat;
struct dirent *dirp;
/*
printf("%s",argv[0]);
printf("%s",argv[1]);
printf("%s",argv[2]);
printf("%s",argv[3]);
printf("\n%d",argc);
*/
//if (argc<2)
	if (strcmp(argv[2],"XDG_VTNR=7")==0)
		strcpy(opndir,"./");
else
	strcpy(opndir,argv[2]);

printf("%s",opndir);
if ((dp = opendir(opndir)) == NULL)//open the directory given in args
	err_sys("can’t open %s", opendir);
//printf("argv[1]:%s",argv[1]);
//read dir and print list of names in dir
	//printf("%d",(strcmp(dirp->d_name,".")!=0)); //&& (strcmp(dirp->d_name,"..")==0))
	//printf("\n");
	//give cases for each of the ls commands
 char fullpath[100]; //To get the current working directory:
      if(getcwd(fullpath ,sizeof(fullpath))!=NULL)
       {
         
       } 
       else
       {
        exit(1);
       }
//printf("%s",fullpath);
//if (argv[1]!=NULL)
		if(argv[1]==NULL)
			//strcpy(ch,argv[1]);//copy arguments to a char array 			
			/*{	while ((dirp = readdir(dp)) != NULL)
     			{	if(!strcmp(dirp->d_name,".")==0)
			      if(!strcmp(dirp->d_name,"..")==0)	
								
				printf("%s ", dirp->d_name);
			}	
			printf("\n");
			}*/
			print_sorted(fullpath);
	while ((opt = getopt (argc, argv, "saliAcdnRt")) != -1)
 	 {	  
  	switch(opt)
     	     {		
	
 	case 'a':if (aflag==0)// && !(lflag==0))	
			disp_dir(fullpath);
		     aflag=1;				
			break;
	case 'l': if (lflag==0)	
		{total=totals(dp,fullpath);
		printf("total %d\n",total);
		//closedir(dp);
		//dp = opendir("./");	 
		/*while ((dirp = readdir(dp)) != NULL)
		{	//printf("total %d\n",total);
		
		   if(!strcmp(dirp->d_name,".")==0)
		     if(!strcmp(dirp->d_name,"..")==0)	
			{		
			strcpy(curdir,fullpath);
			strcat(curdir,"/");
			strcat(curdir,dirp->d_name);
		  */
		
		n=scandir(fullpath, &fileList, NULL, alphasort);//scan the directory using scandir and sorting while reading .
			for (int i = 0; i < n; i++) //for the filelist print and free the structure.
			  	{
			if(!strcmp(fileList[i]->d_name,".")==0)
				     if(!strcmp(fileList[i]->d_name,"..")==0)
			{//	printf("%s  ",fileList[i]->d_name);
		  	
		  	
			//printf("\n");
			//	
			    strcpy(curdir,fullpath);
			    strcat(curdir,"/");
			    strcat(curdir,fileList[i]->d_name);
			
		  if (lstat(curdir, &fileStat) < 0) 
			err_ret("lstat error");
		    printf( (S_ISDIR(fileStat.st_mode)) ?  "d" : "-");	    
		    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
		    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
		    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
		    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
		    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
		    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
		    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
		    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
		    printf(" %zu ",fileStat.st_nlink);
		    printf("%s ",userNameFromId(fileStat.st_uid));//user id
                    printf("%s ",groupNameFromId(fileStat.st_gid));//group id 
                    printf("%-5zu ",fileStat.st_size);//File size
                    strcpy(time,ctime(&fileStat.st_mtim.tv_sec));
                    time[strlen(time)-1]='\0';
		    free(fileList[i]);
		    //printf("%s ",ctime(&fileStat.st_mtim));//Last modification time 
   		    printf("%5s ",time);//Last modification time 
   		    printf("%-10s  \n", fileList[i]->d_name);				
			}
		}
		free(fileList);
		}
			lflag=1;		
			break;
	
	case 'i' :if (iflag==0)	
			disp_inode(dp,fullpath);
			//printf("File inode: \t\t%zu\n",fileStat.st_ino);
		    iflag=1;
			break;
		
	case 's' :	//printf("dasdasadasd***********");
			if (sflag==0)				
			{while ((dirp = readdir(dp)) != NULL)
			{	
				//printf("*****");
				if(!strcmp(dirp->d_name,".")==0)
				     if(!strcmp(dirp->d_name,"..")==0)	
				{		
				strcpy(curdir,fullpath);
				strcat(curdir,"/");
				strcat(curdir,dirp->d_name);
			
				if (stat(curdir, &fileStat) < 0) 
					err_ret("lstat error");
					 printf("%zu ",fileStat.st_size);
					 printf("%s ", dirp->d_name);							   
					    }
			
			}
			printf("\n");
			}
				sflag=1;
			break;
	
	case 'R'://recursively print the file names.
		cnt=scandir(fullpath, &fileList, NULL, alphasort);//scan the directory using scandir and sorting while reading .(fullpath);
		for ( i = 0; i <cnt; i++) //for the filelist print and free the structure.
	  	{
		     if(!strcmp(fileList[i]->d_name,"..")==0)
			{
				strcpy(curdir,fullpath);
				strcat(curdir,"/");
				strcat(curdir,fileList[i]->d_name);					
				if (stat(curdir, &fileStat) < 0) 
					err_ret("lstat error");
				if(S_ISDIR(fileStat.st_mode))
				{
				curdir[0]='\0';				
				strcpy(curdir,"./");	
				strcat(curdir,fileList[i]->d_name);	
				printf("%s:\n",curdir);
				disp_dir(curdir);			
				}
 			}
				curdir[0]='\0';
			  	free(fileList[i]);
		}
			//printf("\n");
			free(fileList);	
			//printf("\n");
			break;	
	
	default	:	
		 while ((dirp = readdir(dp)) != NULL)
     		{	
		 	
   		      if(!strcmp(dirp->d_name,".")==0)
			      if(!strcmp(dirp->d_name,"..")==0)	
				printf("%s ", dirp->d_name);
  		 }
		//printf("\n");	
	    }
	modified=1;
}	
closedir(dp);

exit(0);

}


void disp_dir(char *fulpath)//function to display all files in the directory including .. and .
{
struct dirent **fileList;
int n=0;//no fo files
n=scandir(fulpath, &fileList, NULL, alphasort);//scan the directory using scandir.
for (int i = 0; i < n; i++) //for the filelist print and free the structure.
  	{ if(!strcmp(fileList[i]->d_name,".")==0)
		     if(!strcmp(fileList[i]->d_name,"..")==0)	
		
	printf("%s  ",fileList[i]->d_name);
  	free(fileList[i]);
  	}
printf("\n");
free(fileList);		
}



int disp_inode(DIR *dp,char *ful_path)
{
struct stat fileStat;
struct dirent *dirp;
int count=0;
int totl=0;
char curdir[1000];
while ((dirp = readdir(dp)) != NULL)
		{	count++;
		   if(!strcmp(dirp->d_name,".")==0)
		     if(!strcmp(dirp->d_name,"..")==0)	
			{		
			strcpy(curdir,ful_path);
			strcat(curdir,"/");
			strcat(curdir,dirp->d_name);
		    if (stat(curdir, &fileStat) < 0) 
			err_ret("lstat error");
		    //printf("Information for %s\n",argv[1]);
		printf("%zu\t%s\t",fileStat.st_ino,dirp->d_name);
		if ((count%6)==0)
			printf("\n");
		  	}
		}		    
return totl;
}

int totals(DIR *dp,char *ful_path)
{
struct stat fileStat;
struct dirent *dirp;
int totl=0;
char curdir[1000];
while ((dirp = readdir(dp)) != NULL)
		{	
		   if(!strcmp(dirp->d_name,".")==0)
		     if(!strcmp(dirp->d_name,"..")==0)	
			{		
			strcpy(curdir,ful_path);
			strcat(curdir,"/");
			strcat(curdir,dirp->d_name);
		    if (stat(curdir, &fileStat) < 0) 
			err_ret("lstat error");
		    //printf("Information for %s\n",argv[1]);
		    //printf("%zu ",fileStat.st_blocks);
		  totl+=fileStat.st_blocks;	}
		}		    
return totl/2;
}



char *userNameFromId(uid_t uid)
                   {
                   struct passwd *pwd;
                   pwd = getpwuid(uid);
                    return (pwd == NULL) ? NULL : pwd->pw_name;
                    
                     }
                
/* Return name corresponding to 'gid', or NULL on error */
char *   groupNameFromId(gid_t gid)
                  {
                   struct group *grp;
                   grp = getgrgid(gid);
                     return (grp == NULL) ? NULL : grp->gr_name;
                  }


char ** get_file(char *fulpaths)
{
struct dirent **fileList;
int n=0;//no fo files
n=scandir(fulpaths, &fileList, NULL, alphasort);//scan the directory using scandir and sorting while reading .
char **files=malloc(n*sizeof(char));
for (int i = 0; i < n; i++) //for the filelist print and free the structure.
  	{
	strcpy(files[i],fileList[i]->d_name);
	printf("%s  ",fileList[i]->d_name);
  	free(fileList[i]);
  	}
printf("\n");
free(fileList);	
return files;
}


void print_sorted(char *fulpat)
{
struct dirent **fileList;
int n=0;//no fo files
n=scandir(fulpat, &fileList, NULL, alphasort);//scan the directory using scandir and sorting while reading .
for (int i = 0; i < n; i++) //for the filelist print and free the structure.
  	{
	if(!strcmp(fileList[i]->d_name,".")==0)
		     if(!strcmp(fileList[i]->d_name,"..")==0)
		printf("%s  ",fileList[i]->d_name);
  	free(fileList[i]);
  	}
printf("\n");
free(fileList);	
}


int count(DIR *dp,char *fulpath)
{
int total=0;
char curdir[1000],ch[2];
struct stat fileStat;
struct dirent *dirp,** fileList;
//char;
int noOfFiles;
noOfFiles = scandir(fulpath, &fileList, NULL, alphasort);
printf("total:%d",noOfFiles);
for (int i = 0; i < noOfFiles; i++)
  {
printf("%s\n",fileList[i]->d_name);
  free(fileList[i]);
  }
free(fileList);		
return total;
}

