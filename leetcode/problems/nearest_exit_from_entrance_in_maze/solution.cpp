class Solution {
public:
    
const int inf = int(1e9 + 4);
const char block = '+';

class P{
	public:

	int x, y;

	P(int x, int y)
	{
		this-> x = x;
		this-> y = y;
	}
};

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

    vector<vector<int>> dist(104, vector<int>(104, inf));
	dist[entrance[0]][entrance[1]] = 0;
	queue<P> q;
	P start = P(entrance[0], entrance[1]);
	int n = maze.size(), m = maze[0].size();

	q.push(start);
	while(!q.empty())
	{	
		P cur = q.front();
		q.pop();
		P ary[] = {P(cur.x + 1, cur.y ), P(cur.x - 1, cur.y), P(cur.x, cur.y - 1), P(cur.x, cur.y + 1)};
        // cout << cur.x << cur.y;
		for(auto pr: ary)
		{
			if(pr.x == n || pr.x == -1 || pr.y == m || pr.y == -1 || maze[pr.x][pr.y] == block)
				continue;
			if(dist[pr.x][pr.y] > dist[cur.x][cur.y] + 1)
			{
				dist[pr.x][pr.y] = dist[cur.x][cur.y] + 1;
				q.push(pr);
			}
		}

	}
	int ans = inf;
	for(int i = 0; i < n; i++)
	{
		if(i == 0 || i == n - 1)
		{
            // cout << dist[i][j];
			for(int j = 0; j < m; j++)
				if(i != start.x || j != start.y)
					ans = min(ans, dist[i][j]);
			
		}
		else 
		{
			int j = 0;
				if(i != start.x || j != start.y)
					ans = min(ans, dist[i][j]);
            j = m - 1;
            if(i != start.x || j != start.y)
					ans = min(ans, dist[i][j]);
		}
	}
    // cout << dist[0][2];

	return (ans == inf ? -1: ans);
	
}

};