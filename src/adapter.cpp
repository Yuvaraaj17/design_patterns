#include <iostream>

using namespace std;

class XMLDataProvider {
    public:
        string getXMLData() {
            return "<user><name>John</name><age>25</age></user>";
        }
};

class JSONProcessor {
    public:
        void processJSON(string data) {
            cout << "Processing JSON Data" << endl;
            cout << data << endl;
            cout << "Completed" << endl;
        }
};

class XMLToJSONAdapter {
    private:
        JSONProcessor *jsonprocessor;
        string convertXMLToJSON(string xml) {
        // Simple conversion logic
        // For demo: <user><name>John</name><age>25</age></user>
        // To:      {"name": "John", "age": 25}
        
        string json = "{";
        
        // Extract name
        size_t nameStart = xml.find("<name>") + 6;
        size_t nameEnd = xml.find("</name>");
        string name = xml.substr(nameStart, nameEnd - nameStart);
        json += "\"name\": \"" + name + "\", ";
        
        // Extract age
        size_t ageStart = xml.find("<age>") + 5;
        size_t ageEnd = xml.find("</age>");
        string age = xml.substr(ageStart, ageEnd - ageStart);
        json += "\"age\": " + age;
        
        json += "}";
        return json;
    }
    public:
        XMLToJSONAdapter(JSONProcessor *jsonpc) : jsonprocessor(jsonpc) {}

        void processXML(string xmlData) {
        cout << "Adapter received XML data:" << endl;
        cout << xmlData << endl;
        
        // Convert XML to JSON
        string jsonData = convertXMLToJSON(xmlData);
        
        cout << "Adapter converted to JSON:" << endl;
        cout << jsonData << endl;
        cout << "---" << endl;
        
        // Pass JSON to the module
        jsonprocessor->processJSON(jsonData);
    }
};

int main() {
    XMLDataProvider xmldataprovider;

    JSONProcessor jsonProcessor;

    XMLToJSONAdapter adapter(&jsonProcessor);

    adapter.processXML(xmldataprovider.getXMLData());

    return 0;
}