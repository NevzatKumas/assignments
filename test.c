#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<pwd.h>
int main (int argc, char *argv[]){
   
    struct dirent **datapath;
    struct stat filestat;
    struct passwd *pw;
    
    int n;
    int i=3;
    n = scandir(".", &datapath,NULL,alphasort);
    //stat(n,&filestat);
    
    if (n < 0)
      perror("scandir");
   else {
      while (i<n) {
         stat(datapath[i]->d_name, &filestat);
         printf("%s\n", datapath[i]->d_name);
         printf("%s", ctime(&filestat.st_mtime));
         
         free(datapath[i]);
         ++i;
      }
      free(datapath);
   }
 return 0;
}