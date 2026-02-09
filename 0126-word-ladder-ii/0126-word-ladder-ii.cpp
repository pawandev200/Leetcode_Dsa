class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If endWord is not in the dictionary, no path exists.
        if (dict.find(endWord) == dict.end()) {
            return {};
        }

        // Parent map: child -> list of parents that are one step shorter
        unordered_map<string, vector<string>> parent_map;
        // Distance map: word -> shortest distance from beginWord
        unordered_map<string, int> dist;
        queue<string> q;

        // Initialize BFS with beginWord
        q.push(beginWord);
        dist[beginWord] = 0;
        
        int shortest_len_to_end = -1; // Stores the shortest length found to endWord
        bool found_end = false;       // Flag to indicate if endWord has been found

        // BFS to find shortest path length and build the graph of shortest path transitions
        while (!q.empty()) {
            int level_size = q.size();
            // words_to_erase_from_dict_next_level stores words that were newly added to the queue in this level.
            // These words should be removed from the dictionary after this level is processed,
            // so they are not considered again in subsequent levels (preventing longer paths).
            unordered_set<string> words_to_erase_from_dict_next_level; 

            for (int i = 0; i < level_size; ++i) {
                string curr = q.front();
                q.pop();

                // If endWord is found at this level
                if (curr == endWord) {
                    found_end = true;
                    shortest_len_to_end = dist[curr];
                    // No need to explore neighbors of endWord from this node, as we are looking for paths TO it.
                    continue; 
                }

                // Optimization: If we've already found the endWord and current path is longer, prune.
                // This is crucial: once we know the shortest length, we stop exploring paths that would exceed it.
                if (found_end && dist[curr] >= shortest_len_to_end) {
                    continue; 
                }

                // Generate all one-character-different neighbors
                string temp_curr = curr; 
                for (int j = 0; j < temp_curr.length(); ++j) {
                    char original_char = temp_curr[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == original_char) continue;
                        temp_curr[j] = ch; // Form a new word

                        // Check if the new word is in the dictionary (excluding beginWord if it's not in wordList itself, 
                        // as beginWord is handled by dist map already and shouldn't be rediscovered as a "next word")
                        if (dict.count(temp_curr)) {
                            if (dist.find(temp_curr) == dist.end()) { // New word, first time visiting it, and it's a valid word
                                dist[temp_curr] = dist[curr] + 1;
                                q.push(temp_curr);
                                parent_map[temp_curr].push_back(curr);
                                words_to_erase_from_dict_next_level.insert(temp_curr); // Mark for removal from `dict`
                            } else if (dist[temp_curr] == dist[curr] + 1) { // Already visited, but another shortest path found
                                parent_map[temp_curr].push_back(curr);
                            }
                        }
                    }
                    temp_curr[j] = original_char; // Backtrack char change
                }
            }

            // After processing the current level, remove all words that were added to the queue in THIS level
            // This prevents them from being visited again from later levels via longer paths.
            for (const string& word : words_to_erase_from_dict_next_level) {
                dict.erase(word);
            }

            // If found_end is true, we have processed all words at the shortest level to endWord.
            // Further levels would only yield longer paths. So we can break.
            if (found_end) break;
        }

        vector<vector<string>> results;
        if (!found_end) { // If endWord was not reachable
            return results;
        }

        // DFS to reconstruct all paths from endWord back to beginWord, then reverse.
        vector<string> current_path;
        function<void(string)> dfs_reconstruct = 
            [&](string word) {
            current_path.push_back(word);
            if (word == beginWord) {
                vector<string> path_copy = current_path;
                reverse(path_copy.begin(), path_copy.end()); // Reverse to get beginWord -> endWord
                results.push_back(path_copy);
            } else {
                // Explore only parent words that are exactly one step shorter
                for (const string& parent_word : parent_map[word]) {
                    if (dist.count(parent_word) && dist[parent_word] == dist[word] - 1) {
                         dfs_reconstruct(parent_word);
                    }
                }
            }
            current_path.pop_back(); // Backtrack
        };

        dfs_reconstruct(endWord);
        return results;
        
    }
};