//libraries used
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

//helper methods (unnamed so far)
void recursiveFind(char *startingPath, char *enterPattern, size_t size){
    char currentDIR[] = ".";
    char prevDIR[] = "..";
    DIR *dir = opendir(startingPath);
    struct dirent *datapath;
    size_t i = strlen(startingPath);
    char *tag;

    if(dir == NULL){//if dir cannot open, exit
        fprintf(stderr, "No file found in directory: %s, %s\n", startingPath,strerror(errno));
        return;
    }
    while((datapath = readdir(dir)) != NULL){
        tag = datapath ->d_name;
        if(datapath ->d_type == DT_DIR){
            if(!strcmp(tag, currentDIR) || !strcmp(tag, prevDIR)){
                continue;
            }
            else{
                startingPath[i] = '/';
                strcpy(startingPath + i + 1, tag);
                if(strstr(startingPath,enterPattern) != NULL){
                    printf("%s\n", startingPath);
                }
                    recursiveFind(startingPath,enterPattern,size);
                    startingPath[i] = '\0';
            }
        }
        else{
            if(strstr(tag, enterPattern) != NULL){
                printf("%s/%s\n",startingPath,tag);
            }
        }
    }
    closedir(dir); //closes directory
}
    

//main method
int main(int argc, char *argv[]){
    //variables
    char path[1024] = ".";
    char *pattern = argv[1];
    //commands
    recursiveFind(path, pattern, sizeof path); //calls function above.
    return 0;
    
}
