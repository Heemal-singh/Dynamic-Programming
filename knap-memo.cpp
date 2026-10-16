// Problem Statement:
// We are given n items, each having a weight and a value.
// We have a knapsack with capacity W.
// We have to select items such that:
// 1. Total weight does not exceed W.
// 2. Total value is maximum.
// 3. Each item can be selected only once (0/1 Knapsack).
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Constraints: n <= 100, W <= 1000
int t[102][1002];                                    //--------0/1 Knapsack---------

int knapsack(int wt[], int val[], int W, int n){

  // Base Case
  if(n==0 || W==0){
    return 0;
  }

  // Check if answer is already calculated 
  if(t[n][W] != -1){
    return t[n][W];
  }

  //Chioce diagram--------------------
  if(wt[n-1] <= W)
  {
    return t[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
  }

  // If the current item is too heavy,
  // we cannot include it, so skip it.
  else if(wt[n-1] > W)
  {
    return t[n][W] = knapsack(wt, val, W, n-1);
  }
}

int main(){
  memset(t, -1, sizeof(t));   
  // Initialize the memoization table with -1.
  // -1 means the state has not been calculated yet.


  int wt[] = {1, 3, 4, 5};
  int val[] = {1, 4, 5, 7};

  int W = 7;
  int n = sizeof(wt)/sizeof(wt[0]);

  cout << "Maximum Profit = " << knapsack(wt, val, W, n);

  return 0;
}


//readme
// wt[] = Weight of each item
// val[] = Value of each item
// W = Maximum capacity of the knapsack(bag).
// n = Number of available items
// DP = recursion + memorization.
