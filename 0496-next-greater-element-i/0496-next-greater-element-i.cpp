class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); 
        vector<int>ans(n, -1);

        unordered_map<int, int>mp; // num2, idx 
        for(int i=0; i<nums2.size(); i++) mp[nums2[i]] = i; 

        for(int i=0; i<n; i++){
            int curr = nums1[i];
            auto it = mp.find(curr);
            if(it != mp.end()){
                int j = it->second; 
                // cout<<j; 
                if(j+1 >= nums2.size()) ans[i] = -1;
                for(int k = j+1; k<nums2.size(); k++){
                    if(nums2[k] > curr){
                        ans[i] = nums2[k];
                        cout<<k; 
                        break; 
                    }
                }
            } else  ans[i] = -1;
        }
        return ans; 
    }
};