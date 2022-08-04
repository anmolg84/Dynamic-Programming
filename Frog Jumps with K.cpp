#include<bits/stdc++.h>
using namespace std;

// Frog Jumps with K Recurrence function
int fun(int ind,int k,vector<int> cost){
    if(ind==0) return 0;
    int mini = INT_MAX;
    for(int i=1;i<=k;i++){
        if(ind>=j){
            int curr = fun(index-i,k,cost)+abs(cost[index]-cost[index-i]);
            mini = min(mini,curr,k,cost);
        }
    }
    return mini;
}

// Frog Jumps with K Memoization function
int fun(int ind,int k,vector<int> cost,vector<int> &dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int mini = INT_MAX;
    for(int i=1;i<=k;i++){
        if(ind>=i){
            int curr = fun(ind-i)+ abs(cost[ind]-cost[ind-i]);
            mini = min(mini,curr);
        }
    }
    return (dp[ind] = mini);
}
int main(){
    int n=5,k=2;
    vector<int> cost = {10,20,30,40,50};
    fun(n,k,cost);

    // Frog Jumps with K distance Tabulation 
    vector<int> dp(n,0);
    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i>=j){
                int curr = dp[i-j]+ abs(cost[i]-cost[i-j]);
                mini = min(mini,curr);
            }
        }
        dp[i] = mini;
    }
    cout << dp[n-1] << endl;

    // Space optimization : We can have a vector of k elements instead of n elements
    return 0;
}