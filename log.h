class Log {
private:
    double _start;
    double _stop;
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

    double startTime() {
        return _start;
    }

    double finishTime() {
        return _stop;
    }

    string colour() {
        return _colour;
    }
};
