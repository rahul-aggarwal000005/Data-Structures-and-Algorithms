#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	int i = 0;
	int j = arr.size() - 1;
	while(i<j){
		int sum = arr[i] + arr[j];
		if(sum < s){
			i++;
		}
		else if(sum > s){
			j--;
		}
		else{
			int k = j;
			int cnt = 0;
			while(i < k and arr[k] == arr[j]){
				k--;
				cnt++;
			}
			while(cnt--){
				ans.push_back({arr[i],arr[j]});
			}
			i++;
		}
	}
	return ans;
}