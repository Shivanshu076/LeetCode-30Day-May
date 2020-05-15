/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
*/

// Solution (Kadane's algo) :


int maxSubarraySumCircular(vector<int>& A) {
    int sm=0;
    for(int i=0;i<A.size();i++) sm+=A[i];
    int mn=INT_MAX,mx=INT_MIN,a=0;
    for(int i=0;i<A.size();i++){
        a+=A[i];
        mx=max(mx,a);
        if(a<0) a=0;
    }
    a=0;
    for(int i=0;i<A.size();i++){
        a+=A[i];
        mn=min(mn,a);
        if(a>0) a=0;
    }
    cout<<mn<<" "<<mx<<endl;
    if(sm==mn && mn<0) return mx;
    return max(mx,sm-mn);
}

        int mn=INT_MAX,mx=INT_MIN,a=0;
