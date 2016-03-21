#include "Scheduler.h"

// struct compareArrivalPriority
// {
// 	bool operator (Process lhs, Process rhs) {
// 		if(lhs.getArrivalTime() < rhs.getArrivalTime())
// 			return true;
// 		if (lhs.getArrivalTime() == rhs.getArrivalTime())
// 		{
// 			if (lhs.getPriority() > rhs.getPriority())
// 				return true;
// 			return false;
// 		}
// 		return false;
// 	}
// };

size_t time = 0;

struct CompareArrivalPriority {
	bool operator()(Process* lhs, Process* rhs) {
		double t1 = lhs->getArrivalTime();
		double t2 = rhs->getArrivalTime();
		if (time >= t1 && time >= t2)
			return lhs->getPriority() <= rhs->getPriority();
		if (t1 < t2)
			return true;
		else if (t1 == t2)
			return lhs->getPriority() <= rhs->getPriority();
		else
			return false;
	}
};

void Scheduler::priority(bool prempt) {
	double totalWaiting = 0;

	_queue.sort(CompareArrivalPriority());
	Process* top = _queue.front();
	if (prempt)
	{

		while(_queue.size() != 0) {
			if (top->getRemainingTime(time) == 0)
			{
				top->stop(time);
				totalWaiting += top->getWaitingTime();
				delete top;
				_queue.pop_front();
				top = _queue.front();
				if (_queue.size() == 0) break;
			}

			_queue.sort(CompareArrivalPriority());
			if (_queue.front() != top)
			{
				top->stop(time);
				top = _queue.front();
			}

			if (!top->isWorking() && top->getArrivalTime() <= time) {
				top->start(time);
			}
			
			time++;
		}
	}
	else {
		while(_queue.size() > 0) {
			if(top->getArrivalTime() <= time) {
				double latency = top->getBurstTime();
				top->start(time);
				time += latency;
				top->stop(time);
				totalWaiting += top->getWaitingTime();
				delete top;
				_queue.sort(CompareArrivalPriority());
				top = _queue.front();
				_queue.pop_front();
			}
			else time++;
		}
	}

	cout << "Total time: " << time;
	cout << "Average waiting time: " << totalWaiting/_queue.size();
}

