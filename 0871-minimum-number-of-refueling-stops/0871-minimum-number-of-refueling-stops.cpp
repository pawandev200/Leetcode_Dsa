class Solution {
public:
    int minRefuelStops(int t, int sf, vector<vector<int>>& st) {
        
        st.push_back({t, 0});
        int n = st.size();
        sort(st.begin(), st.end());
        // go on each station and take all fuel: 
        // if reaching to station required fule the fueled it and cnt it: 

        priority_queue<int> pq; // max heap to refuel with max fule to minimize cnt
        int lp = 0; 
        int cf = sf;
        int cnt =0; 
        
        for(int i=0; i<n; i++){
            int cp = st[i][0];
            int f = st[i][1];
            
            int disc = cp - lp; // dist of current station
            cf -= disc;
            while(cf <0 && !pq.empty()){
                cf+=pq.top();
                pq.pop();
                cnt++; 
            }
            // if don't have intermediate station, of refuelling not suff to take cs
            if(cf < 0) return -1; 

            pq.push(f);
            lp = cp; 
        }
        return cnt;  
    }
};