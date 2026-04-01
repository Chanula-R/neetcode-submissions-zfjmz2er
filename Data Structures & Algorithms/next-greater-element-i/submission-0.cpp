class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);

        unordered_map<int,int> nums1Idx;
        for (int i=0;i<nums1.size();i++)
        {
            nums1Idx[nums1[i]] = i; 
        }

        stack<int> myStack;

        for (int num : nums2)
        {
            while (!myStack.empty() && num > myStack.top())
            {
                int index = nums1Idx[myStack.top()];
                res[index] = num;
                myStack.pop();
            }
            if (nums1Idx.contains(num))
            {
                myStack.push(num);   
            }
        }
        return res;
    }
       
    
};