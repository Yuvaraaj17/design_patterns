#include <iostream>
using namespace std;

class Button
{
public:
    virtual void render() = 0;
};

class WindowsButton : public Button
{
public:
    void render() override
    {
        cout << "Windows button is created" << endl;
    }
};

class LinuxButton : public Button
{
public:
    void render() override
    {
        cout << "Linux button is created" << endl;
    }
};

Button *createButton(string os)
{
    if (os == "windows")
    {
        return new WindowsButton();
    }
    else if (os == "linux")
    {
        return new LinuxButton();
    }
    else
    {
        return nullptr;
    }
}

int main()
{
    cout << "Application starting" << endl;

    Button *btn = createButton("windows");
    if (btn)
    {
        btn->render();
        delete btn;
    }
    else
    {
        cout << "Invalid OS name" << endl;
    }

    return 0;
}