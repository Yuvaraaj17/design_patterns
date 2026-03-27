#include <iostream>

using namespace std;

class CheckBox {
    public:
        virtual void render() = 0;
};

class WindowsCheckBox : public CheckBox {
    public:
        void render() {
            cout << "Windows Checkbox rendered" << endl;
        }
};

class LinuxCheckBox : public CheckBox {
    public:
        void render() {
            cout << "Linux Checkbox rendered" << endl;
        }
};

class Button {
    public:
        virtual void render() = 0;
};

class WindowsButton : public Button {
    public:
        void render() override {
            cout << "Windows button rendered" << endl;
        }
};

class LinuxButton : public Button {
    public:
        void render() override {
            cout << "Linux button rendered" << endl;
        }
};



class GUIFactory {
    public:
        virtual Button* createButton() = 0;
        virtual CheckBox* createCheckBox() = 0;
        static GUIFactory* getGUIFactory(string osname);

};

class WindowsFactory : public GUIFactory {
    public:
        Button* createButton() override {
            return new WindowsButton();
        }

        CheckBox* createCheckBox() override {
            return new WindowsCheckBox();
        }
};

class LinuxFactory : public GUIFactory {
    public:
        Button* createButton() override {
            return new LinuxButton();
        }

        CheckBox* createCheckBox() override {
            return new LinuxCheckBox();
        }
};

GUIFactory* GUIFactory::getGUIFactory(string osname) {
            if(osname == "windows") {
                return new WindowsFactory();
            } else if(osname == "linux") {
                return new LinuxFactory();
            } else {
                return nullptr;
            }
        }

int main() {

    GUIFactory *gui = GUIFactory::getGUIFactory("linux");

    if(!gui) {
        cout << "Invalid os name" << endl;
        return 0;
    }

    Button *btn = gui->createButton();
    btn->render();
    delete btn;

    CheckBox *chkBox = gui->createCheckBox();
    chkBox->render();
    delete chkBox;

    return 0;
}