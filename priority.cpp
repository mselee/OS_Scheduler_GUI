#include "Scheduler.h"

 void Scheduler::sortPriority()
 {
    _queue.sort([&](Process* & lhs, Process* & rhs) {
        double t1 = lhs->getArrivalTime();
        double t2 = rhs->getArrivalTime();
        if (current_time >= t1 && current_time >= t2)
            return lhs->getPriority() <= rhs->getPriority();
        if (t1 < t2)
            return true;
        else if (t1 == t2)
            return lhs->getPriority() <= rhs->getPriority();
        else
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
                stop(top);
				totalWaiting += top->getWaitingTime();
				delete top;
				_queue.pop_front();
				top = _queue.front();
				if (_queue.size() == 0) break;
			}

            sortPriority();
			if (_queue.front() != top)
			{
                stop(top);
				top = _queue.front();
			}

            if (!top->isWorking() && top->getArrivalTime() <= current_time) {
                start(top);
			}
			
            current_time++;
		}
	}
	else {
            while(_queue.size() > 0) {
            if(top->getArrivalTime() <= current_time) {
                sortPriority();
                top = _queue.front();
				double latency = top->getBurstTime();
                start(top);
                current_time += latency;
                stop(top);
				totalWaiting += top->getWaitingTime();
				delete top;
				_queue.pop_front();
			}
            else current_time++;
		}
	}

    cout << "Total time: " << current_time;
	cout << "Average waiting time: " << totalWaiting/_queue.size();
}

