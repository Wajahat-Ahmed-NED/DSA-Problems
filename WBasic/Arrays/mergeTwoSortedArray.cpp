// Source: LeetCode
// Link : https://leetcode.com/problems/merge-sorted-array/submissions/983249384/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        int k=0;
        vector<int> nums3;
        while(i<m && j<n){
            if (nums1[i]<=nums2[j]){
                nums3.push_back(nums1[i]);
                k++;
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
                k++;
            }
        }
        

        while(i<m){
            nums3.push_back(nums1[i]);
            i++;
            k++;
        }
        
        while(j<n){
            nums3.push_back(nums2[j]);
            j++;
            k++;
        }

        for (int i=0;i<m+n;i++){
            nums1[i]=nums3[i];
        }

    }
};