#include <iostream>

using namespace std;

class Coffee {
    public:
        virtual int price () = 0;
};

class PlainCoffee : public Coffee {
    public:
        int price() override {
            return 15;
        }
};

class CoffeeDecorator : public Coffee{
    protected:
        Coffee* c;
    
    public:
        CoffeeDecorator(Coffee *c) : c(c) {}
        virtual int price() = 0;
};

class Milk : public CoffeeDecorator {
    public:
        Milk(Coffee *c) : CoffeeDecorator(c) {}

        int price() override {
            return c->price() + 5;
        }
};

class Sugar : public CoffeeDecorator {
    public:
        Sugar(Coffee *c) : CoffeeDecorator(c) {}

        int price() override {
            return c->price() + 2;
        }
};

int main() {

    Coffee *c = new PlainCoffee();

    cout << "Before adding coffee cost:" << c->price() << endl;

    c = new Milk(c);
    c = new Sugar(c);

    cout << "Coffee cost after adding things:" << c->price() << endl;

    return 0;
}