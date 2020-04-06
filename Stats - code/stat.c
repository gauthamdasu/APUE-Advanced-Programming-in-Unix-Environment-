#include<stdio.h>
#include"apue.h"
#include<sys/stat.h>
int main(int argc,char *argv[])
{

  int i=0;
  struct stat buf;
  char *p=NULL;

if (argv[1]==NULL)
	printf("Please enter the filename:\n");
else{
  for (i = 1; i < argc; i++) 
  {
  printf("%s: ", argv[i]);
  if (lstat(argv[i], &buf) < 0) 
  {
  err_ret("lstat error"); 
  }
  
if (S_ISREG(buf.st_mode)) //TYPES OF FILE
 p = "The file is of type regular";
  
    else if (S_ISDIR(buf.st_mode))
 p = "The file is of type directory ";
  
    else if (S_ISCHR(buf.st_mode))
      p = "The file is character special";
 
     else if (S_ISBLK(buf.st_mode))
      p = "The file is block special";

      else if (S_ISFIFO(buf.st_mode))
      p = "The file is fifo";

      else if (S_ISLNK(buf.st_mode))
      p = "The file is symbolic link";

      else if (S_ISSOCK(buf.st_mode))
      p = "socket";

      else
      p = "file not known";
      printf("%s\n", p);
  printf("The i-node no is :%lu\n",buf.st_ino);
  printf("The device number is :%lu\n",buf.st_dev);
  printf("The device number for special files is :%lu\n",buf.st_rdev);
  printf("The number of links are :%lu\n",buf.st_nlink);
  printf("The user id of the owner is :%ld\n",buf.st_uid);
  printf("The group id is :%lu\n",buf.st_gid);
  printf("The size in bytes, for regular files is :%lu\n",buf.st_size );
    }

      exit(0);
}
}     



