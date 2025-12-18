class Solution {
public:
typedef pair<int ,int > p ;
void dijkstra(unordered_map<int , vector<p>> &adj, vector<int> &result , int src)
{
    priority_queue<p , vector<p> , greater<p>> pq ;
    pq.push({0 , src}); // w , u
    while(!pq.empty())
    {
        p tops = pq.top() ; pq.pop() ;
        int u = tops.second  ;
        int w = tops.first  ;
        for(auto &next : adj[u])
        {
            int v = next.second ;
            int dist = next.first ;
            if(dist + w < result[v])
            {
                result[v] = dist + w; 
                pq.push({dist + w , v}) ;
            }
        }
    }
    return ;
}
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int mx = 1e7 ;
        vector<int> result_src(n , mx ) ;
        vector<int> result_dest(n,mx) ;

        unordered_map<int,vector<p>> adj ;
        for(auto &it : edges)
        {
            int u=it[0] ;
            int v=it[1] ;
            int w=it[2] ;
             
            adj[u].push_back({w , v }) ;
            adj[v].push_back({w , u }) ;
        }
        result_src[0] = 0 ;
        result_dest[n-1] = 0 ;

        vector<bool> ans ;
        // calling dijkstra 2 times 
        dijkstra(adj , result_src , 0) ;
        dijkstra(adj , result_dest, n-1);
        
        
        for(auto &it  : edges)
        {
            int x = it[0];
            int y = it[1];
            int w = it[2];

            if(result_src[x] + w + result_dest[y] == result_src[n-1]) ans.push_back(true) ;
            else if(result_src[y] + w + result_dest[x] == result_src[n-1]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans ;
       
    }
};