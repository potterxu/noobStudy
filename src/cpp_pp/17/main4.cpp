#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const size_t bufferSize = 255;

int main() {
    char inName1[bufferSize];
    char inName2[bufferSize];
    char outName[bufferSize];
    cout << "Input input file 1" << endl;
    cin >> inName1;
    cout << "Input input file 2" << endl;
    cin >> inName2;
    cout << "Input output file 1" << endl;
    cin >> outName;

    ifstream in1(inName1, ios::binary);
    if (in1.fail()) {
        cout << "Cannot open " << inName1 << endl;
    }
    ifstream in2(inName2, ios::binary);
    if (in2.fail()) {
        cout << "Cannot open " << inName2 << endl;
    }
    ofstream out(outName, ios::binary);
    if (out.fail()) {
        cout << "Cannot open " << outName << endl;
    }
    
    string input;
    string input2;
    while (!in1.eof() && !in2.eof()) {
        getline(in1, input);
        getline(in2, input2);
        if (input.empty() && input2.empty()) {
            break;
        }
        if (!input.empty()) {
            out << input;
        }
        if (!input.empty() && !input2.empty()) {
            out << " ";
        }
        if (!input2.empty()) {
            out << input2;
        }
        out << endl;
}
    in1.close();
    in2.close();
    out.close();
    return 0;
}