/*
    ProblemSet : https://leetcode.com/problem-list/5ecpr1th/
*/

/*  
    994. Rotting Oranges
    (https://leetcode.com/problems/rotting-oranges/description/)

    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> que;
        int goodOrange = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    que.push({i, j});
                }else if(grid[i][j] == 1){
                    goodOrange += 1;
                }
            }
        }

        if(goodOrange == 0){
            return 0;
        }

        int timeelapsed = 0;
        while(!que.empty()){
            
            timeelapsed += 1;
            int size = que.size();

            for(int i = 0; i < size; i++){
                pair<int, int> val = que.front();
                int row = val.first;
                int col = val.second;

                if(row+1 < m && grid[row + 1][col] == 1){
                    goodOrange--;
                    grid[row + 1][col] = 2;
                    que.push({row+1, col});
                }
                if(col + 1 < n && grid[row][col+1] == 1){
                    goodOrange--;
                    grid[row ][col+ 1] = 2;
                    que.push({row, col+1});
                }
                if(row-1>= 0 && grid[row - 1][col] == 1){
                    goodOrange--;
                    grid[row - 1][col] = 2;
                    que.push({row-1, col});
                }
                if(col -1 >= 0 && grid[row][col - 1] == 1){
                    goodOrange--;
                    grid[row][col - 1] = 2;
                    que.push({row, col-1});
                }

                que.pop();
            }

            if(goodOrange == 0){
                return timeelapsed;
            }
            
        }

        if(goodOrange != 0){
            return -1;
        }

        return timeelapsed;
    }

*/