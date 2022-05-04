#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	map<int,int> mp;
	for(auto x:arr){
		mp[x]++;
	}
	pair<int,int> ans;
	for(int i=1;i<=n;i++){
		if(mp[i] > 1){
			ans.second = i;
		}
		else if(mp[i] == 0){
			ans.first = i;
		}
	}
	return ans;
}
