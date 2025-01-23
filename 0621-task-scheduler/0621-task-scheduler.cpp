class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0); // Frequency of each task (A-Z)

        // Count the frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find the maximum frequency and count how many tasks have it
        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxFreqCount = count(freq.begin(), freq.end(), maxFreq);

        // Calculate the minimum time required
        int partCount = maxFreq - 1;           // Number of "gaps" created by the most frequent task
        int partLength = n - (maxFreqCount - 1); // Slots available in each gap
        int emptySlots = partCount * partLength; // Total empty slots
        int availableTasks = tasks.size() - maxFreq * maxFreqCount; // Remaining tasks to fill gaps
        int idles = max(0, emptySlots - availableTasks); // Remaining idle slots after filling gaps

        return tasks.size() + idles; // Total intervals = tasks + idle slots
    }
};
