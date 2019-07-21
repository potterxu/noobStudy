#include <vector>
using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
    vector<int> rv(num_people, 0);
    int i = 0;
    while (candies > 0) {
        int index = i;
        if (index >= num_people) {
            index = index % num_people;
        }
        if (candies <= i + 1) {
            rv[index] += candies;
            break;
        }
        rv[index] += i+1;
        candies -= i+1;
        ++i;
    }
    return rv;
}