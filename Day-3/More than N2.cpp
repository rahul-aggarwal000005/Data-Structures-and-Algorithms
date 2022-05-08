#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int count = 0;
	int val = -1;
	for(int i=0;i<n;i++){
		if(count == 0){
			count++;
			val = arr[i];
		}
		else if(arr[i] == val){
			count++;
		}
		else{
			count--;
		}
	}
	int f = 0;
	for(int i=0;i<n;i++){
		if(val == arr[i]){
			f++;
		}
	}
	return f > (n/2) ? val : -1;
}