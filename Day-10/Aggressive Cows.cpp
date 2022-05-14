bool check(vector<int> &arr, int dist, int c) {
	int cnt = 1;
	int last = arr[0];
	for (int i = 1; i < (arr.size()); i++) {
		int d = arr[i] - last;
		if (d >= dist) {
			cnt++;
			last = arr[i];
		}
	}
	return cnt >= c;
}

int chessTournament(vector<int> arr , int n ,  int c){
	// Write your code here
	sort(arr.begin(),arr.end());
	int s = 0;
	int e = 1e18;
	int ans = e;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (check(arr, mid, c)) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}