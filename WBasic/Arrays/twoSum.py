class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        numMap={}

        for i in range(0,len(nums)):
            ans=target-nums[i]
            if ans in numMap:
                return [numMap[ans],i]
            numMap[nums[i]]=i
        