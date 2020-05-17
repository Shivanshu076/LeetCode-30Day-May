/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.
*/

// Solution using sliding window technique :

vector<int> findAnagrams(string s, string p) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    int o[26]={};
    for(int i=0;i<p.length();i++) o[int(p[i]-'a')]++;
    int u[26]={};
    int i=0, j=0;
    while(i<s.length()){
        while(j-i<p.length() && j<s.length()){
            u[int(s[j]-'a')]++;
            j++;
        }
        if(j-i == p.length()){
            bool f=1;
            for(int k=0;k<26;k++){
                if(o[k]!=u[k]){f=0; break;}
            }
            if(f) v.push_back(i);
        }
        u[s[i]-'a']--; i++;
    }
    return v;
}
