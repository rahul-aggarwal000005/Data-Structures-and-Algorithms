// Hard
class Solution {
public:
    

    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> freq;
        vector<int> ans;
        for(auto x:words){
            freq[x]++;
        }
        int n = s.length();
        int each = words[0].length();
        int total = each*words.size();
        for(int i=0;i+total<=n;i++){
            map<string,int> seen;
            for(int j=0;j<words.size();j++){
                string word = s.substr(i+each*j,each);
                if(freq.find(word) == freq.end()){
                    break;
                }
                seen[word]++;
                if(seen[word] > freq[word]){
                    break;
                }
                if(j == words.size()-1){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};