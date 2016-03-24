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



        while (!_queue.empty())
        {
            if(pointer == _queue.end())
            {
                pointer=_queue.begin();
            }
            else
            {
                if((*pointer)->getArrivalTime() <=current_time)
                {
                    start((*pointer));
                    if((*pointer)->getRemainingTime(current_time) < quantum)
                        current_time += (*pointer)->getRemainingTime(current_time);
                    else
                        current_time += quantum;
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
                    if(pointer == _queue.begin())
                        current_time++;
                    else
                        pointer = _queue.begin() ;

                }
            }
        }
        if (_queue.size()==0){
        avg_waiting_time= total_waiting_time/z;
         cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;
        }
}

