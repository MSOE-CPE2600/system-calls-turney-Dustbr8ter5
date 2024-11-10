/*************************************************************************** */ 
//Author: Vincent Vassallo
//Filename: pmod.c
//Section: 111
//Description: File to retrieve process information
//************************************************************************** */
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    struct timespec ts; //Declare struct
    ts.tv_sec = 1; //Set seconds
    ts.tv_nsec = 837272638; //Set nanoseconds
    nice(10); //Reduce priotity by 10
    nanosleep(&ts, NULL); //Sleep for the time in the struct, no remainder needed
    printf("Sleep finished: Goodbye\n"); //Print exit message
    return 0;
}