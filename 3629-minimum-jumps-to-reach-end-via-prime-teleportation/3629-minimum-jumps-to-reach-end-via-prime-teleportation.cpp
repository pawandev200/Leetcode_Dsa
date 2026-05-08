class Solution {
public:
    vector<int> spf;

    void buildSPF(int n) {
        spf.resize(n + 1);

        for (int i = 0; i <= n; i++) spf[i] = i;

        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    bool isPrime(int x) {
        return x >= 2 && spf[x] == x;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        buildSPF(mx);

        unordered_map<int, vector<int>> mp;

        // store indices by prime factor
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            unordered_set<int> factors;

            while (x > 1) {
                factors.insert(spf[x]);
                x /= spf[x];
            }

            for (int p : factors) {
                mp[p].push_back(i);
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1)
                return dist[i];

            // adjacent
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            // teleport
            int val = nums[i];

            if (isPrime(val) && !usedPrime.count(val)) {

                for (int nxt : mp[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[i] + 1;
                        q.push(nxt);
                    }
                }

                usedPrime.insert(val);
            }
        }

        return -1;
    }
};