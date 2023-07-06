# Source : Coding Ninjas
# https://www.codingninjas.com/codestudio/problems/inplace-rotate-matrix-90-degree_839734?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=1

from os import *
from sys import *
from collections import *
from math import *

def inplaceRotate(inputArray, n):

    # Write your code here.
    rows=len(inputArray)
    cols=len(inputArray[0])
    for i in range(rows):
        for j in range(i+1,cols):
            temp=inputArray[i][j]
            inputArray[i][j]=inputArray[j][i]
            inputArray[j][i]=temp
    # print(inputArray)
    # for i in range(rows):
    #     inputArray[i].reverse()

    start=0
    end=cols-1
    while(start<end):
        temp=inputArray[start]
        inputArray[start]=inputArray[end]
        inputArray[end]=temp
        start+=1
        end-=1
    
    return inputArray
