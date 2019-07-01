#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> commonFriends;
   
    ifstream mat, pat;
    string input;

    mat.open("mat.dat");
    if (mat.fail()) {
        cout << "Failed to open mat.dat";
    }
    cout << "mat's friends:" << endl;
    while (getline(mat, input)) {
        cout << input << endl;
        commonFriends.insert(input);
    }
    mat.close();

    pat.open("pat.dat");
    if (pat.fail()) {
        cout << "Failed to open pat.dat";
    }
    cout << "pat's friends:" << endl;
    while (getline(pat, input)) {
        cout << input << endl;
        commonFriends.insert(input);
    }
    mat.close();

    ofstream out;
    out.open("matnpat.dat");
    if (out.fail()) {
        cout << "Failed to open matnpat.dat";
    }
    for (auto f : commonFriends) {
        out << f << endl;
    }
    out.close();
}