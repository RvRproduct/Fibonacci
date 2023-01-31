#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Given a number N return the index value of the Fibonacci
// sequence, where the sequence is:

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 ...
// The pattern of the sequence is that each value is the sum of the 2 previous values,
// that means that for N=5 -> 2+3

int fibonacciIterative(int n);
int fibonacciIterativeV2(int n);
int fibonacciRecursive(int n);

int fibonacciIterative(int n) {
    vector<int> allFibNums;
    for (int i = 0; i < n; i++) {
        if (allFibNums.size() == 0){
            allFibNums.push_back(i);
        }
        else if (allFibNums.size() == 1) {
            allFibNums.push_back(i);
            allFibNums.push_back(i);
        }
        else
            allFibNums.push_back(allFibNums[i]+ allFibNums[i - 1]);
    }
    if (n < 2) {
        return n;
    }
    cout << "N=" << allFibNums[allFibNums.size() - 1] << "-> " << allFibNums[allFibNums.size() - 3] << "+" << allFibNums[allFibNums.size() - 2] << endl;
    return allFibNums[allFibNums.size() - 1];
    
}

int fibonacciIterativeV2(int n) {
    vector<int> allFibNums = {0, 1};
    
    for (int i = 2; i < n + 1; i++)
        allFibNums.push_back(allFibNums[i - 2] + allFibNums[i - 1]);
    return allFibNums[n];
}

int fibonacciRecursive(int n) {
    if (n < 2) {
        return n; 
    }
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int main(){
    cout << fibonacciIterative(5) << endl; // O(n)
    cout << fibonacciIterativeV2(5) << endl; // O(n)
    cout << fibonacciRecursive(5) << endl; // O(2^n)
    return 0;
}