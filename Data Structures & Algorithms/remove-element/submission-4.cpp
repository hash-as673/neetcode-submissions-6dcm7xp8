class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow {0};
        for (int fast{0} ; fast < std::ssize(nums) ; ++fast){
            if (nums[fast] != val){
                nums[slow] = nums[fast];
                ++slow;
            } 
        }
        return slow;
    }
};