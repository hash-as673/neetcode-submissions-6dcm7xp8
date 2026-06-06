class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slow = 0
        for fast,num in enumerate(nums):
            if num != val:
                nums[slow] = nums[fast]
                slow += 1
        
        return slow