/*************************************************************************** */ 
//Author: Vincent Vassallo
//Filename: finfo.c
//Section: 111
//Description: File to perform Information Maintenance System Calls
//************************************************************************** */
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[]) {
    struct timespec current;    
    struct utsname buffer;
    

    //Time in nanoseconds
    //Get time since epoch in struct
    clock_gettime(CLOCK_REALTIME, &current); 
    //Put time in nanoseconds
    long time = ((current.tv_sec)*1000000000) + current.tv_nsec;
    //Separate out the hours, minutes, seconds, and nanoseconds
    time = time % 86400000000000;
    printf("Current time in nanoseconds: %ld\n\n", time);
    
    //Network, System, Release, Version Name and Hardware Type
    char name[30];
    //Putting the name of the network in the string
    gethostname(name, sizeof(name));
    printf("Network Name: %s\n", name);
    
    //Uname fills the struct
    if(uname(&buffer) == 0) {
        //Getting information from the struct
        printf("System Name: %s\n", buffer.sysname);
        printf("Release: %s\n", buffer.release);
        printf("Version: %s\n", buffer.version);
        printf("Hardware Type: %s\n\n", buffer.machine);
    }

    //Number of Processors
    printf("Number of Processors: %d\n\n", get_nprocs());

    //Memory
    //Getting pages of memory and multiplying it by bytes per page for total bytes
    long memory = sysconf(_SC_PHYS_PAGES) * getpagesize();
    long amemory = sysconf(_SC_AVPHYS_PAGES) * getpagesize();
    
    printf("Total Memory in Bytes: %ld\n", memory);
    printf("Total Available Memory in Bytes: %ld\n\n", amemory);

    return 0;
}