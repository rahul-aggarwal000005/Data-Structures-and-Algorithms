vector<int> ans;
void helper(vector<int> &arr,int N,int sum){
    if(N == 0){
        ans.push_back(sum);
        return;
    }
    helper(arr,N-1,sum+arr[N-1]);
    helper(arr,N-1,sum);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    ans.clear();
    helper(arr,N,0);
    return ans;
}