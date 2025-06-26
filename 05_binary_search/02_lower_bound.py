from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums)-1
        ans = high+1

        while(low <= high):
            mid = int((low+high)/2)
            if(nums[mid] >= target):
                ans = mid
                high = mid -1
            else:
                low = mid+1
        
        return ans
