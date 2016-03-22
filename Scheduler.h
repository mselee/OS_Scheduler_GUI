#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <list>
#include "Process.h"
#include <queue>

class Scheduler
{

private:
    size_t current_time;
    list<Process*> _queue;
//    queue<Log> log;
    void sortSJF();
    void sortPriority();

public:
	Scheduler(list<Process*> queue) {
		_queue = queue;
        current_time = 0;
	}

    ~Scheduler() {
    }

	void sjf(bool prempt=false);
	void fcfs();
	void priority(bool prempt=false);
    void roundRobin(double quantum);
};

#endif
