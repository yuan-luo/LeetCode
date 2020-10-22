class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        vector<int> dp1(height.size(), 0); // dp1[i]表示第i位的左边的最大值
        vector<int> dp2(height.size(), 0); // dp2[i]表示第i位的右边的最大值
        int mx = 0;
        for (int i = 0; i < height.size(); ++i) {
            dp1[i] = mx;
            mx = max(mx, height[i]);            
        } 
        mx = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            dp2[i] = mx;
            mx = max(mx, height[i]);            
        } 
        
        for (int i = 0; i < height.size(); ++i) {
            if (min(dp1[i], dp2[i]) - height[i] > 0)
                res += min(dp1[i], dp2[i]) - height[i]; 
        }         
        
        return res;
    }
};
