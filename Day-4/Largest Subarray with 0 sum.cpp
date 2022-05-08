#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
	int n = arr.size();
	map<int,int> mp;
	mp[0] = 0;
	int ans = 0, sum = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum == 0){
			ans = i + 1;
		}
		else if(mp.count(sum) > 0){
			int len = i - mp[sum];
// 			cout<<i<<" "<<len<<endl;
			ans = max(ans,len);
		}
		else{
			mp[sum] = i;
		}
	}
	return ans;
}