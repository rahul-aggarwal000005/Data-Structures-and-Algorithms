class Node{
public:
    Node *arr[26];
    int freq;
	int eow;
    Node(){
        for(int i=0;i<26;i++){
            arr[i] = NULL;
        }
		eow = 0;
        freq = 0;
    }
};

class Trie{
	Node *root;
    public:

    Trie(){
        // Write your code here.
		root = new Node();
    }

    void insert(string &word){
        // Write your code here.
		Node *crawler = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(!crawler->arr[idx]){
                crawler->arr[idx] = new Node();
            }
            crawler = crawler->arr[idx];
			crawler->freq = crawler->freq + 1;
        }
        crawler->eow += 1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
		Node *crawler = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(!crawler->arr[idx]){
                return 0;
            }
            crawler = crawler->arr[idx];
        }
        return crawler->eow;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
		Node *crawler = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(!crawler->arr[idx]){
                return 0;
            }
            crawler = crawler->arr[idx];
        }
        return crawler->freq;
    }

    void erase(string &word){
        // Write your code here
		Node *crawler = root;
		Node *prev = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            crawler = crawler->arr[idx];
			int f = crawler->freq;
			if(f == 1){
				prev->arr[idx] = NULL;
				return;
			}
			else{
				crawler->freq = crawler->freq - 1;
			}
			prev = crawler;
        }
		crawler->eow -= 1;
    }
};
