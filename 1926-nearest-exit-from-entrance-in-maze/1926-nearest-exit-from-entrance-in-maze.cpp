class Solution {
public:
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int rows = maze.size();
    int cols = maze[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Mark the entrance as visited and add it to the queue
    maze[entrance[0]][entrance[1]] = '+';
    q.push({entrance[0], entrance[1]});
    
    int steps = 0;
    
    while (!q.empty()) {
        int size = q.size();
        steps++;
        
        for (int k = 0; k < size; k++) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                // Check if the new cell is within bounds and not a wall
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == '.') {
                    // If it's on the border and not the entrance, return the steps
                    if (nx == 0 || nx == rows - 1 || ny == 0 || ny == cols - 1) {
                        return steps;
                    }
                    
                    // Mark as visited and add to the queue
                    maze[nx][ny] = '+';
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return -1; // No exit found
}

};