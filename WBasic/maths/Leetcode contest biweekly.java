class Solution {

    public boolean isPrime(int value){
        if(value<=1) return false;
        for(int i=2;i*i<=value;i++){
            if(value%i==0) return false;
        }
        return true;
    }
    public boolean completePrime(int num) {
        int prefixNum=num;
        int suffixNum=num;
        List<Integer> list= new ArrayList<>();
        int suffixAns=0;
        
        while(suffixNum!=0){
            int digit=suffixNum%10;
            list.add(digit);
            // if(!isPrime(digit)) return false;
            suffixNum/=10;            
        }
        
        Collections.reverse(list);

        int numToCheck=0;
        for(int i=0;i<list.size();i++){
            numToCheck=numToCheck*10+list.get(i);
            if(!isPrime(numToCheck)) return false;
            int suf=list.get(i);
            for(int j=i+1;j<list.size();j++){
                suf=suf*10+list.get(j);
            }
            if(!isPrime(suf)) return false;
        }

        return true;
    }
}






class Solution {
     public static boolean isBinaryPalindrome(int num) {
        String binary = Integer.toBinaryString(num);
        int left = 0, right = binary.length() - 1;

        while (left < right) {
            if (binary.charAt(left) != binary.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }

    public static int nearestBinaryPalindrome(int n) {
        if (isBinaryPalindrome(n)) return 0;

        int offset = 1;

        while (true) {
            int lower = n - offset;
            int higher = n + offset;

            if (lower >= 0 && isBinaryPalindrome(lower)) break;
            if (isBinaryPalindrome(higher)) break;

            offset++;
        }

        return offset;
    }
    public int[] minOperations(int[] nums) {
        int[] ans=new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            ans[i] = nearestBinaryPalindrome(nums[i]);
        }
        return ans;
    }
}©leetcode