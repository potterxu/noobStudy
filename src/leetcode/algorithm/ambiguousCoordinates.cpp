/* 
 * We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we
 * removed all commas, decimal points, and spaces, and ended up with the string
 * S. Return a list of strings representing all possibilities for what our
 * original coordinates could have been.
 * 
 * Our original representation never had extraneous zeroes, so we never started
 * with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other
 * number that can be represented with less digits. Also, a decimal point within
 * a number never occurs without at least one digit occuring before it, so we
 * never started with numbers like ".1".
 * 
 * The final answer list can be returned in any order. Also note that all
 * coordinates in the final answer have exactly one space between them
 * (occurring after the comma.)
 * 
 * Example 1: Input: "(123)" Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1,
 * 2.3)"]
 * 
 * Example 2: Input: "(00011)" Output: ["(0.001, 1)", "(0, 0.011)"] Explanation:
 * 0.0, 00, 0001 or 00.01 are not allowed.
 * 
 * Example 3: Input: "(0123)" Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)",
 * "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
 * 
 * Example 4: Input: "(100)" Output: [(10, 0)] Explanation: 1.0 is not allowed.
 */
#include <list>
#include <string>
#include <vector>

using namespace std;

/* Divide the input string to left and right, for each part, check:
 * if it is *       then output [*]
 * if it is 0***    then output [0.***]
 * if it is ***0    then output [***0]
 * if it is ****    then output [****, *.***, **.**, ***.*]
 * else             then output []
 */
list<string> getValidList(string &&str) {
    list<string> rv;
    if (str.size()==1) {
        rv.push_back(str);
        return rv;
    }
    if (str[0] == '0') {
        if (str[str.size() - 1] != '0') {
            rv.push_back(str.substr(0,1) + "." + str.substr(1,str.size()-1));
        }
    } else {
        rv.push_back(str);
        if (str[str.size() - 1] != '0') {
            for (size_t i = 1; i < str.size(); ++i) {
                rv.push_back(str.substr(0,i) + "." + str.substr(i,str.size()-i));
            }
        }
    }
    return rv;
}

vector<string> ambiguousCoordinates(string S) {
    vector<string> rv;
    for (size_t i = 1; i < S.size() - 2; ++i) {
        for (auto s1 : getValidList(S.substr(1, i))) {
            for (auto s2 : getValidList(S.substr(i+1, S.size() - i - 2))) {
                rv.push_back("(" + s1 + ", " + s2 + ")");
            }
        }
    }
    return rv;
}