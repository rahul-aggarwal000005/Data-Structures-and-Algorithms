// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0;
        int j = 0;
        while(k > 1){
            if(i < n and j < m){
                if(arr1[i] < arr2[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            else if(i < n){
                i++;
            }
            else{
                j++;
            }
            k--;
        }
        int ans = INT_MAX;
        if(i < n){
            ans = min(ans,arr1[i]);
        }
        if(j < m){
            ans = min(ans,arr2[j]);
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends