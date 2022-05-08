#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
	unordered_set<int> st;
	for(auto x:arr) st.insert(x);
	int ans = 1;
	for(int i=0;i<n;i++){
		int cur = arr[i];
		if(st.find(cur - 1) == st.end()){
			int len = 0;
			while(st.find(cur) != st.end()){
				cur++;
				len++;
			}
			ans = max(ans,len);
		}
	}
	return ans;
}