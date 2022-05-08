#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
	map<char,int> mp;
	int ans = 0;
	int i = 0;
	int start = 0;
	int n = input.length();
	while(i<n){
		char cur = input[i];
		while(start < i and mp[cur] > 0){
			mp[input[start]]--;
			start++;
		}
		mp[cur]++;
		ans = max(ans,i - start + 1);
		i++;
	}
	return ans;
}