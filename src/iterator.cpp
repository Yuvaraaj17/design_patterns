#include <iostream>
#include <vector>

using namespace std;

class Iterator {
    public:
        virtual bool hasNext() = 0;
        virtual int next() = 0;
};

class Collection {
    vector<int> col;

    public:
        void add(int a) {
            col.push_back(a);
        }

        int get(int ind) {
            return col[ind];
        }

        int size() {
            return col.size();
        }

        Iterator *createIterator();
};

class MyIterator : public Iterator {
    Collection* myCol;
    int index;

    public:
        MyIterator(Collection* c) : myCol(c), index(0) {}

        bool hasNext() override {
            return index < myCol->size();
        }

        int next() override {
            return myCol->get(index++);
        }
};

Iterator* Collection::createIterator() {
    return new MyIterator(this);
}

int main() {
    Collection c;

    c.add(5);
    c.add(4);
    c.add(3);

    Iterator* it = c.createIterator();

    while (it->hasNext())
    {
        cout << it->next() << endl;
        /* code */
    }
    
    return 0;
}

