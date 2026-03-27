#include <iostream>
#include <vector>

using namespace std;

class Subscriber {
    vector<string> content;
    public:
        void push_content(string message) {
            content.push_back(message);
        }

        void view_content() {
            for(string s : content) {
                cout << s << " ";
            }
        }

};

class Publisher {
    vector<Subscriber*> subscribers;
    vector<string> messages;

    public:
        void subscribe(Subscriber* s) {
            subscribers.push_back(s);
        }

        void unsubscribe(Subscriber* s) {
            for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
                if(*it == s) subscribers.erase(it);
            }
        }
        void notifyAll() {
            for(Subscriber* sub : subscribers) {
                sub->push_content(messages.back());
            }
        }

        void add_content(string s) {
            messages.push_back(s);
            notifyAll();
        }
};

int main() {

    Publisher p;

    Subscriber a;
    Subscriber b;

    p.subscribe(&a);
    p.subscribe(&b);

    cout << "\nBefore publish A content:";
    a.view_content();
    cout << "\nBefore publish B content:";
    b.view_content();

    string s;
    cin >> s;

    p.add_content(s);
    cout << "\nAfter publish A content:";
    a.view_content();
    cout << "\nAfter publish B content:";
    b.view_content();

    return 0;
}