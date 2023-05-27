# Problem Source : Coding Ninjas

from os import *
from sys import *
from collections import *
from math import *

def encode(message):
    # Write your code here.
   
    ans=0
    temp=message[0]
    result=message[0]
    for i in range(len(message)):
        if message[i]==temp:
            ans+=1
        else:
            result=result+str(ans)
            ans=1
            temp=message[i]
            result=result+message[i]
    return result+str(ans)
