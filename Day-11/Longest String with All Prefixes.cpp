class Node{
public:
    Node *arr[26];
    bool eow;
    Node(){
        for(int i=0;i<26;i++){
            arr[i] = NULL;
        }
        eow = false;
    }
};

Node *root;
void insert(string word) {
	Node *crawler = root;
	for(int i=0;i<word.length();i++){
		int idx = word[i] - 'a';
		if(!crawler->arr[idx]){
			crawler->arr[idx] = new Node();
		}
		crawler = crawler->arr[idx];
	}
	crawler->eow = true;
}

bool search(string word) {
	Node *crawler = root;
	for(int i=0;i<word.length();i++){
		int idx = word[i] - 'a';
		if(!crawler->arr[idx]){
			return false;
		}
		crawler = crawler->arr[idx];
		if(!crawler->eow) return false;
	}
	return crawler->eow;
}
string completeString(int n, vector<string> &a){
    // Write your code here.
	root = new Node();
	sort(a.begin(),a.end(),[](string a,string b){
		return a.length() < b.length();
	});
	vector<string> ans;
	for(auto x:a){
		insert(x);
	}
	for(auto x:a){
		if(search(x)){
			ans.push_back(x);
		}
	}
	sort(ans.begin(),ans.end(),[](string a,string b){
		if(a.length() == b.length()) return a < b;
		return a.length() > b.length();
	});
	if(ans.size() == 0){
		return "None";
	}
	return ans[0];
}