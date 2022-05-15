vector<vector<int>> res;
void helper(vector<int> &arr,int idx,vector<int>&temp){
	if(idx == arr.size()){
		res.push_back(temp);
		return;
	}
	helper(arr,idx+1,temp);
	temp.push_back(arr[idx]);
	helper(arr,idx+1,temp);
	temp.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    res.clear();
	vector<int> temp;
	helper(v,0,temp);
	return res;
}