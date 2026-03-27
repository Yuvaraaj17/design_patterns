#include <iostream>

using namespace std;

class Element;

class Mediator {
    public:
        virtual void notify(Element* ele) = 0;
};

class Element {
    protected:
    Mediator *md;
    public:
        Element(Mediator *m = nullptr) : md(m) {}

        void setMediator(Mediator* m) {
            md = m;
        }
};

class Button : public Element{
    public:
        Button(Mediator* m = nullptr) : Element(m) {}

        void click() {
            if(md){
                md->notify(this);
            }
        }

        void enable() {
            cout << "Enabled" << endl;
        }
};

class TextBox : public Element {
    public:
        TextBox(Mediator* m = nullptr) : Element(m) {}

        void click() {
            if(md){
                md->notify(this);
            }
        }

        void setText(string txt) {
            cout << txt << endl;
        }
};

class TBMediator : public Mediator {
    Button* button;
    TextBox* tbx;
    public:
    TBMediator(Button *b, TextBox* t) : button(b), tbx(t) {}
        void notify(Element* sender) override {
            if(sender == button) {
                tbx->setText("clicked");
            } else if(sender == tbx) {
                button->enable();
            }
        }
};

int main() {

    Button btn;
    TextBox tbx;

    Mediator* med = new TBMediator(&btn, &tbx);
    btn.setMediator(med);
    tbx.setMediator(med);

    btn.click();
    tbx.click();

    delete med;
    return 0;
}