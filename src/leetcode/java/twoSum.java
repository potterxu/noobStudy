class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];

        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (map.containsKey(num)) {
                int index = map.get(num);
                result[0] = index;
                result[1] = i;
                return result;
            } else {
                int diff = target - num;
                map.put(diff, i);
            }
        }
        return result;
    }
}