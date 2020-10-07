class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) 
    {
        if(height.size() == 0)
		    return 0;
        int z=height.size();
        int x=height[0].size();
        int mini[z][x],left_max[z][x],right_max[z][x],breadth_max[z][x],up_max[z][x];
        for(int i=0;i<z;i++)
        {
            left_max[i][0] = height[i][0];
            for (int j = 1; j < x; j++)
            {
                left_max[i][j] = max(height[i][j], left_max[i][j-1]);
            }
            right_max[i][x-1] = height[i][x-1];
            for (int j =x- 2; j >= 0; j--) 
            {
                right_max[i][j] = max(height[i][j], right_max[i][j+1]);
            }
        }
        for(int j=0;j<x;j++)
        {
            breadth_max[0][j]=height[0][j];
            for(int i=1;i<z;i++)
               breadth_max[i][j]=max(height[i][j],breadth_max[i-1][j]); 
        }
        for(int j=0;j<x;j++)
        {
            up_max[z-1][j]=height[z-1][j];
            for(int i=z-2;i>=0;i--)
               up_max[i][j]=max(height[i][j],up_max[i+1][j]); 
        }
        int sum=0;
        for(int i=0;i<z;i++)
        {
            for(int j=0;j<x;j++)
            {
                //cout<<min(min(min(left_max[i][j],right_max[i][j]),breadth_max[i][j]),up_max[i][j])<<" ";
                sum+=min(min(min(left_max[i][j],right_max[i][j]),breadth_max[i][j]),up_max[i][j])-height[i][j];
            }
            cout<<endl;
        }
        return sum;
    }
};