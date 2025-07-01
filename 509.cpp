// 509. Fibonacci Number

class Solution {
public:
    int fib(int n) {
        if (n<2) return n;  
        vector<int> fib(n+1);       // dp
        fib [0] = 0; fib[1] = 1;
        for (int i=2; i<=n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        } 
        return fib[n];
    }
};
// recursive:
    // int fib(int n) {
    //     if (n<2) return n; 
    //     return fib(n-1) + fib(n-2);
    // }
