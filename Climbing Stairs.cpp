#include<bits/stdc++.h>
using namespace std;
// Climbing Stairs Recursion function
int fun(int index){
    if(index<=1) return 1;
    return fib(index-1)+fib(index-2);
}
// Climbing Stairs Memoization function : Time : O(n) , Space : O(2N)
int fun(int index, vector<int> &dp){
    if(index<=1) return index; // base condition
    if(dp[index]!=-1) return dp[index]; // Using Previous Function calls
    return (dp[index]=fib(index-1,dp)+fib(index-2,dp));
}
int main(){
    int n = 6;
    // Initializing Dp vector to store values for function call
    vector<int> dp(n+1,-1);
    fun(n,dp);

    // Climbing Stairs Tabulation Method : Time : O(n) , Space : O(N)
    dp[0] = 0 , dp[1] = 1;
    for(int i=2;i<=n;i++) dp[i] = dp[i-1]+dp[i-2];
    cout << dp[n] << endl; // Total ways to get till nth staircase

    // Space Optimization instead of dp array we can use prev1,prev2 varaiable
    return 0;
}