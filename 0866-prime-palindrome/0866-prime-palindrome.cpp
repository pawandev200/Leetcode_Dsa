class Solution {
public:
    // function to check a num n is prime or not

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        if(n>=8 && n<=11) return 11; // even len palidrome 
        for(int i=1; i<=1e5; i++){
            string st = to_string(i);
            string rev = st; 
            reverse(rev.begin(), rev.end());

            string pal = st + rev.substr(1);
            int num = stoi(pal);
            if(num>=n && isPrime(num)) return num; 
        }

        return -1; 
    }
};