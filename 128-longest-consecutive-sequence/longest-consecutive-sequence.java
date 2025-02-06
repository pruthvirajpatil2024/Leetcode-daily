import java.util.Arrays;
class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        Arrays.sort(nums);
        int mx = 1;
        int cnt = 1;
        for(int i=0; i<nums.length-1; i++)
        {
            if(nums[i] == nums[i+1]) continue;
            else if(nums[i]+1 == nums[i+1])
            {
                cnt++;
            }
            else
            {
                mx = Math.max(cnt, mx);
                cnt = 1;
            }
        }
        mx = Math.max(cnt, mx);
        return mx;
    }
}