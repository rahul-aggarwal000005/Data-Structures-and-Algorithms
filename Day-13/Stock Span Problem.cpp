class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while(!st.empty() and st.top().first <= price){
            res += st.top().second;
            st.pop();
        }
        st.push({price,res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */