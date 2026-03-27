#include <iostream>

using namespace std;

class Image{
    public:
        virtual void display() = 0;
};

class RealImage : public Image {
    string filename;
    public:
        RealImage(string filename) : filename(filename) {}
        void display() override {
            cout << "Displaying the Real Image" << filename << endl;
        }
};

class ProxyImage : public Image {
    string filename;
    RealImage* r = nullptr;
    public:
        ProxyImage(string filename) : filename(filename) {}
        void display() override {
            if(r == nullptr) {
                cout << "Initialising" << endl;
                r = new RealImage(filename);
            }
            cout << "Without Init" << endl;
            r->display();
        }

        ~ProxyImage() {
            delete r;
            r = nullptr;
        }
};

int main() {

    Image* p = new ProxyImage("image.png");

    p->display();
    p->display();

    delete p;

    return 0;
}