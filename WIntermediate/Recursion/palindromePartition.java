class Solution {
    public boolean isPalindrome(int s,int e,String st){
        while(s<e){
            if(st.charAt(s++)!=st.charAt(e--)) return false;
        }
        return true;
    }
    public void doPartition(int ind,String s,List<String> temp, List<List<String>> result){
        if(ind>=s.length()){
            result.add(new ArrayList<>(temp));
            return;
        }

        for(int i=ind;i<s.length();i++){
            if(isPalindrome(ind,i,s)){
                temp.add(s.substring(ind,i+1));
                doPartition(i+1,s,temp,result);
                temp.remove(temp.size()-1);
            }
        }
    }

    public List<List<String>> partition(String s) {
     List<String> temp=new ArrayList<>();
     List<List<String>> result=new ArrayList<>();
    
        doPartition(0,s,temp,result);
        return result;

    }
}