#include <iostream>

using namespace std;

class Square;

class Visitor {
    public:
        virtual int computeArea(Square* s) = 0;
};

class Shape {
    public:
        virtual int area(Visitor* v) = 0;
};

class Square : public Shape {
    public:
        int s = 5;
        int area(Visitor* v) override {
            return v->computeArea(this);
        }
};

class AreaVisitor : public Visitor{
    public:
        int computeArea(Square* s) override {
            return s->s * s->s;
        }
};

int main() {
    Shape *s = new Square();
    Visitor *v = new AreaVisitor();
    cout << "Area is:" << s->area(v) << endl;

    delete v;
    delete s;
    return 0;
}