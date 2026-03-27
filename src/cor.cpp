#include <iostream>

using namespace std;

class Logger {
    protected:
        Logger *next;

    public:
        Logger() : next(nullptr) {}

        void setNext(Logger *nxt) {
            next = nxt;
        }

        virtual void log(string level, string message) {
            if(next)
                next->log(level, message);
        }
};

class InfoLogger : public Logger {
    public:
        void log(string level, string message) override {
            if(level == "INFO") {
                cout << "INFO :" << message << endl;
            } else {
                Logger::log(level, message);
            }
        }
};

class DebugLogger : public Logger {
    public:
        void log(string level, string message) override {
            if(level == "DEBUG") {
                cout << "DEBUG :" << message << endl;
            } else {
                Logger::log(level, message);
            }
        }
};

class WarnLogger : public Logger {
    public:
        void log(string level, string message) override {
            if(level == "WARN") {
                cout << "WARN :" << message << endl;
            } else {
                Logger::log(level, message);
            }
        }
};


int main() {

    Logger* info = new InfoLogger();
    Logger* debug = new DebugLogger();
    Logger* warn = new WarnLogger();


    info->setNext(debug);
    debug->setNext(warn);

    info->log("INFO", "info message sample");
    info->log("WARN", "warn message sample"); // auto propagation through info

    delete info;
    delete debug;
    delete warn;

    return 0;

}