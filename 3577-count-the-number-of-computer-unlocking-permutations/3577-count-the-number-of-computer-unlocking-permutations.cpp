class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod = 1e9 + 7 ;
        int n = complexity.size() ;
        int first = complexity[0] ;
        for(int i=1;i<n;i++)
        {
            if(first >= complexity[i]  ) return 0;
        }
        long long fact = 1 ;
        for(int i = 1;i<n ;i++)
        {
            fact = (1LL* fact * i )%mod;
        }
        return fact %mod ;
    }
};