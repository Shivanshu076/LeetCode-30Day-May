// Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

// My Solution :

int findComplement(int num) {
        int x= (int)log2(num) +1;
        x= pow(2,x)-1;
        // cout<<x<<endl;
        return ( num^x ) ;
    }
