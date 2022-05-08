#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
	int cnt = 0;
	int pref = 0;
	map<int,int> mp;
	mp[0]++;
	for(int i=0;i<arr.size();i++){
		pref ^= arr[i];
		int val = pref ^ x;
		if(mp.count(val) > 0){
			cnt += mp[val];
		}
		mp[pref]++;
	}
	return cnt;
}