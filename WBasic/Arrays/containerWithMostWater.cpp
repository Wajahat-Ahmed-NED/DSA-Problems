// Brute Force Approach

int maxArea(vector<int> &height)
{
    int maxWater = 0;

    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int width = j - i;
            int h = min(height[i], height[j]);
            int area = h * width;
            maxWater = max(maxWater, area);
        }
    }

    return maxWater;
}

// Optimized Approach

int maxArea(vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;
    int w;
    int h;
    int area;
    int maxArea = 0;

    while (l < r)
    {
        w = r - l;
        h = min(height[l], height[r]);
        area = w * h;
        maxArea = max(area, maxArea);

        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return maxArea;
}