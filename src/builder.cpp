#include <iostream>
#include <vector>

using namespace std;

enum FieldType {
    TEXT,
    CHECKBOX,
    BUTTON
};

struct Field {
    string name;
    string label;
    FieldType type;

    Field(string n, string l, FieldType ft) : name(n), label(l), type(ft) {}
};

class Form {
    private:
        string name;
        vector<Field> fields;

    public:
        Form(string name, vector<Field> fls) : name(name), fields(fls) {}
        void render() {
            for(Field f : fields) {
                cout << f.label << ":" << "[" << f.type << "]" << endl;
            }
        }

};

class FormBuilder {
    string name;
    vector<Field> fields;
    public:
        FormBuilder(string name) : name(name) {}

        FormBuilder& addTextField(string name, string label){
            fields.push_back(Field(name, label, TEXT));
            return *this;
        }

        FormBuilder& addCheckBox(string name, string label){
            fields.push_back(Field(name, label, CHECKBOX));
            return *this;
        }

        FormBuilder& addButtonField(string name, string label){
            fields.push_back(Field(name, label, BUTTON));
            return *this;
        }

        Form build() {
            return Form(name, fields);
        }
};

int main(){

    Form formbuilder = FormBuilder("simple").addButtonField("name","name").addCheckBox("gender","male").addCheckBox("gender","female").addButtonField("login","login").build();

    formbuilder.render();
    return 0;
}