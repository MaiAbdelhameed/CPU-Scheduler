#include "headers.h"
#include "process.c"
struct PCB
{
    int arrivaltime;
    int priority;
    int runningtime;
    int id;
    int finishtime;
};

struct PCB* running; //points to the running process





int main(int argc, char *argv[])
{
     
    initClk();
    //At beginning: find a way of commmunication between scheduler and process generator to put new processes in the ready queue which will have different structure according to the type of algorithm


    //Notes about processes:  1)Creation of a process: by fork() then if we're in child call the functions in process.c 
    //                        2)Stop a process: a)call function currentstate in process.c b)save the state c)kill that child(that doesn't mean that the process has completed as the scheduler still has its PCB)

    //Notes about any algorithm:  1)any algorithm will be working in a while(1){} where the first line in this loop is to check whether there's a new processs arrived or not (message queue between scheduler and process generator)
    //                            2)when an algorithm selects a new process to run: a)put the PCB of runnning in the ready queue but check if its not null first 
    //                                                                              b)running=PCB of the selected process
    
    
    
    
    //TODO: implement the scheduler.

    //TODO: upon termination release the clock resources.

    destroyClk(true);
}
