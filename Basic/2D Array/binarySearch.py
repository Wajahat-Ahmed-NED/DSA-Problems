# Source: LeetCode
# https://leetcode.com/problems/search-a-2d-matrix/submissions/971377127/

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row=len(matrix)
        col=len(matrix[0])

        start=0
        end=row*col-1

        mid=start+(end-start)//2

        while(start<=end):
            element=matrix[mid//col][mid%col];
            if(element==target):
                return True
            elif (target>element):
                start=mid+1;
            else:
                end=mid-1
            
            mid=start+(end-start)//2
        return False