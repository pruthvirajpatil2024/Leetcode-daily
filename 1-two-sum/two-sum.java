class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        int[] res = {-1,-1};
        for(int i =0; i<nums.length; i++)
        {
            mp.put(nums[i], i);
        }

        for(int i =0; i<nums.length; i++)
        {
            int rem  = target - nums[i];

            if(mp.containsKey(rem) && mp.get(rem) != i)
            {
                res[0] = i;
                res[1] = mp.get(rem);
                return res;
            }
        }

        return res;
    }
}