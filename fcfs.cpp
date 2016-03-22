#include "scheduler.h"
#include <iostream>
using namespace std ;


void Scheduler::fcfs ()
{
    list<Process*>::iterator pointer;
    pointer =_queue.begin();

    double Time = 0;
    double total_waiting_time =0 ,avg_waiting_time , temp=0 ;




    while(pointer != _queue.end())
    {

        start((*pointer));
        Time = Time + (*pointer)->getBurstTime();
        stop((*pointer));
        total_waiting_time+=(*pointer)->getWaitingTime();
        ++pointer;
    }
    avg_waiting_time= total_waiting_time/_queue.size();
         cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;

}
