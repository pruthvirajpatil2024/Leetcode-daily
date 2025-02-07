class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int j=0; j<n; j++)
        {
            vector<int> temp;
            for(int i=n-1; i>=0;i--)
            {
                temp.push_back(mat[i][j]);
            }
            mat.push_back(temp);
        }

        for(int i=0; i<n; i++)
        {
            mat.erase(mat.begin());
        }
    }
};