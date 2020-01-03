class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       map<int,int> v2occurence;
       map<int,int> occurence2count;
       for (int i : arr) {
           --occurence2count[v2occurence[i]];
           ++v2occurence[i];
           ++occurence2count[v2occurence[i]];
       }
       for (auto &p : occurence2count) {
           if (p.second > 1) {
               return false;
           }
       }
       return true;
    }
};
