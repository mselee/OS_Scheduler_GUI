#include "Scheduler.h"

void Scheduler::sortSJF() {
    _queue.sort([&](Process* & lhs, Process* & rhs) {
        double t1 = lhs->getArrivalTime();
        double t2 = rhs->getArrivalTime();
        if (current_time >= t1 && current_time >= t2)
            return lhs->getRemainingTime(current_time) <= rhs->getRemainingTime(current_time);
        if (t1 < t2)
            return true;
        else if (t1 == t2)
            return lhs->getRemainingTime(current_time) <= rhs->getRemainingTime(current_time);
        else
            return false;
    });
}

void Scheduler::sjf(bool prempt) {
	int counter = 0;

    sortSJF();
	Process* item = _queue.front();

	while (true) {
			if (item->getRemainingTime(current_time) == 0) {
				stop(item);
				delete item;
				_queue.pop_front();
                item = _queue.front();
                if (_queue.size() == 0) break;
            }

            sortSJF();
			if (_queue.front() != item)
			{
                if(item->isWorking())
                    stop(item);
				item = _queue.front();
			}

            if (!item->isWorking() && item->getArrivalTime() <= current_time)
			{
				start(item);
			}
			 

            if ((!prempt || _queue.size() == 1) && item->isWorking())
				current_time += item->getRemainingTime(current_time);
            else
				current_time += 1;

		
		counter++;
		if (counter > 100)  {
			cout << "Infinite Loop Ya 7mar";
			break;
		}
	}
}
