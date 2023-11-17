class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        first=float('-inf')
        second=float('-inf')
        third=float('-inf')
       
        for i in nums:
            if i > first:
                third=second;
                second=first;
                first=i
            elif i>second and i!=first:
                third=second
                second=i
            elif i>third and i!=first and i!=second:
                third=i
            
        if third==float('-inf'):
            return first

        return third


        # for i in range (0,len(nums)):
        #     if nums[i]>first:
        #         temp=first
        #         first=nums[i]
        #         third=second
        #         second=temp

        # if  third==-1 or third==0:
        #     return first
        

        # return third

