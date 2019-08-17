#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    if (chars.size() <= 1) {
        return chars.size();
    }
    int ptr = 1;
    char curChar = chars[0];
    int count = 1;
    int ptr2 = 1;
    while (ptr2 < chars.size()) {
        if (chars[ptr2] == curChar) {
            ++count;
        } else {
            bool need = false;
            if (count > 999) {
                chars[ptr] = '1';
                count -= 1000;
                ++ptr;
                need = true;
            }
            if (need || count > 99) {
                chars[ptr] = count / 100 + '0';
                count %= 100;
                ++ptr;
                need = true;
            }
            if (need || count > 9) {
                chars[ptr] = count / 10 + '0';
                count %= 10;
                ++ptr;
                need = true;
            }
            if (need || count > 1) {
                chars[ptr] = count + '0';
                ++ptr;
            }
            chars[ptr] = chars[ptr2];
            curChar = chars[ptr2];
            count = 1;
            ++ptr;
        }
        ++ptr2;
    }
    bool need = false;
    if (count > 999) {
        chars[ptr] = '1';
        count -= 1000;
        ++ptr;
        need = true;
    }
    if (need || count > 99) {
        chars[ptr] = count / 100 + '0';
        count %= 100;
        ++ptr;
        need = true;
    }
    if (need || count > 9) {
        chars[ptr] = count / 10 + '0';
        count %= 10;
        ++ptr;
        need = true;
    }
    if (need || count > 1) {
        chars[ptr] = count + '0';
        ++ptr;
    }
    chars.erase(chars.begin() + ptr, chars.end());
    return chars.size();
}