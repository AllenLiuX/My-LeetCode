class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //动态规划！先加满上面和下面（因为是固定的），然后向右下，每次看是加左还是加上比较小
        int n= grid[0].size();
        int m= grid.size();
        //cout<<m<<","<<n<<endl;
        for(int i=1;i<n;i++) grid[0][i]=grid[0][i-1]+ grid[0][i];
        for(int i=1;i<m;i++) grid[i][0]=grid[i-1][0]+ grid[i][0];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
              grid[i][j]=min(grid[i-1][j]+grid[i][j],grid[i][j-1]+grid[i][j]) ; 
            }
        }
        return grid[m-1][n-1];
        
    }
};