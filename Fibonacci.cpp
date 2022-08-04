#include<bits/stdc++.h>
using namespace std;
// Fibonacci Recursion function
int fib(int n){
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}
// Fibonacci Memoization function : Time : O(n) , Space : O(2N)
int fib(int n, vector<int> &dp){
    if(n<=1) return n; // base condition
    if(dp[n]!=-1) return dp[n]; // Using Previous Function calls
    return (dp[n]=fib(n-1,dp)+fib(n-2,dp));
}
int main(){
    int n = 6;
    // Initializing Dp vector to store values for function call
    vector<int> dp(n+1,-1);
    fib(n,dp);

    // Fibonacci Tabulation Method : Time : O(n) , Space : O(N)
    dp[0] = 0 , dp[1] = 1;
    for(int i=2;i<=n;i++) dp[i] = dp[i-1]+dp[i-2];
    cout << dp[n] << endl; // Nth fibonacci number

    // Space Optimization instead of dp array we can use prev1,prev2 varaiable
    return 0;
}