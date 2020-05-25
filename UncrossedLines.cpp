/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.
*/

// This is basically the LCS problem.
// Solution using DP :

int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int n=A.size(), m=B.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(!i || !j) dp[i][j]=0;
            else{
                if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1] +1;
                else dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
