void insertInSorted(stack<int>&st,int val){
	if((st.empty()) || (st.top() < val)){
		st.push(val);
		return;
	}
	int x = st.top();
	st.pop();
	insertInSorted(st,val);
	st.push(x);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty() or stack.size() == 1) return;
	// Write your code here
	int val = stack.top();
	stack.pop();
	sortStack(stack);
	insertInSorted(stack,val);
}