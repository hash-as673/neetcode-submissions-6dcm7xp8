class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int double_n = n * 2;
        vector<int> concat_nums(double_n);
        for(int i = 0 ; i < n ; i++){
            concat_nums[i] = nums[i];
            concat_nums[n + i] = nums[i];
        }
        return concat_nums;
    }
};