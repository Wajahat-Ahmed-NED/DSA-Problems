// Better approach - 3 passes;

class Solution {
    public void sortColors(int[] nums) {
        int j=0;

        for(int color=0;color<3;color++){
            for(int i=j;i<nums.length;i++){
                if(nums[i]==color){
                    int temp=nums[j];
                    nums[j]=nums[i];
                    nums[i]=temp;
                    j++;
                }
            }
        }
    }
}


// Optimal Approach 
// 3 pointers - Dutch National Flag Algorithm

class Solution {
    public void sortColors(int[] nums){
        int low=0;
        int high=nums.length-1;
        int mid=0;

        while(mid<=high){
            if(nums[mid]==0){
                int temp=nums[mid];
                nums[mid]=nums[low];
                nums[low]=temp;

                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else {
                int temp=nums[mid];
                nums[mid]=nums[high];
                nums[high]=temp;

                high--;                
            }
        }
    }
}