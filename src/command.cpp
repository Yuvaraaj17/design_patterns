#include <iostream>
using namespace std;

class Command {
    public:
        virtual void execute() = 0;
};

class Application {
    public:
        void save() {
            cout << "Saved" << endl;
        }

        void clear() {
            cout << "Cleared" << endl;
        }

        void format() {
            cout << "Formatted" << endl;
        }
};

class SaveCommand : public Command {
    protected:
        Application *app;
    public:
        SaveCommand(Application *app) : app(app) {}
        void execute() override {
            app->save();
        }
};

class ClearCommand : public Command {
    protected:
        Application *app;
    public:
        ClearCommand(Application *app) : app(app) {}
        
        void execute() override {
            app->clear();
        }
};

class FormatCommand : public Command {
    protected:
        Application *app;
    public:
        FormatCommand(Application *app) : app(app) {}
        
        void execute() override {
            app->format();
        }
};

class Button {
    Command* cmd;
    public:

        void setCmd(Command *c) {
            cmd = c;
        }

        void click() {
            cmd->execute();
        }
};

int main() {

    Application app;

    Button savebtn, clsbtn, fmtbtn;

    savebtn.setCmd(new SaveCommand(&app));
    clsbtn.setCmd(new ClearCommand(&app));
    fmtbtn.setCmd(new FormatCommand(&app));

    cout << "failing" << endl;

    savebtn.click();
    clsbtn.click();
    fmtbtn.click();

    return 0;
}