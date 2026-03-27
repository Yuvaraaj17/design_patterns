#include <iostream>
using namespace std;

class TrafficLight;

class State {
    public:
        virtual void handle(TrafficLight* system) = 0;

};

class TrafficLight {
    State* state;

    public:
        TrafficLight(State* st) : state(st) {}

        void setState(State* s) {
            state = s;
        }

        void request() {
            state->handle(this);
        }
};

class StopState : public State {
    void handle(TrafficLight* st) override;
};

class ReadyState : public State {
    void handle(TrafficLight* st) override;
};

class GoState : public State {
    void handle(TrafficLight* st) override;
};

void StopState::handle(TrafficLight *st) {
    cout << "In Stop State --> Moving to Ready State" << endl;
    st->setState(new ReadyState());
}

void ReadyState::handle(TrafficLight *st) {
    cout << "In Ready State --> Moving to Go State" << endl;
    st->setState(new GoState());
}

void GoState::handle(TrafficLight *st) {
    cout << "In Go State --> Moving to Stop State" << endl;
    st->setState(new StopState());
}

int main() {

    TrafficLight* light = new TrafficLight(new StopState());

    light->request();
    light->request();

    delete light;
    return 0;
}