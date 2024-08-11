j = 1
for i in range(1, len(nums)):
    if nums[i] != nums[i - 1]:
        nums[j] = nums[i]
        j += 1
return j

# output will be [1,2,3,5,6,_,_,_] length will remain same
# Leet Code Question