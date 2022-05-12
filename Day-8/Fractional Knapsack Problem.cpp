class Solution
{
    public:
    bool static cmp(Item &a,Item &b){
        double x = (a.value * 1.0) / (a.weight);
        double y = (b.value * 1.0) / (b.weight);
        return x > y;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double ans = 0.0;
        for(int i=0;i<n;i++){
            int w = arr[i].weight;
            int v = arr[i].value;
            double val;
            if(W >= w){
                ans += v;
                W -= w;
            }
            else{
                ans += (v * (((double)(W))/(double)(w)));
                break;
            }
        }
        return ans;
    }
        
};
