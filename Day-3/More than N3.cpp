#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
	int n = arr.size();
	int val1 = -1, val2 = -1;
	int c1 = 0, c2 = 0;
	for(int i=0;i<n;i++){
		if(c1 == 0){
			c1++;
			val1 = arr[i];
		}
		else if(val1 == arr[i]){
			c1++;
		}
		else if(c2 == 0){
			c2++;
			val2 = arr[i];
		}
		else if(val2 == arr[i]){
			c2++;
		}
		else{
			c1--;
			c2--;
		}
	}
	c1 = 0, c2 = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == val1){
			c1++;
		}
		if(arr[i] == val2){
			c2++;
		}
	}
	vector<int> ans;
	if(c1 > (n/3)){
		ans.push_back(val1);
	}
	if(c2 > (n/3)){
		ans.push_back(val2);
	}
	return ans;
}