class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        const std::ptrdiff_t size {std::ssize(nums)};
        vector<int> result(2 * size,0);
        
        for (std::ptrdiff_t i { 0 }; i < size ; ++i){
            result[i] = nums[i];
            result[i + size] = nums[i];
        }

        return std::move(result);
    }
};