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
    
    string input1;
    string input2;
    while(getline(in1, input1)) {
        if (getline(in2, input2)) {
            out << input1 << " " << input2 << endl;
        } else {
            out << input1 << endl;
        }
    }
    while(getline(in2, input2)) {
        out << input2 << endl;
    }
    in1.close();
    in2.close();
    out.close();
    return 0;
}