/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<bits/stdc++.h>

int findCelebrity(int n) {
 	// Write your code here.
	stack<int> st;
	for(int i=0;i<n;i++){
		st.push(i);
	}
	while(st.size() > 1){
		int p1 = st.top(); st.pop();
		int p2 = st.top(); st.pop();
		if(knows(p1,p2)){
			st.push(p2);
		}
		else if(knows(p2,p1)){
			st.push(p1);
		}
	}
	if(st.size() == 0) return -1;
// 	cout<<st.top()<<endl;
	int pos = st.top();
	for(int i=0;i<n;i++){
		if(i != st.top() and knows(pos,i)) return -1;
		if(i != st.top() and !knows(i,pos)) return -1;
	}
	return st.top();
	
}