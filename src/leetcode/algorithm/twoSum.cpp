/*
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
 */

#include <vector>
#include <unordered_map>

// Loop the input vector and for each number, store remain = (target - number)
// in a hash_map and search if this number is in the hash_map.

//Complexity: O(n)
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> rv;
    std::unordered_map<int,int> remainMap;
    for (size_t i = 0; i < nums.size(); i++) {
        int remain = target - nums[i];

        auto it = remainMap.find(nums[i]);
        if (it != remainMap.end()) {
            rv.push_back(it->second);
            rv.push_back(i);
            break;
        }

        remainMap[remain] = i;
    }
    return rv;
}