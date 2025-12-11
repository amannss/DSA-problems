class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int s = buildings.size() ;
        vector<int> left(n+1,INT_MAX);
        vector<int> up(n+1,INT_MAX) ;
        vector<int> right(n+1,-1) ;
        vector<int> down(n+1,-1) ;
        for(auto &it : buildings)
        {
            int i = it[0];
            int j = it[1];
            if(left[i] >  j) left[i]= j ;
            if(up[j] > i  ) up[j] = i;
            if(right[i] < j) right[i] = j ;
            if(down[j] < i) down[j] = i;
        }
        int ans = 0;
        for(auto &it : buildings)
        {
            int i=it[0];
            int j=it[1];
            if(left[i] < j && right[i]> j && up[j] < i && down[j] > i   ) ans++ ;
        }
        return ans ;
    }
};