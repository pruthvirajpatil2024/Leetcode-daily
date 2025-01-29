class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> mp(nums.begin(), end(nums));

        for(int num : mp){
            if(mp.count(num-1)) continue;       // if it's previous no is present, no need to process current element.
            int i = num;
            while(mp.count(i+1)) ++i;           // checking next-next no
            maxLen = max(maxLen, (i-num+1));
        }
        return maxLen;
    }
};