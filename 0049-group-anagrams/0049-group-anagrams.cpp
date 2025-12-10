class Solution {
public:
    // bool f(string s,string t){
    //     vector<int> freq(26,0);

    //     for(auto& ch : s) freq[ch - 'a']++;
    //     for(auto& ch : t) freq[ch - 'a']--;

    //     for(auto& f : freq) if(f != 0) return false;
    //     return true;
    // }

    string generateWord(string  word){
        int arr[26] = {0};

        for(auto& ch : word) arr[ch - 'a']++;

        string newWord = "";
        for(int i = 0; i < 26 ; i++){
            int freq = arr[i];
            if(freq > 0) newWord+= string(freq, i + 'a');
        }

        return newWord;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>> result;
        // vector<bool> visited(strs.size(),false);
        // for(int i = 0 ; i<strs.size();i++){
        //     if(visited[i]) continue;
        //     vector<string> group;
        //     group.push_back(strs[i]);
        //     visited[i] = true;
        //     for(int j = i+1;j<strs.size();j++){
        //         if(!visited[j] && f(strs[i],strs[j])){
        //             group.push_back(strs[j]);
        //             visited[j] = true;
        //         }
        //     }
        //     result.push_back(group);
        // }
        // return result;


        unordered_map<string,vector<string>> mp;
        // for(auto& s : strs){
        //     string key = s;
        //     sort(key.begin(),key.end());
        //     mp[key].push_back(s);
        // }

        for(auto& word : strs){
            string newWord = generateWord(word);
            mp[newWord].push_back(word);
        }

        vector<vector<string>> result;
        for(auto& key : mp){
            result.push_back(key.second);
        }
        return result;
    }
};