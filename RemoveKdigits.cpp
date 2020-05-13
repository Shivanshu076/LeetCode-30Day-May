/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
*/

//Solution :

string removeKdigits(string num, int k) {
        int i=0;
        while(k && i<num.length()){
            // cout<<num<<endl;
            while(i==num.length()-1 && k){
                if(!i) return "0";
                num=num.substr(0,num.length()-1);
                i--;
                k--;
            }
            while(k && i>=0 && num[i+1]<num[i]){
                k--;
                num.erase(i,1);
                i--;
            }
            i++;
        }
        i=0;
        while(i<num.length() && num[i]=='0') i++;
        if(i>=num.length()) return "0";
        return num.substr(i,num.length()-i);
    }
