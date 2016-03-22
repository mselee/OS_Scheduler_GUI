#include  <iostream>
#include "Scheduler.h"
using namespace std;
void Scheduler::roundRobin(double quantum)
{
        list<Process*>::iterator pointer;
        pointer =_queue.begin();
        double total_waiting_time =0;
        double avg_waiting_time;
        double z=_queue.size();
        double Time =0 ;



        while (!_queue.empty())
        {
        if(pointer == _queue.end())
        {
        pointer=_queue.begin();
        }
        else
        {
            if((*pointer)->getArrivalTime() <=Time)
            {
                start((*pointer));
                if((*pointer)->getRemainingTime(Time) < quantum)
                    Time += (*pointer)->getRemainingTime(Time);
                else
                    Time += quantum;
                stop((*pointer));
            if((*pointer)->isFinished())
                {
                    total_waiting_time+= (*pointer)->getWaitingTime();
                    if(_queue.size() == 1) {
                        _queue.erase(pointer);
                        break;
                    }
                    else {
                        --pointer;
                        _queue.erase(next(pointer,1));
                    }
                }
            ++pointer ;

            }

            else
            {
            pointer = _queue.begin() ;
            //(*pointer)->start(Time);
            //Time += x;
            //(*pointer) ->stop(Time);
            //if((*pointer)-> isFinished())
                //{
                    //_queue.erase(pointer);
                //}
            //++pointer ;
            }
        }
    }
        if (_queue.size()==0){
        avg_waiting_time= total_waiting_time/z;
         cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;
        }
}

