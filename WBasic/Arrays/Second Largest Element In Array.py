# Problem Source : Coding Ninjas

def findSecondLargest(sequenceOfNumbers):
    # Write your code here.
    first=-2101010101
    second=-210101001
    for i in range(0,len(sequenceOfNumbers)):
        if(sequenceOfNumbers[i]>first):
            second=first
            first=sequenceOfNumbers[i]
        elif(sequenceOfNumbers[i]>second and sequenceOfNumbers[i]!=first):
            second=sequenceOfNumbers[i]
    if second==-210101001 or second==-2101010101:
        return -1
    else:
        return second