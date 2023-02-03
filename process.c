#include "headers.h"

/* Modify this file as needed*/
int remainingtime;
int finishtime;

void new_process(int savedremaining) //savedremaining is equal to bursttime at first then it will be the remaining time when state saved
{
    initClk(); //to be able to read the shared memory(clock)
    remainingtime=savedremaining;

    //TODO The process needs to get the remaining time from somewhere
    //remainingtime = ??;
    int x;
    while (remainingtime > 0)
    {
        x=getClk(); //get current time
        
        while(x==getClk()); //busy wait till time is incremented one
       
        remainingtime=remainingtime-1; //Here we're sure that time is incremented
        

    }
    
    finishtime=x+1;
    destroyClk(false);

    return 0;
}

int currentstate(){   //this function will be used to save the current state 
    return remainingtime;
}

int finishtime(){
    return finishtime;
}
