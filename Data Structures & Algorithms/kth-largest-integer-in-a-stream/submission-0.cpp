class KthLargest {
public:
    vector<int> nums;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
           
    }
    
    int add(int val) {
        priority_queue<int,vector<int>> heap(nums.begin(),nums.end());
        heap.push(val);
        nums.push_back(val);
        for (int i=0;i<k-1;i++)
        {
            heap.pop();
        }
        return heap.top();
    }
};
