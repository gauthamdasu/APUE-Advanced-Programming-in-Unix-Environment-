#include "apue.h"
#include "error.c"

int main(int argc, char *argv[])
{
int i;
struct stat buf;
char *ptr;
if (argv[1]==NULL)
	printf("Please enter the filename:\n");
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
  printf("The i-node no is st_ino:%lu\n",buf.st_ino);
  printf("The device number is st_dev:%lu\n",buf.st_dev);
  printf("The device number for special files is st_rdev:%lu\n",buf.st_rdev);
  printf("The number of links are st_nlink:%lu\n",buf.st_nlink);
  printf("The user id of the owner is st_uid:%ld\n",buf.st_uid);
  printf("The group id is st_gid:%lu\n",buf.st_gid);
  printf("The size in bytes, for regular files is st_size:%lu\n",buf.st_size );
  printf("The time of last access is st_atim:%s",ctime(&buf.st_atim));
  printf("The time of last modification is st_mtim:%s",ctime(&buf.st_mtim));
  printf("The time of last file status changest_ctim:%s",ctime(&buf.st_ctim));
  printf("The I/O block size is st_blksize:%lu\n",buf.st_blksize);
  printf("The no of disk blocks allocated is st_blocks:%lu\n\n",buf.st_blocks); 
    }
      exit(0);
}     

