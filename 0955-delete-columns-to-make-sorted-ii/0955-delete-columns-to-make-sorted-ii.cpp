class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].length() ; // 2
        int n = strs.size() ; // 5
        int deletion = 0 ;
        vector<bool> alreadySort(n-1, false ) ;
        for(int i = 0 ; i < m ; i++) // cols
        {   bool deleted = false ;
            for(int j = 0 ; j < n-1 ; j++)// rows 
            {
                if(alreadySort[j]==false && strs[j][i] > strs[j+1][i])
                {   
                    deleted = true ;
                    deletion++ ;
                    break ; 
                }
            }
            if(deleted == true ) continue ;// delte this column and moveon 
            for(int k = 0 ; k < n-1;k++)
            {
                alreadySort[k] = alreadySort[k] |  strs[k][i] < strs[k+1][i] ;
            }
        }
        return deletion ;

    }
};