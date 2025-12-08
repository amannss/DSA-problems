class Solution {
public:
    int countTriples(int n) {
        
        int cnt = 0 ;
        for(int i = 1 ; i <= n ;i++)
        {   
            for(int j = 1 ; j <= n ; j++)
            {
                int a2 = i*i ;
                int b2 = j*j ;
                float c = sqrt(a2 + b2) ;
                int x = (int)c ;

                if(x == c && c>=1 && c<=n ) cnt++ ;
            }
        }
        return cnt ;
    }
};