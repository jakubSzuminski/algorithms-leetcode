class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat[0].size();
        int pos = -1;
        int n = mat.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int count = 0;

            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1) {
                   count++;
                   pos = j;
                }
            }

            if(count == 1){
                count = 0;

                for(int k = 0; k < n; k++) {
                    if(mat[k][pos] == 1) count++;
                }

                if(count == 1) ans++;
            }
        }

        return ans;
    }
};