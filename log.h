class Log {
private:
    size_t _start;
    size_t _stop;
    size_t _pid;
    string _colour;

public:
    Log(size_t pid,size_t start,size_t stop,string colour) {
        _pid = pid;
        _start = start;
        _stop = stop;
        _colour = colour;
    }

    size_t pid() {
        return _pid;
    }

    size_t startTime() {
        return _start;
    }

    size_t finishTime() {
        return _stop;
    }

    string colour() {
        return _colour;
    }
};
