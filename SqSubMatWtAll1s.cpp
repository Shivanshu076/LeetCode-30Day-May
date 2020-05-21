// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

// Solution using Dynamic Programming :

int countSquares(vector<vector<int>>& matrix) {
    int a=0;
        
    int dp[matrix.size()+1][matrix[0].size()+1];
    for(int i=0;i<=matrix.size();i++) 
    for(int j=0;j<=matrix[0].size();j++) dp[i][j]=0;
        
    for(int i=1;i<=matrix.size();i++){
        for(int j=1;j<=matrix[0].size();j++){
            if(matrix[i-1][j-1]){
                int mn=INT_MAX;
                mn=min(mn,dp[i-1][j]);
                mn=min(mn,dp[i][j-1]);
                mn=min(mn,dp[i-1][j-1]);
                dp[i][j]= 1+mn;
                a+=dp[i][j];
            }
        }
    }
    return a;
}
