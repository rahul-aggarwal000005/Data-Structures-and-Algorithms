const int p = 3;
bool check(string &s,string &p,int i,int j){
	for(int k=i;k<j;k++){
		if(s[k] != p[k-i]) return false;
	}
	return true;
}
vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
	int n = str.length(), m = pat.length();
	vector<int> res;
	long long hashStr = 0, hashPat = 0;
	long long pow = 1;
	for(int i=0;i<m;i++){
		hashStr = hashStr + (str[i] - 'A' + 1)*pow;
		hashPat = hashPat + (pat[i] - 'A' + 1)*pow;
		pow *= p;
	}
	pow /= p;
	int i = 0;
	int j = m;
	while(j<n){
		if(hashStr == hashPat){
			if(check(str,pat,i,j)){
				res.push_back(i);
			}
		}
		hashStr -= (str[i] - 'A' + 1);
		hashStr /= p;
		hashStr += (str[j] - 'A' + 1)*pow;
		j++;
		i++;
	}
	if(hashStr == hashPat){
		if(check(str,pat,i,j)){
			res.push_back(i);
		}
	}
	return res;
}
