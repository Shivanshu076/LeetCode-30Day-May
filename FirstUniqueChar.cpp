// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Simple solution using hashing :

int firstUniqChar(string s) {
    int c[26]={};
    for(int i=0;i<s.length();i++) c[int(s[i]-'a')]++;
    for(int i=0;i<s.length();i++) if(c[int(s[i]-'a')]==1) return i;
    return -1;
}
