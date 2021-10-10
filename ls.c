#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include<stdlib.h>
int main (int argc, char *argv[]){
   
    struct dirent **datapath;
    int n;
    int i=3;
    n = scandir(".", &datapath,NULL,alphasort);

    if (n < 0)
      perror("scandir");
   else {
      while (i<n) {
         printf("%s\n", datapath[i]->d_name);
         free(datapath[i]);
         ++i;
      }
      free(datapath);
   }
 return 0;
}