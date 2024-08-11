# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
print("Hello world")

arr=[2,3,5,5,65,4,3]

ans=[]

for i in arr:
    if i in ans:
        print("Duplicate Element",i)
    else:
        ans.append(i)


# ===========OR=============

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dict1={}
        for i in nums:
            try:
                if dict1[i]>=1:
                    return True
                
            except Exception as e:
                dict1[i]=1
                
        return False
        