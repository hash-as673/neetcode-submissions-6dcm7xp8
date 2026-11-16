class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count {0};
        int current_count {0};
        for (int i {0}; i < std::ssize(nums); i++){
            if (nums[i] == 1){
                current_count++;
            } else {
                current_count = 0;
            }
            max_count = max(current_count, max_count);
        }
        return max_count;
    }
};