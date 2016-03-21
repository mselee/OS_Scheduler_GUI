#include "Scheduler.h"

 void Scheduler::sortPriority()
 {
    _queue.sort([&](Process* & lhs, Process* & rhs) {
        if(lhs->getArrivalTime() < rhs->getArrivalTime())
            return true;
        if (lhs->getArrivalTime() == rhs->getArrivalTime())
        {
            if (lhs->getPriority() > rhs->getPriority())
                return true;
            return false;
        }
        return false;
    });
 };

void Scheduler::priority(bool prempt) {
	double totalWaiting = 0;

    sortPriority();
	Process* top = _queue.front();
	if (prempt)
	{

		while(_queue.size() != 0) {
            if (top->getRemainingTime(current_time) == 0)
			{
                top->stop(current_time);
				totalWaiting += top->getWaitingTime();
				delete top;
				_queue.pop_front();
				top = _queue.front();
				if (_queue.size() == 0) break;
			}

            sortPriority();
			if (_queue.front() != top)
			{
                top->stop(current_time);
				top = _queue.front();
			}

            if (!top->isWorking() && top->getArrivalTime() <= current_time) {
                top->start(current_time);
			}
			
            current_time++;
		}
	}
	else {
		while(_queue.size() > 0) {
            if(top->getArrivalTime() <= current_time) {
				double latency = top->getBurstTime();
                top->start(current_time);
                current_time += latency;
                top->stop(current_time);
				totalWaiting += top->getWaitingTime();
				delete top;
                sortPriority();
				top = _queue.front();
				_queue.pop_front();
			}
            else current_time++;
		}
	}

    cout << "Total time: " << current_time;
	cout << "Average waiting time: " << totalWaiting/_queue.size();
}

