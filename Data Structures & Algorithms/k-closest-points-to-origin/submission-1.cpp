class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](vector<int>& a,vector<int>& b)
        {
            return a[0] < b[0];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> maxHeap;
        for (int i =0; i< points.size();i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int d = pow(x,2) + pow(y,2);
            vector<int> tmp = {d,x,y};
            maxHeap.push(tmp);
        }

        while (maxHeap.size() > k)
        {
            maxHeap.pop();
        }

        vector<vector<int>> res;
        while (!maxHeap.empty() && k >0)
        {
            vector<int> tmp = {maxHeap.top()[1],maxHeap.top()[2]};
            res.push_back(tmp);
            maxHeap.pop();
            k--;
        }
        return res;
    }
    
};
