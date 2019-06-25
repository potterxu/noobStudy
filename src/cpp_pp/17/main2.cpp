#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    cout << "Please input the file name to output" << endl;
    char name[20];
    cin >> name;
    ofstream f;
    f.open(name,ios::app);
    if (f.fail()) {
        cout << "Cannot open file " << name << endl;
    }
    char input[255];
    cin >> input;
    while (strcmp(input, "eof")) {
        cin >> input;
        f << input;
    }
    f.close();
}