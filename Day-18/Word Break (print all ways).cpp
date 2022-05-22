#include<bits/stdc++.h>
set<string> st;
vector<string> res;
void helper(string &s,string ans){
	if(s.length() == 0){
		ans.pop_back();
		res.push_back(ans);
		return;
	}
	for(int i=1;i<=s.length();i++){
		string left = s.substr(0,i);
		if(st.find(left) != st.end()){
			string right = s.substr(i);
			helper(right,ans + left + " ");
		}
	}
	
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
	st.clear();
	res.clear();
	for(auto x:dictionary){
		st.insert(x);
	}
	string ans = "";
	helper(s,ans);
	return res;
}