
class Solution {
public:
    
    int parent[201], sz[201];

    int get_parent(int x)
    {
        if(parent[x] == x)  return x;
        return parent[x] = get_parent(parent[x]);
    }
    
    void group(int a, int b)
    {
        int pa = get_parent(a);
        int pb = get_parent(b);
        if(pa == pb)    return;

        if(sz[pb] > sz[pa]) 
        {
            swap(a, b);
            swap(pa, pb);
        }

        parent[pb] = pa;
        sz[pa] += sz[pb];
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();

        for(int i = 0; i < n;i++)
            parent[i] = i, sz[i] = 1;

        for(int i = 0; i < n;i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j])   group(i, j);

        int cnt = 0;
        for(int i = 0; i < n; i++)  if(parent[i] == i)  cnt++;
        return cnt;

    }
};
