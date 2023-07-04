// Source: Coding Ninjas
// Link: https://www.codingninjas.com/studio/problems/sum-of-two-arrays_893186?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_4&leftPanelTab=0
#include <bits/stdc++.h> 

vector<int> reversed(vector<int>&ans){
	int s=0,e=ans.size()-1;
	while(s<e){
		swap(ans[s],ans[e]);
		s++;
		e--;
	}
	return ans;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	int i=n-1;
	int j=m-1;
	int carry=0;

	vector <int> ans;

	while(i>=0 && j>=0){
		int sum=a[i]+b[j]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		j--;
		i--;

	}

	while(i>=0){
		int sum=a[i]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
	}
	while(j>=0){
		int sum=b[j]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		j--;
	}
	
	while(carry!=0){
		int sum=carry;
		carry=sum/10;
		
		ans.push_back(sum);
	}

	return reversed(ans);



}