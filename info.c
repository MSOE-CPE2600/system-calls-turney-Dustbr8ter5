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
    long time = ((current.tv_sec)*1000000000) + current.tv_nsec;
    time = time % 86400000000000;
    printf("Current time in nanoseconds: %ld\n\n", time);
    
    //Network, System, Release, Version Name and Hardware Type
    char name[30];
    gethostname(name, sizeof(name));
    printf("Network Name: %s\n", name);

    if(uname(&buffer) == 0) {
        printf("System Name: %s\n", buffer.sysname);
        printf("Release: %s\n", buffer.release);
        printf("Version: %s\n", buffer.version);
        printf("Hardware Type: %s\n\n", buffer.machine);
    }

    //Number of Processors
    printf("Number of Processors: %d\n\n", get_nprocs());

    //Memory
    long memory = sysconf(_SC_PHYS_PAGES) * getpagesize();
    long amemory = sysconf(_SC_AVPHYS_PAGES) * getpagesize();
    
    printf("Total Memory in Bytes: %ld\n", memory);
    printf("Total Available Memory in Bytes: %ld\n\n", amemory);

    return 0;
}