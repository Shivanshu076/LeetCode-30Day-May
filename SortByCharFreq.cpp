// Given a string, sort it in decreasing order based on the frequency of characters.

// Solution using hashing and vector sorting :

static bool myc(pair<char,int> a, pair<char,int> b) return a.second>b.second;
    
string frequencySort(string s) {
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++){
        if(mp.find(s[i])==mp.end()) mp[s[i]]=1;
        else mp[s[i]]++;
    }
    vector<pair<char,int>> v;
    for(auto i=mp.begin(); i!=mp.end(); i++) v.push_back(*i);
    sort(v.begin(),v.end(),myc);
    string ss="";
    for(int i=0;i<v.size();i++) while(v[i].second--) ss+=v[i].first;
    return ss;
}
