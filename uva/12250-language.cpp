#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string input;
    unordered_map<string, string> traduction({{"HELLO", "ENGLISH"}, {"HOLA", "SPANISH"}, {"HALLO", "GERMAN"}, {"CIAO", "ITALIAN"}, {"BONJOUR", "FRENCH"}, {"ZDRAVSTVUJTE", "RUSSIAN"}});
    int i = 0;
    while (true) {
        i++;
        getline(cin, input);
        if(input == "#") {
            break;
        }

        if(traduction.count(input) == 0) {
            cout << "Case " << i << ": " << "UNKNOWN" << endl;
        }

        else {
            cout << "Case " << i << ": " << traduction[input] << endl;
        }

    }

    return 0;
}