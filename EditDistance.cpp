/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

// Solution using Dynamic Programming :

int minDistance(string s1, string s2) {
    int n=s1.length(), m=s2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(!i) dp[i][j]=j;
            else if(!j) dp[i][j]=i;
            else{
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }
                else{
                    dp[i][j]= 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
            }
        }
    }
    return dp[n][m];
}
