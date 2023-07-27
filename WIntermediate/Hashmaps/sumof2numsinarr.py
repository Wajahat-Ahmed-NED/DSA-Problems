

def findElementsWithSum(arr,inp):

    hashmap={}
    for i in range(len(arr)):
        ans=inp-arr[i]
        # print(ans not in hashmap)
        
        if ans not in hashmap:
            hashmap[arr[i]]=i
        else:
            return str(ans) + str(arr[i])
            
    print(hashmap)
    return None

arr = [1, 6, 3, 5, 5, 2, 6]
two_numbers = findElementsWithSum(arr,9)
print("Two Numbers are",two_numbers)