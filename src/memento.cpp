#include <iostream>
#include <vector>

using namespace std;

class State {
    string content;

    public:
        State(string s) : content(s) {}

        string getState() const {
            return content;
        }
};

class Editor {
    string content;

    public:
        void setContent(string s){
            content = s;
        }

        string getContent() {
            return content;
        }

        State save(){
            return State(content);
        }

        void restore(const State &s) {
            content = s.getState();
        }
};

class History {
    vector<State> history;

    public:
        void store(const State& s){
            history.push_back(s);
        }

        State pop(){
            State last = history.back();
            history.pop_back();
            return last;
        }
};

int main() {
    Editor edit;
    History his;

    edit.setContent("A");
    his.store(edit.save());

    edit.setContent("AB");
    his.store(edit.save());

    edit.setContent("ABC");

    cout << edit.getContent() << endl; // ABC

    // undo
    edit.restore(his.pop());
    cout << edit.getContent() << endl; // AB

    edit.restore(his.pop());
    cout << edit.getContent() << endl; // A

    return 0;
}