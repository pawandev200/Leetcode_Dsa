class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        vector<int> freq(26,0);
        int maxf=0, maxfc=0;
        for(char i:tasks){
            freq[i-'A']++;  // count the number of times a task needs to be done
            if(freq[i-'A']>maxf){
                maxf=freq[i-'A']; // find maximum frequency 
            }
        }   
        for(int i=0;i<26;i++){
            if(freq[i]==maxf) maxfc++; 
        }
        int time= (maxf-1)*(n+1)+maxfc; 
        return max(time,sz);
    }
};