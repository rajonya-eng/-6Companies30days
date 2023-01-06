class Solution {
public:
    string getHint(string secret, string guess) {
        int cows=0,bulls=0;
        unordered_map<char,int> s,g;
        for(int i=0; i<secret.length(); i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                s[secret[i]]++;
                g[guess[i]]++;
            }

        }
        unordered_map<char,int>::iterator it;
        for(it=s.begin(); it!=s.end(); it++){
            if(g.find(it->first)!=g.end()){
                cows+=min(g[it->first],it->second);
            }
        }
        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};