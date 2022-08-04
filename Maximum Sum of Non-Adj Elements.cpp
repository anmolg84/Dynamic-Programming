#include<bits/stdc++.h>
using namespace std;
// Maximum Sum of Non Adjacent Elements Recursive Function : Time : O(2^n)
int fun(int ind, vector<int> A){
    if(ind==0) return A[ind];
    if(ind<0) return 0;
    // Pick the element
    int pick = A[ind]+ fun(ind-2,A);
    // Not Pick the element
    int notpick = 0+ fun(ind-1,A);
    return max(pick,notpick);
}

// Maximum Sum of Non Adjacent Elements Memoization Function : Time : O(N),Space: O(2N)
int fun(int ind, vector<int> A,vector<int> &dp){
    if(ind==0) return A[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    // Pick the element
    int pick = A[ind]+ fun(ind-2,A,dp);
    // Not Pick the element
    int notpick = 0+ fun(ind-1,A,dp);
    return dp[ind] = max(pick,notpick);
}
int main(){
    vector<int> A={1,2,3,4};
    int n = A.size();
    vector<int> dp(n,-1);
    fun(n,A);
    fun(n,A,dp);
    // Tabulation Method
    dp[0] = A[0];
    for(int i=1;i<n;i++){
        int take=A[i];
        if(i>1) take+=dp[i-2];
        int nontake = 0+dp[i-1];
        dp[i] = max(take,nontake);
    }
    cout << dp[n-1] << endl;
    return 0;
}