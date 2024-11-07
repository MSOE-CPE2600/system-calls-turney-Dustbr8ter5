/*************************************************************************** */ 
//Author: Vincent Vassallo
//Filename: finfo.c
//Section: 111?
//Description: File to perform Information Maintenance System Calls
//************************************************************************** */
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    struct timespec current;    

    clock_gettime(CLOCK_REALTIME, &current);
    long time = ((current.tv_sec)*1000000000) + current.tv_nsec;
    time = time % 86400000000000;
    printf("Current time in nanoseconds: %ld\n", time);

    



    return 0;
}