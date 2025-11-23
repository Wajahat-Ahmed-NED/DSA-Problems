class Solution {

    public void findAllCombinations(int ind,int k,int n,List<Integer> temp, List<List<Integer>> result){
        if(ind>9 || k==0 || ind>n){
            if(n==0 && k==0) {
                result.add(new ArrayList<>(temp));
            }
            return;
        }

        temp.add(ind);
        findAllCombinations(ind+1,k-1,n-ind, temp,result);
        temp.remove(temp.size()-1);

        findAllCombinations(ind+1,k,n,temp,result);

        
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<Integer> temp= new ArrayList<>();
        List<List<Integer>> result= new ArrayList<>();

        findAllCombinations(1,k,n, temp, result);
        
        return result;
    }
}