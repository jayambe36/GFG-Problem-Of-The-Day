class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        // Freq of elements
        int MAX = *max_element(arr.begin(), arr.end());
        vector<int> freq(MAX+1, 0);
        for(int e : arr)
            freq[e]++;
        
        // Num elements divisible by D
        vector<int> numElementsDivByD(MAX+1,0);
        for(int d = 1; d <= MAX; d++)
            for(int num = d; num <= MAX; num += d)
                numElementsDivByD[d] += freq[num];
        
        // Mobius Sieve 
        vector<bool> isPrime(MAX+1, true);
        vector<int> mobius(MAX+1, 1);
        for(int p = 2; p <= MAX; p++) {
            if(isPrime[p]) {
                for(int num = p; num <= MAX; num += p) {
                    isPrime[num] = false;
                    mobius[num] *= -1;
                }
                for(int num = p*p; num <= MAX; num += p*p) 
                    mobius[num] = 0;
            }
        }
        
        // Num Co-primes = sum_1_max(mobius(d)*numElementsDivByDC2)
        int ans = 0;
        for(int d = 1; d <= MAX; d++)
            ans += mobius[d]*numElementsDivByD[d]*(numElementsDivByD[d]-1)/2;
        return ans;
    }
};

