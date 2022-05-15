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

class Trie {
    Node *root;
    public:
    
    Trie() {
        root = new Node();
    }
    
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
    
    bool startsWith(string prefix) {
        Node *crawler = root;
        for(int i=0;i<prefix.length();i++){
            int idx = prefix[i] - 'a';
            if(!crawler->arr[idx]){
                return false;
            }
            crawler = crawler->arr[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */