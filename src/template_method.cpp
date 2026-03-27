#include <iostream>

using namespace std;


class Beverage {
    public:
        void boil_milk() {
            cout << "Boiling Milk" << endl;
        }

        virtual void add_powder() = 0;

        void add_sugar() {
            cout << "Adding Sugar" << endl;
        }

        virtual void filter_and_flavour() = 0;

        void prepare() {
            boil_milk();
            add_powder();
            add_sugar();
            filter_and_flavour();
        }
};

class Tea : public Beverage {
    public:
        void add_powder() override {
            cout << "adding tea powder" << endl;
        }

        void filter_and_flavour() override {
            cout << "filtering and flavouring tea" << endl;
        }
};

class Coffee : public Beverage {
    public:
        void add_powder() override {
            cout << "adding coffee powder" << endl;
        }

        void filter_and_flavour() override {
            cout << "filtering and flavouring coffee" << endl;
        }
};

int main() {

    Tea t;
    t.prepare();

    Coffee c;
    c.prepare();
    return 0;
}