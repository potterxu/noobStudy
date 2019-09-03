#include <unordered_map>
#include <string>
using namespace std;

int dfs(unordered_map<char, int> m) {
    int rv = 0;
    for (auto &p : m) {
        if (p.second > 0) {
            --p.second;
            ++rv;
            rv += dfs(m);
            ++p.second;
        }
    }
    return rv;
}

int numTilePossibilities(string tiles) {
    unordered_map<char, int> m;
    for (char c : tiles) {
        ++m[c];
    }
    return dfs(m);
}