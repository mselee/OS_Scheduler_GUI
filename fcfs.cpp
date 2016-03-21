#include "Scheduler.h"
#include <iostream>


void Scheduler::fcfs ()
{
    int Time = 0;
    double total_waiting_time =0 ,avg_waiting_time , temp=0 ;
    list<Process>::iterator pointer;
	
    while(pointer != _queue.end())
    {
        pointer->start(Time);
        Time = Time + pointer->getBurstTime();
        pointer -> stop(Time);
        total_waiting_time+=pointer->getWaitingTime();
        ++pointer;
    }
    avg_waiting_time= total_waiting_time/_queue.size();
         cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;

}
	
