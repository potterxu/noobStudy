/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 *
 * https://leetcode.com/problems/24-game/description/
 *
 * algorithms
 * Hard (45.91%)
 * Likes:    738
 * Dislikes: 151
 * Total Accepted:    41.6K
 * Total Submissions: 89.5K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 
 * You have 4 cards each containing a number from 1 to 9.  You need to judge
 * whether they could operated through *, /, +, -, (, ) to get the value of
 * 24.
 * 
 * 
 * Example 1:
 * 
 * Input: [4, 1, 8, 7]
 * Output: True
 * Explanation: (8-4) * (7-1) = 24
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 1, 2]
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The division operator / represents real division, not integer division.  For
 * example, 4 / (1 - 2/3) = 12.
 * Every operation done is between two numbers.  In particular, we cannot use -
 * as a unary operator.  For example, with [1, 1, 1, 1] as input, the
 * expression -1 - 1 - 1 - 1 is not allowed.
 * You cannot concatenate numbers together.  For example, if the input is [1,
 * 2, 1, 2], we cannot write this as 12 + 12.
 * 
 * 
 * 
 */

class Solution {
public:
    void getAllResult(double a, double b, vector<double> &result) {
        result.push_back(a+b);
        result.push_back(a-b);
        result.push_back(b-a);
        result.push_back(a*b);
        if (abs(b) > 0.00001) {
            // b != 0
            result.push_back(a/b);
        }
        if (abs(a) > 0.00001) {
            // a != 0
            result.push_back(b/a);
        }
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double> d(nums.begin(), nums.end());
        return judgePoint24(d);
    }
    bool judgePoint24(vector<double>& nums) {
        // choose two number to count, then problem change to get 24 with 3 number
        // then choose two in the three number ==> get 24 with 2 number
        // then check if we can get with this 2 number
        vector<double> innerNum = nums;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                // remove later one first
                double num2 = innerNum[j];
                double num1 = innerNum[i];
                innerNum.erase(innerNum.begin()+j);
                innerNum.erase(innerNum.begin()+i);
                // loop all possible values can form by the two number
                vector<double> result;
                getAllResult(num1, num2, result);
                if (innerNum.empty()) {
                    for (double d : result) {
                        if (abs(d-24) < 0.00001) {
                            return true;
                        }
                    }
                } else {
                    for (double d : result) {
                        innerNum.push_back(d);
                        if (judgePoint24(innerNum)) {
                            return true;
                        }
                        innerNum.pop_back();
                    }
                }
                innerNum.insert(innerNum.begin()+i, num1);
                innerNum.insert(innerNum.begin()+j, num2);
            }
        }
        return false;
    }
};