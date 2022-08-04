#include<bits/stdc++.h>
using namespace std;

// Frog Jump Recursion function
int fun(int index,vector<int> &cost){
    if(index<=1) return 1;
    int left = fun(index-1,cost)+ abs(cost[index]-cost[index-1]);
    int right = INT_MAX;
    if(index>1) right = fun(index-2,cost)+abs(cost[index]-cost[index-2]);
    return min(left,right);
}

// Frog Jump Memoization function : Time : O(n) , Space : O(2N)
int fun(int index,vector<int> &cost,vector<int> &dp){
    if(index<=1) return 1;
    if(dp[index]!=-1) return dp[index];
    int left = fun(index-1,cost,dp)+ abs(cost[index]-cost[index-1]);
    int right = INT_MAX;
    if(index>1) right = fun(index-2,cost,dp)+abs(cost[index]-cost[index-2]);
    return (dp[index]=min(left,right));
}

int main(){
    int n = 6;
    // Initializing Dp vector to store values for function call
    vector<int> dp(n+1,-1);
    vector<int> cost = {10,20,30,10,40,20};
    fun(n,cost,dp);

    // Climbing StairsFrog Jump Tabulation Method : Time : O(n) , Space : O(N)
    dp[0] = 0;
    for(int i=1;i<n;i++) {
        int left = dp[i-1]+ abs(cost[i-1]-cost[i]);
        int right = INT_MAX;
        if(i>1) right = dp[i-2]+ abs(cost[i-2]-cost[i]);
        dp[i] = min(left,right);
    }
    cout << dp[n-1] << endl; // Total ways to get till nth staircase

    // Space Optimization instead of dp array we can use prev1,prev2 varaiable
    return 0;
}