/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
*/

// Solution :

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> ans;
    int i=0, j=0;
    while( i<A.size() && j<B.size() ){
        vector<int> v;
        int a= max(A[i][0] , B[j][0]);
        int b= min(A[i][1] , B[j][1]);
        if(a<=b){
            v.push_back(a); v.push_back(b);
            ans.push_back(v);
        }
        if(b==A[i][1]) i++;
        else j++;
    }
    return ans;
}
