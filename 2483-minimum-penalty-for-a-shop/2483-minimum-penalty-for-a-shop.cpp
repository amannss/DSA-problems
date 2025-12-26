class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length() ;
        vector<int> pre(n , 0) ;
        if(customers[0] == 'N') pre[0]++ ;
        for(int i = 1; i < n ;i++)
        {
            if(customers[i] == 'N' )
            {
                pre[i]= pre[i-1] +  1 ;
            }
            else pre[i] = pre[i-1] ;
        }
        int mini; int ans = n  ; int cnt_y= 0  ;
        mini = pre[n-1] ;// itne N in whole , for 4 

        for(int j = n- 1 ;j > 0; j--)
        {   
            if(customers[j]=='Y') cnt_y++ ;
            int temp ;
            temp = cnt_y + pre[j-1] ;
            if(temp <= mini )
            {
                mini = temp ;
                ans = j ;
            }
        }
        // for j = 0 ;
        if(customers[0]=='Y') cnt_y++ ;
        if(cnt_y <= mini)
        {
            return 0 ;
        }
        return ans ;
    }
};