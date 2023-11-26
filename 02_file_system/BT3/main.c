#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main()
{

   int fd;
   struct stat infor;
   char str1[12] = "Tuan TNT19 ";
   char str2[14] = "Rat dep trai\n";
   fd = open("test.txt",O_RDWR | O_CREAT,0666);
   if (fd ==-1)
    {
      printf("Can not open file \n");
    }
   int w,w1;
   lseek(fd,0,SEEK_SET);
   w=write(fd,str1,strlen(str1));
   if (w==-1)
    {
      printf("Can not write 1\n");
    }
   lseek(fd,11,SEEK_SET);
   w1=write(fd,str2,strlen(str2));
   if (w1==-1)
    {
      printf("Can not write 2\n");
    }
   int check = stat("test.txt",&infor);
   if (check==0)
    {
      printf("Type: ");
      switch (infor.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }
      printf("Last modify Time : %s",ctime(&infor.st_mtime));
      printf("Size : %ld\n",infor.st_size);
     }
   close(fd);
   return 0;
}