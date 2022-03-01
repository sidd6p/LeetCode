class Solution {
public:
    vector<int> countBits(int n) {
        int k = 0, cur_ele = 1;
        vector<int> sol;
        
        sol.push_back(0);

        for (int i = 1; i <= n; i++) {
            if (i == cur_ele) {
                k = 0;
                cur_ele *= 2;
            }
            sol.push_back(1 + sol[k++]);
        }

        return sol;
    }
};
