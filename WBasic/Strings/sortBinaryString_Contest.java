class Solution {
    public int[] sortByReflection(int[] nums) {
        
    
        List<Integer> result=new ArrayList<>();
        Map<Integer, List<Integer>> hash = new HashMap<>();

        for(int i=0;i<nums.length;i++){
            String binary = Integer.toBinaryString(nums[i]);
            String reversed = new StringBuilder(binary).reverse().toString();
            int num=Integer.parseInt(reversed,2);
            hash.putIfAbsent(num, new ArrayList<>());
            hash.get(num).add(nums[i]);
            Collections.sort(hash.get(num),Collections.reverseOrder());
            result.add(num);
        }

        Collections.sort(result);

        for(int i=0;i<result.size();i++){
            int len=hash.get(result.get(i)).size();
            int value=hash.get(result.get(i)).remove(len-1);
            result.set(i,value);
        }

        int[] arr = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            arr[i] = result.get(i);
        }

        return arr;

        
    }
}