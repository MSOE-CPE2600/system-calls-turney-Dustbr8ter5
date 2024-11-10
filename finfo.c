/*************************************************************************** */ 
//Author: Vincent Vassallo
//Filename: finfo.c
//Section: 111
//Description: Program to retrieve info on a file
//************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if(argc != 2) { //Check for proper command line format
        return 1;
    }
    struct stat filestat; //Declare structure
    if(stat(argv[1], &filestat) == 0) { //Set structure to file

        //Check for type of file
        if (S_ISREG(filestat.st_mode)) {
            printf("File type: Regular file\n");
        } else if (S_ISDIR(filestat.st_mode)) {
            printf("File type: Directory\n");
        } else if (S_ISCHR(filestat.st_mode)) {
            printf("File type: Character device\n");
        } else if (S_ISBLK(filestat.st_mode)) {
            printf("File type: Block device\n");
        } else if (S_ISFIFO(filestat.st_mode)) {
            printf("File type: FIFO (named pipe)\n");
        } else if (S_ISLNK(filestat.st_mode)) {
            printf("File type: Symbolic link\n");
        } else if (S_ISSOCK(filestat.st_mode)) {
            printf("File type: Socket\n");
        } else {
            printf("File type: Unknown\n");
        }

        //Use bitwise operations to determine permissions
        printf("File Permissions:\n");

        //Owner Permissions
        printf("Owner: ");
        if (filestat.st_mode & S_IRWXU) {
            printf("Read, Write, Execute");
        } else if (filestat.st_mode & S_IRUSR) {
            printf("Read");
        } else if (filestat.st_mode & S_IWUSR) {
            printf("Write");
        } else if (filestat.st_mode & S_IXUSR) {
            printf("Execute");
        } else {
            printf("None");
        }
        printf("\nGroup: ");

        //Group permissions
        if(filestat.st_mode & S_IRWXG) {
            printf("Read, Write, Execute");
        } else if (filestat.st_mode & S_IRGRP) {
            printf("Read");
        } else if (filestat.st_mode & S_IWGRP) {
            printf("Write");
        } else if (filestat.st_mode & S_IXGRP) {
            printf("Execute");
        } else {
            printf("None");
        }
        printf("\nOthers: ");

        //Others permissions
        if(filestat.st_mode & S_IRWXO) {
            printf("Read, Write, Execute\n");
        } else if (filestat.st_mode & S_IROTH) {
            printf("Read\n");
        } else if (filestat.st_mode & S_IWOTH) {
            printf("Write\n");
        } else if (filestat.st_mode & S_IXOTH) {
            printf("Execute\n");
        } else {
            printf("None\n");
        }

        //Owner ID
        printf("Owner ID: %d\n", filestat.st_uid);

        //Size of file
        printf("Size in Bytes: %ld\n", filestat.st_size);

        //Last modified date
        printf("Last Modified Date: %s\n", asctime(localtime(&filestat.st_mtim.tv_sec)));
        
    } else {
        perror("Invalid Filename or File DNE\n");
        return 1;
    }

    return 0;
}