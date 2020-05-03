/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
*/

// Solution using hashing : 

bool canConstruct(string ransomNote, string magazine) {
        int ak[300]={};
        int bk[300]={};
        for(int i=0;i<ransomNote.length();i++) ak[ransomNote[i]]++;
        for(int i=0;i<magazine.length();i++) bk[magazine[i]]++;
        for(int i=0;i<300;i++) if(ak[i]>bk[i]) return 0;
        return 1;
    }
