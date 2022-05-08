#include <bits/stdc++.h> 

int merge(vector<int>&arr,int s,int mid,int e){
	int i = s, j = mid+1, k = 0;
	int temp[e - s + 2] = {0};
	int total = 0;
	for (int i = s; i <= mid; i++) {
		while (j <= e && arr[i] > 2ll * arr[j]) {
		  j++;
		}
		total += (j - (mid + 1));
	}
	i = s, j = mid+1;
	while(i<=mid and j<=e){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}
	for(int m=s;m<=e;m++){
		arr[m] = temp[m-s];
	}
	return total;
}
int mergeSort(vector<int>&arr,int s,int e){
	if(s >= e) return 0;
	int mid = (s+e)/2;
	int x = mergeSort(arr,s,mid);
	int y = mergeSort(arr,mid+1,e);
	int z = merge(arr,s,mid,e);
	return (x+y+z);
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	return mergeSort(arr,0,n-1);
}