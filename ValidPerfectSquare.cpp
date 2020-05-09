/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.
*/

// Solution (Binary Search) :

bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int l=0, r = num/2;
        while(l <= r){
            double mid = l + (r-l)/2;
            //cout << mid << endl;
            if(mid==num/mid) return true;
            if(mid> num/mid){
                r = mid-1;
            }
            else l = mid+1;
        }
        return false;
    }
