/*************************************************************************** */ 
//Author: Vincent Vassallo
//Assignment: Lab 9 System Calls
//Filename: pinfo.c
//Section: 111
//Description: File to retrieve process information
//************************************************************************** */
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char* argv[]) {
    pid_t pid;
    int method;
    switch (argc) {
        case 1: //If there is no input
            pid = getpid(); //Get default pid
            if(kill(pid, 0) != 0) { //Check pid
                printf("Pid does not exist\n");
                break;
            }
            //Get and print priority
            printf("Process Priority: %d\n", getpriority(PRIO_PROCESS, pid));
            //Get the scheduling method
            method = sched_getscheduler(pid);
            switch (method) { //Determine what scheduling method is used
                case -1:
                    printf("Scheduler Fail\n");
                case SCHED_OTHER:
                    printf("Scheduling Method: SCHED_OTHER\n");
                    break;
                case SCHED_FIFO:
                    printf("Scheduling Method: SCHED_FIFO\n");
                    break;
                case SCHED_RR:
                    printf("Scheduling Method: SCHED_RR\n");
                    break;
                default:
                    printf("Unknown scheduling method\n");
            }
            break;

        case 2:
            pid = atoi(argv[1]); //Turn string input to pid
            if(kill(pid, 0) != 0) { //Check pid
                printf("Pid does not exist\n");
                break;
            }
            //Get and print process priority
            printf("Process Priority: %d\n", getpriority(PRIO_PROCESS, pid));
            //Get the scheduling method
            method = sched_getscheduler(pid);
            switch (method) { //Determine the scheduling method
                case -1:
                    printf("Scheduler Failure\n");
                case SCHED_OTHER:
                    printf("Scheduling Method: SCHED_OTHER\n");
                    break;
                case SCHED_FIFO:
                    printf("Scheduling Method: SCHED_FIFO\n");
                    break;
                case SCHED_RR:
                    printf("Scheduling Method: SCHED_RR\n");
                    break;
                default:
                    printf("Unknown Scheduling Method\n");
            }
            break;

        default:
            printf("Invalid Command Line\n");
            break;
    }

    return 0;
}