#include  <iostream>
#include "Scheduler.h"
using namespace std;
void Scheduler::roundRobin ()
{
        list<Process*>::iterator pointer;
        pointer =_queue.begin();
    double x;
    double total_waiting_time =0;
    double avg_waiting_time;
    cout<< "Enter Quantum Time" << endl ;
        cin >> x ;
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
                (*pointer)->start(Time);
                if((*pointer)->getRemainingTime(Time) < x)
                    Time += (*pointer)->getRemainingTime(Time);
                else
                    Time += x;
                (*pointer) ->stop(Time);
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

