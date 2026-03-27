#include <iostream>

using namespace std;

class Colour {
    public:
        virtual void paint() {
            cout << "Painted the colour" << endl;
        }
};

class Red : public Colour {
    public:
        void paint() override {
            cout << "Painted Red" << endl;
        }
};

class Shape {
    protected:
        Colour *c;
    public:
        Shape(Colour *c) : c(c) {}
        virtual void create() {
            cout << "Created Shape" << endl;
        }
};

class Circle : public Shape {
    public:
        Circle(Colour *c) : Shape(c) {}
        void create() override {
            cout << "Created a Circle Shape" << endl;
            c->paint();
        }
};

int main() {
    Colour *r = new Red();

    Shape *s = new Circle(r); // create a red circle so that No need to do RedCircle()
    s->create();

    delete r;
    delete s;
    return 0;
}