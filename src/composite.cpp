#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        string name;
        Node(string n) : name(n) {}
        virtual void show() = 0;
};

class File : public Node {
    public:
        string name;
        File(string n) : Node(n) {}
        void show () override {
            cout << "Shows file contents" << endl;
        }
};

class Directory : public Node {
    public:
        string name;
        vector<Node*> nodes;
        Directory(string n) : Node(n) {}

        void show() override {
            for(int i = 0; i < nodes.size(); i++) {
                nodes[i]->show();
            }
        }

        void add(Node *n) {
            nodes.push_back(n);
        }
};

int main() {
    Directory *root = new Directory("sample");

    File* f1 = new File("file 1");
    cout << f1->name << endl;
    root->add(f1);

    root->show();
    return 0;
}