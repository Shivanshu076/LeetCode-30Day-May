int firstBadVersion(int n) {
        if(n<=1) return n;
        int l=1, h=n;
        while(l<=h){
            int m=(l/2 + h/2);
            if(l%2 && h%2) m++;
            if(isBadVersion(m)) h=m-1;
            else l=m+1;
        }
        return l;
    }
