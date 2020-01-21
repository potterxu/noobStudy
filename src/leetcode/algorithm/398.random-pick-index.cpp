class Solution {
	public:
		Solution(vector<int>& nums) {
			srand(time(NULL));
			for (int i = 0; i < nums.size(); ++i) {
				num2Index[nums[i]].push_back(i);
			}
		}

		int pick(int target) {
			if (num2Index[target].size() == 1) {
				return num2Index[target][0];
			}
			return num2Index[target][rand() % (num2Index[target].size())];
		}
	private:
		map<int, vector<int>> num2Index;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
