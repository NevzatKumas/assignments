#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <pwd.h>

int main (int argc, char *argv[]){
   if(argc==2 && strcmp(argv[1], "-l") == 0){
    struct dirent **datapath;
    struct stat filestat;
    struct group* gr;
    struct passwd *ui;
    uid_t uid=0;
   
    int n;
    int i=3;
    n = scandir(".", &datapath,NULL,alphasort);
    long int size;
    
    if( ( gr = getgrgid( getgid() ) ) == NULL ) {
        return( EXIT_FAILURE );
         }
     if ((ui = getpwuid(uid)) == NULL){
        return( EXIT_FAILURE );
     }
    if (n < 0)
      perror("scandir");
   else {
      while (i<n) {
         stat(datapath[i]->d_name, &filestat);
         size = filestat.st_size;

    printf( (filestat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (filestat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (filestat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (filestat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (filestat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (filestat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (filestat.st_mode & S_IROTH) ? "r" : "-");
    printf( (filestat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (filestat.st_mode & S_IXOTH) ? "x" : "-");
         printf(" %s %s %ld %.19s %s\n",ui->pw_name, gr->gr_name, size, ctime(&filestat.st_mtime), datapath[i]->d_name);         
         
         free(datapath[i]);
         ++i;
      }
      free(datapath);
   }
   }else{

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
   }
 return 0;
}
