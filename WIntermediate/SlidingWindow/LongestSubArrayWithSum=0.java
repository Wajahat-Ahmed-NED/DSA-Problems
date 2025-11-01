class Solution {
    public int longestSubarray(int[] nums, int k) {
       int prefixSum=0;
       int maxLen=0;
        
        Map<Integer,Integer> m=new HashMap<>();
        m.put(0,-1);

       for(int i=0;i<nums.length;i++){
            prefixSum+=nums[i];
            
            if(m.containsKey(prefixSum)){
                Integer isPresent=m.get(prefixSum);
                Integer currLen=i-isPresent;
                maxLen=Math.max(maxLen,currLen);            
            }
            else m.put(prefixSum,i);

       }

       return maxLen;
    }
}