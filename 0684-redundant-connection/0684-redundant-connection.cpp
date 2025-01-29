class Solution {
public:

vector<int>p;
vector<int>size;
int find(int i){
    if(i==p[i]) return i; 
    return p[i] = find(p[i]);
}
void uniteset(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;
    if(size[pa] > size[pb]){
        p[pb] = pa;
        size[pa] +=size[pb]; 
    }
    if(size[pa] <= size[pb]){
        p[pa] = pb;
        size[pb] +=size[pa]; 
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        p.resize(n+1);
        size.assign(n+1,0);
        for(int i=0; i<n; i++) p[i] = i; 

        vector<int>ans;
        for(int i=0; i<n; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int pa = find(a);
            int pb = find(b);
            if(pa == pb){
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
            else uniteset(a, b);
        }
        return ans;
    }
};