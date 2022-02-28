class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)  {
            return {};
        }
        
        vector<string> sol;
        int start = nums[0], end = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                end = nums[i];
            }
            else {
                if (start == end) {
                    sol.push_back(to_string(end));
                }
                else {
                    sol.push_back(to_string(start) + "->" + to_string(end));                 
                }
                start = nums[i];
                end = nums[i];
            }
        }
        
        if (start == end) {
            sol.push_back(to_string(end));
        }
        else {
            sol.push_back(to_string(start) + "->" + to_string(end));                 
        }
        
        return sol;
    }
};
