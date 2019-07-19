#include <vector>

using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    int sum = 0;
    for (int a : A) {
        if ((a & 1) == 0) {
            sum += a;
        }
    }
    vector<int> rv(queries.size());
    int index = 0;
    for (auto v : queries) {
        if ((A[v[1]] & 1) == 0) {
            sum -= A[v[1]];
        }
        A[v[1]] += v[0];
        if ((A[v[1]] & 1) == 0) {
            sum += A[v[1]];
        }
        rv[index] = sum;
        index++;
    }
    return rv;
}