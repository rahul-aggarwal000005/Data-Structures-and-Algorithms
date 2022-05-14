bool isvalid(vector<int> A, int x, int k){
    int m=A.size();
    int students=1;
    int sum=0;
    for(int i=0;i<m;i++){
        if(A[i] > x) return false;
        sum+=A[i];
        if(sum>x){
            students++;
            sum=A[i];
        }
        if(students>k) return false;
    }
    return true;
}


int Solution::books(vector<int> &A, int B) {
    int sum=0;
    int n=A.size();
    if(n<B) return -1;
    int res=-1;
    for(int i=0;i<n;i++) sum+=A[i];
    int maxB=*max_element(A.begin(),A.end());
    int l=maxB,h=sum;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(isvalid(A,mid,B)==true){
            res=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return res;
}