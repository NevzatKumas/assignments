//libraries used
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


//helper methods (unnamed so far)
void recursiveFileSearch(char *startingpath){
    int *myPointer; //cleared up my segmentation fault
    myPointer = malloc(sizeof(int)); //tbh this cleared up my segmentation fault so idk
    char path[500]; //allocating memory for files list.
    struct dirent *datapath;
    DIR *dir = opendir(startingpath);

    if(!dir){
        return; //if dir cannot open.
    }
    while((datapath = readdir(dir)) != NULL){
        if(strcmp(datapath->d_name, ".") !=0 && strcmp(datapath->d_name, "..") !=0){
            printf("%s\n", datapath ->d_name);

            strcpy(path,startingpath);
            strcat(path,"/");
            strcat(path, datapath ->d_name);
        }
    }
    free(myPointer); //frees up memory
    closedir(dir); //closes directory
}

//main method
int main(int argc, char *argv[]){
    char enterPattern[] = "Please enter pattern into command line: "; //tells user to input
    char pattern[10]; //allocating memory for amount of char's in "pattern".
    printf("%s", enterPattern); //printing enterPattern[].
    scanf("%s", argv[1]); // taking input from command line
    recursiveFileSearch(argv[1]); //calls function above.
    return 0;
}