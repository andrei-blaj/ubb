#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("hamiltonian.in");

vector <int> v[20];
int cost[20][20];
int dp[300000][20];
int i,j,sol,n,m,x,y,c;


int main()
{
    fin>>n>>m;
    for(i=1;i<=m;++i)
    {
        fin>>x>>y>>c;
        v[y].push_back(x);
        cost[x][y]=c;
        
    }
    
    dp[1][0]=0;
    
    for(i=2;i<(1<<n);++i)
    for(j=0;j<n;++j)
    dp[i][j]=2000000000;
    
    for(i = 1; i < (1<<n); i+=2)
    {
        for(j = 1; j < n; ++j)
        {
            if((i & (1<<j)) == 0) continue;
            
            int newi= i - (1<<j);
            
            for(int k = 0; k < v[j].size(); ++k)
            {
                if( (newi & (1<<v[j][k])) >0 )
                dp[i][j] = min(dp[i][j], cost[v[j][k]][j] + dp[newi][v[j][k]]);
            }
        }
    }
    
    sol=2000000000;
    
    for(j = 1; j < n; ++j)
        if(cost[j][0] > 0)
            sol = min(sol, dp[(1<<n)-1][j] + cost[j][0]);
    
    if(sol!=2000000000)
        cout << sol << "\n";
    else
        cout << "No solution!";
    
    return 0;
}
