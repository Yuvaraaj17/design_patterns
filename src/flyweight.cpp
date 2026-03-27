#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Style {
   public:
        string font;
        string style;
        string color;

        Style(string f, string s, string c) : font(f), style(s), color(c) {}
};

class StyleFactory {
    public:
        unordered_map<string, Style*> styles;

        Style *getStyle(string f, string s, string c)
        {
            string key = f + s + c;

            if (styles.find(key) == styles.end())
            {
                styles[key] = new Style(f, s, c);
            }
            return styles[key];
        }
};

class Character {
    public:
        Style* s;
        string value;

        Character(Style* s, string v) : s(s), value(v) {}

        void display() {
            cout << this->value << ":" << s->font << ":" << s->style << ":" << s->color << endl;
        }
};

int main() {

    StyleFactory s;
    vector<Character*> word;

    auto style = s.getStyle("Arial", "Bold", "Black");

    word.push_back(new Character(style, "A"));
    word.push_back(new Character(style, "B"));
    word.push_back(new Character(style, "C"));
    word.push_back(new Character(style, "D"));

    for( Character* w : word){
        w->display();
    }

    return 0;
}