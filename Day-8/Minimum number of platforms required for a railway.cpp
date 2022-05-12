// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second < b.second;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            int s = (arr[i]);
            int d = (dep[i]);
            v.push_back({s,1});
            v.push_back({d,2});
        }
        sort(v.begin(),v.end());
        int ans = 0;
        int cur = 0;
        for(int i=0;i<2*n;i++){
            if(v[i].second == 1){
                cur++;
            }
            else{
                cur--;
            }
            ans = max(ans,cur);
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
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends