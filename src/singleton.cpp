#include <iostream>

using namespace std;

class SingleClass {
    private:
        SingleClass() {};
    public:
        static SingleClass* getSingleClass() {
            cout << "Single Class is called" << endl;
            return new SingleClass();
        }
};

int main() {

    SingleClass *s = SingleClass::getSingleClass();
    // SingleClass *s = new SingleClass();
    return 0;
}