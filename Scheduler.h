#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <list>
#include "Process.h"
#include "log.h"
#include <queue>
#include <map>

class Scheduler
{

private:
    size_t current_time;
    size_t logStartTime;
    list<Process*> _queue;
    queue<Log*> log;
    map<size_t,string> colours;


    void sortSJF();
    void sortPriority();

    void start(Process* p) {
        p->start(current_time);

        if(colours[p->getPID()] == "") {
            colours[p->getPID()] = "#" + to_string(rand()%1000000);
        }

        logStartTime = current_time;
    }

    void stop(Process* p) {
        p->stop(current_time);
        size_t pid = p->getPID();
        log.push(new Log(pid,logStartTime, current_time, colours[pid]));
    }

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
