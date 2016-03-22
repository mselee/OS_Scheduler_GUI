#include <iostream>
using namespace std;

class Process
{
public:
	Process(size_t pid, double arrivalTime, double burstTime,  int priority = 0)
	{
		_pid = pid;
		_waitingTime = 0;
		_stopTime = 0;
		_working = false;

		_arrivalTime = arrivalTime;
		_burstTime = burstTime;
		_remainingTime = burstTime;
		_priority = priority;
	};

	void start(double time) {
		if (_working)
		{
			throw("Process already running!");
		}

		_startTime = time;
		_waitingTime += time - _stopTime;
		_working = true;

		cout << "[" << _pid << "] Started at " << _startTime << endl;
	}

	void stop(double time) {
		if (!_working)
		{
			throw("Process not running!");
		}

		double latency = time - _startTime;
		if (latency > _burstTime)
		{
			throw("Process finishes before stopping!!");
		}

		_remainingTime -= latency;
		_stopTime = time;
		_working = false;

		if (_remainingTime == 0)
		{
			_finishTime = time;
		}

		cout << "[" << _pid << "] Stopped at " << _stopTime << endl;
	}

	double getArrivalTime() {
		return _arrivalTime;
	}

	double getBurstTime(){
		return _burstTime;
	}

	double getRemainingTime(size_t time) {
		return isWorking() ? _remainingTime - (time - _startTime) : _remainingTime;
	}

	double getWaitingTime() {
		return _waitingTime;
	}

	double getFinishTime() {
		return _finishTime;
	}

	int getPriority() {
		return _priority;
	}

	bool isFinished() {
		return _remainingTime == 0;
	}

	bool isWorking() {
		return _working;
	}

    size_t getPID() {
        return _pid;
    }

private:
	size_t _pid;
	double _startTime, _stopTime, _finishTime;
	double _waitingTime, _burstTime, _arrivalTime, _remainingTime;
	int _priority;
	bool _working;
};
