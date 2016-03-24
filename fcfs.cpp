#include "Scheduler.h"
#include <iostream>
using namespace std ;


void Scheduler::fcfs ()
{
    list<Process*>::iterator pointer = _queue.begin();
    pointer =_queue.begin();

    double total_waiting_time =0 ,avg_waiting_time , temp=0 ;




    while(pointer != _queue.end())
    {
        if((*pointer)->getArrivalTime() <= current_time) {
            start((*pointer));
            current_time = current_time + (*pointer)->getBurstTime();
            stop((*pointer));
            total_waiting_time+=(*pointer)->getWaitingTime();
            ++pointer;
        }
        else
            current_time++;
    }
    avg_waiting_time= total_waiting_time/_queue.size();
         cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;

}
