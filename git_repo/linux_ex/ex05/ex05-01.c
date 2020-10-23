#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>

int main()
{
    char buffer[256];
    DIR *dirp;
    struct dirent *dentry;

    getcwd(buffer, 256);
    printf("%s\n", buffer);

    mkdir("apple", 0755);
    mkdir("banana", 0755);

    chdir("apple");
    getcwd(buffer, 256);
    printf("%s\n", buffer);

    close(open("test.txt", O_CREAT | O_RDWR, 0644));

    chdir("..");

    rmdir("apple");
    rmdir("banana");

    dirp = opendir("apple");

    while(dentry = readdir(dirp))
      if(dentry->d_ino != 0)
	  printf("%s\n", dentry->d_name);
    
    rewinddir(dirp);

    while(dentry = readdir(dirp))
      if(dentry->d_ino != 0)
	      printf("%s\n", dentry->d_name);

    closedir(dirp);
}
