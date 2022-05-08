#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int s = j+1;
			int e = n-1;
			while(s<e){
				int x = arr[s];
				int y = arr[e];
				int sum = arr[i] + arr[j] + x + y;
				if(sum == target){
					return "Yes";
				}
				else if(sum < target){
					while(s < e and arr[s] == x) s++;
				}
				else{
					while(s < e and arr[e] == y) e--;
				}
			}
			while(j + 1 < n && arr[j + 1] == arr[j]) ++j;
		}
		while(i + 1 < n && arr[i + 1] == arr[i]) ++i;
	}
	return "No";
}
