class Solution {
public:
    int numRescueBoats(vector<int>& people, int lim) {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0; 
        int j = n - 1;
        int cnt = 0;  
        while(i<=j){
            if(people[i] + people[j] <= lim) i++; 
            j--; 
            cnt++; 
        }
        return cnt; 
    }
};