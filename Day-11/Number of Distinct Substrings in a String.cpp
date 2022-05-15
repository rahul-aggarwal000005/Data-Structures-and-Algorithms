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
	}
	return crawler->eow;
}

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
	root = new Node();
	int n = s.length();
	int cnt = 1;
	for(int len=1;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			string cur = s.substr(i,len);
			if(!search(cur)){
				insert(cur);
				cnt++;
			}
		}
	}
	return cnt;
}