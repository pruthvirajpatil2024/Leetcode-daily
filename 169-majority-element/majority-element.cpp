class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ind = 0, cnt =0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == nums[ind])
            {
                cnt++;
            }
            else if(nums[i] != nums[ind] && cnt != 0) 
            {
                cnt--;
            }
            else 
            {
                ind = i;
                cnt++;
            }
        }

        return nums[ind];
    }
};