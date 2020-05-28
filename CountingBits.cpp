// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Solution :

vector<int> countBits(int num) {
        vector<int> v(num+1);
        v[0]=0;
        for(int i=1;i<=num;i++){
            // int a=0;
            // int x=i;
            // while(x){
            //     if(x%2) a++;
            //     x>>= 1;
            // }
            // v.push_back(a);
            v[i]= v[i&(i-1)]+1;
        }
        return v;
    }
