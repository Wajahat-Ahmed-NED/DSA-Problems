

def findFirstDuplicate(arr):

    hashmap={}
    for i in range(len(arr)):
        try:
            if hashmap[arr[i]]==True:
                return arr[i]
        except:
            hashmap[arr[i]]=True
    return None

arr = [1, 6, 3, 5, 5, 2, 6]
first_duplicate = findFirstDuplicate(arr)
print("First duplicate:", first_duplicate)