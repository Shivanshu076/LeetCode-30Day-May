/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
*/

// Solution using slideing window technique :

bool checkInclusion(string s1, string s2) {
    int o[26]={};
    for(int i=0;i<s1.length();i++) o[int(s1[i]-'a')]++;
    int u[26]={};
    int i=0, j=0;
    while(i<s2.length()){
        while(j-i<s1.length() && j<s2.length()){
            u[int(s2[j]-'a')]++;
            j++;
        }
        if(j-i == s1.length()){
            bool f=1;
            for(int k=0;k<26;k++){
                if(o[k]!=u[k]){f=0; break;}
            }
            if(f) return 1;
        }
        u[s2[i]-'a']--; i++;
    }
    return 0;
}
