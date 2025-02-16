class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string match = strs[0];

        for(int i=1; i<strs.size(); i++)
        {
            string dst = strs[i];
            for(int j=0; j<match.length(); j++)
            {
                if(dst[j] != match[j])
                {
                    match = dst.substr(0, j);
                }
            }
        }

        return match;
    }
};