class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& q) {
        int n = nums.size();
        unordered_map<int, vector<int>>mp; // num, idxs
        for(int i=0; i<n; i++) mp[nums[i]].push_back(i);

        vector<int>ans; 
        for(int i=0; i<q.size(); i++){
            int st = q[i];
            // auto it = mp.find(nums[st]);
            // if(it!=mp.end()){
            //     if(it->second.size()==1) ans.push_back(-1);
            //     else if(it->second.size() > 1){
            //         int mind = n; 
            //         for(int j = 0; j<it->second.size(); j++){
            //             int idx = it->second[j];
            //             if(st==idx) continue; 
            //             int bd = (st - idx + n) % n;
            //             int fd = (idx - st + n) % n;
            //             mind = min(mind, min(bd, fd));
            //         }
            //         ans.push_back(mind);
            //     }
            // }
            vector<int>&vec = mp[nums[st]];
            int m = vec.size();
            if(m==1) {
                ans.push_back(-1);
                continue; 
            }
            int mind = n;
            // pos/idx of st in vector: min dist will in +-1 pos 
            int pos = lower_bound(vec.begin(), vec.end(), st) - vec.begin();
            int l = vec[(pos-1 + m)%m];
            int r = vec[(pos+1)%m];

            // circular dist: 
            int bd = (st - l + n)%n;
            int fd = (r - st + n)%n;
            mind = min(mind, min(bd, fd));
            ans.push_back(mind);
        }
        return ans; 
    }
};