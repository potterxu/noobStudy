/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (36.15%)
 * Likes:    209
 * Dislikes: 736
 * Total Accepted:    34.6K
 * Total Submissions: 95.5K
 * Testcase Example:  '2\n[3]'
 *
 * Your task is to calculate a^b mod 1337 where a is a positive integer and b
 * is an extremely large positive integer given in the form of an array.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: a = 2, b = [3]
 * Output: 8
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = 2, b = [1,0]
 * Output: 1024
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int pow(int a, int p) {
        // a*b % m = (a%m)(b%m)%m
        if (p == 0) {
            return 1;
        } else if (p == 1) {
            return a;
        }
        if ((p&1) == 0) {
            return (pow(a, p/2) % 1337) * (pow(a, p/2) % 1337) % 1337;
        }
        return (a * pow(a, p-1)) % 1337;
    }
    int superPow(int a, vector<int>& b) {
       // a^1234 = a^4 * (a^123)^10
       a %= 1337;
       if (a == 0) {
           return 0;
       }
       if (a == 1) {
           return 1;
       }
       if (!b.empty()) {
           int part1 =  pow(a, b.back());
           b.pop_back();
           int part2 = pow(superPow(a, b), 10) % 1337;
           return part1 * part2 % 1337;
       }
       return 1;
    }
};
// @lc code=end
