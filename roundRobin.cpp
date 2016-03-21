#include  <iostream>
#include "scheduler.h"
void Scheduler::roundRobin ()
{
        list<Process>::iterator pointer;

    double x , temp=0 , total_waiting_time =0 ,avg_waiting_time ;
    cout<< "Enter Quantum Time" << endl ;
        cin >> x ;

        double z=_queue.size();
        double Time =0 ;
		
        while (!_queue.empty())
        {
			
		
        if(pointer == _queue.end)
        {
        pointer=_queue.begin();
        }
        else
        {
            if(pointer->getArrivalTime() <=Time)
            {
            pointer->start(Time);
            Time += x;
            pointer ->stop(Time);
            if(pointer->finished())
                {
                    total_waiting_time+= pointer->getWaitingTime();

                    _queue.erase(pointer);
                }
            ++pointer ;

            }
			
            else
            {
            pointer = _queue.begin() ;
            pointer->start(Time);
            Time += x;
            pointer ->stop(Time);
            if(pointer->finished())
                {
                    _queue.erase(pointer);
                }
            ++pointer ;
            }

        }


        }
        avg_waiting_time= total_waiting_time/z;
         cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;
}

