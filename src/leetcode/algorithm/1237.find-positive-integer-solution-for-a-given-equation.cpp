/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
			vector<vector<int>> rv;
			if (customfunction.f(1000, 1000) < z
			    || customfunction.f(1, 1) > z) {
				return rv;
			}
			for (int x = 1; x <= 1000; ++x) {
				if (customfunction.f(x, 1000) < z
				    || customfunction.f(x, 1) > z) {
					continue;
				}
				int start = 1;
				int end = 1000;
				while (start <= end) {
					int mid = (start + end) / 2;
					int v = customfunction.f(x, mid);
					if (v == z) {
						rv.push_back({x,mid});
						break;
					} else if (v > z) {
						end = mid - 1;
					} else if (v < z) {
						start = mid + 1;
					}
				}
			}
			return rv;
    }
};
