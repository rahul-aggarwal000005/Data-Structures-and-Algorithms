#include <bits/stdc++.h>
#define ll long long

ll merge(ll *arr,int s,int e){
	int mid = (s+e)/2;
	int temp[e - s + 2] = {0};
	int i = s,k=0;
	int j = mid+1;
	ll count = 0;
	/*
		1 2 4 5    3 4 6 7
		1 2 
	*/
	while(i<=mid and j<=e){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			count += mid - i + 1;
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}
	for(int i=s;i<=e;i++){
		arr[i] = temp[i-s];
	}
	return count;
}

ll mergeSort(ll *arr,int s,int e){
	if(s >= e) return 0;
	int mid = (s+e)/2;
	ll x = mergeSort(arr,s,mid);
	ll y = mergeSort(arr,mid+1,e);
	ll z = merge(arr,s,e);
	return (x + y + z);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
	return mergeSort(arr,0,n-1);
}