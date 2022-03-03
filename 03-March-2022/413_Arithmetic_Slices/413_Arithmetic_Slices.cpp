class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sol = 0;
        
        if (nums.size() < 3) return sol;
                
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 2; j < nums.size(); j++) {
                if (nums[j] - nums[j - 1] != nums[i + 1] - nums[i]) {
                    break;
                }
                sol++;
            }
        }
        
        return sol;
    }
};
