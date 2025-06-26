from typing import List
#https://docs.python.org/3.6/library/typing.html
#refer to link for typing

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #list is sorted
        low = 0
        high = len(nums)-1
        ans = -1

        while(low <= high):
            mid = int((low+high)/2)
            if(nums[mid] == target):
                ans = mid
                break
            elif (nums[mid] < target):
                low = mid+1
            else:
                high = mid-1
        
        return ans
