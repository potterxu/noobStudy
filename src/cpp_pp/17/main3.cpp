#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    cout << "Input src file" << endl;
    char in[255];
    cin >> in;
    cout << "Output src file" << endl;
    char out[255];
    cin >> out;
    
    ifstream inf;
    inf.open(in, ios::binary);
    if (inf.fail()) {
        cout << "Failed to open input file " << in << endl;
        return 0;
    }
    ofstream outf;
    outf.open(out, ios::binary);
    if (!outf) {
        cout << "Failed to open output file " << out << endl;
        return 0;
    }

    char buffer[512];
    while (!inf.eof()) {
        inf.read(buffer, sizeof(buffer));
        outf.write(buffer, sizeof(buffer));
    }
    inf.close();
    outf.close();
    return 0;
}