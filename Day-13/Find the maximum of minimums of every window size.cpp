#include<bits/stdc++.h>
vector<int> getLeftSmaller(vector<int> &a,int n){
	stack<pair<int,int>> st;
	vector<int> res(n,-1);
	for(int i=n-1;i>=0;i--){
		while(!st.empty() and st.top().first > a[i]){
			res[st.top().second] = i;
			st.pop();
		}
		st.push({a[i],i});
	}
	return res;
}

vector<int> getRightSmaller(vector<int> &a,int n){
	stack<pair<int,int>> st;
	vector<int> res(n,n);
	for(int i=0;i<n;i++){
		while(!st.empty() and st.top().first > a[i]){
			res[st.top().second] = i;
			st.pop();
		}
		st.push({a[i],i});
	}
	return res;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
	vector<int> res(n,INT_MIN);
	vector<int> leftSmaller = getLeftSmaller(a,n);
	vector<int> rightSmaller = getRightSmaller(a,n);
	for(int i=0;i<n;i++){
		int idx = rightSmaller[i] - leftSmaller[i] - 2;
		res[idx] = max(res[idx],a[i]);
	}
	for(int i=n-2;i>=0;i--){
			res[i] = max(res[i],res[i+1]);
	}
	return res;
}