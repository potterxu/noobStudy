#include <algorithm>
#include <vector>
using namespace std;

int distributeCandy(vector<int> &candies) {
    sort(candies.begin(), candies.end());
    auto result = unique(candies.begin(), candies.end());
    int types = distance(candies.begin(), result);
    if (types > candies.size() / 2) {
        return candies.size() / 2;
    } else {
        return types;
    }
}