class Solution {
public:
    vector<int> sumZero(int n) {
       auto v = vector<int>(n, 0);
       bool haveZero = false;
       if (n & 1) {
           haveZero = true;
       }
       int index = 0;
       for (int i = -n/2; i <= n/2; ++i) {
           if (i == 0 && !haveZero) {
               continue;
           }
           v[index] = i;
           ++index;
       }
       return v;
    }
};
