class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int k) {
        int low = 0, high = nums.size()-1;
        int ind = -1;
        while(low <= high)
        {
            int mid = (low + high) /2;
            if(nums[mid] == k) 
            {
                ind = mid;
                break;
            }
            else if(nums[mid] > k)
            {
                high = mid-1;
            }
            else 
            {
                low = mid +1;
            }
        }

        if(ind == -1) return {-1,-1};

        while(ind > 0)
        {
            if(nums[ind] == nums[ind-1])
            {
                ind--;
            }
            else 
            {
                break;
            }
        }
        int s = ind;
        while(ind < nums.size()-1)
        {
            if(nums[ind] == nums[ind+1])
            {
                ind++;
            }
            else 
            {
                break;
            }
        }
        return {s, ind};
    }
};