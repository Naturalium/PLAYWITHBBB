#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
  DIR *dirp;
  struct dirent *dentry;
  if((dirp = opendir("test_dir1")) == NULL)
    {
      fprintf(stderr, "Error on opening directiory test_dir1\n");
      exit(1);
    }
  while(dentry = readdir(dirp))
  {
    if(dentry->d_ino != 0)
      printf("%s\n", dentry->d_name);
  }

  closedir(dirp);
}
