class Solution 
{
   public:
   //Function to find the maximum profit and the number of jobs done.
   static bool cmp (Job a , Job b){
      return a.profit > b.profit;
   }
   vector<int> JobScheduling(Job arr[], int n) 
   { 
      set<int> st;
      for (int i = 1 ; i<= 100 ; i++){
          st.insert(i);
      }
      
      sort(arr , arr + n , cmp);
      int ans = 0;
      int cnt =0;
      for (int i = 0 ; i<n ; i++){
          int end = arr[i].dead;
          auto it = st.upper_bound(end);
          if (it != st.begin()){
              --it;
              ans += arr[i].profit;
              cnt++;
              st.erase(*it);
          }
      }
      return {cnt , ans};
   } 
};