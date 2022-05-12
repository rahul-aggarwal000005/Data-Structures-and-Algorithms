int findMinimumCoins(int amount) 
{
    // Write your code here
	vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	reverse(arr.begin(),arr.end());
	int ans = 0;
	for(int i=0;i<arr.size();i++){
		if(amount < arr[i]) continue;
		int cnt = amount / arr[i];
		amount -= cnt * arr[i];
		ans += cnt;
	}
	return ans;
}
