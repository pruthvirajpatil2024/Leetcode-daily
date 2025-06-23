class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && nums[i] == nums[i + 1]) {
                temp.push_back(nums[i] * 2);
                nums[i + 1] = 0;
                ++i;
            } else if (nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        while (temp.size() < n) {
            temp.push_back(0);
        }

        return temp;
    }
};
