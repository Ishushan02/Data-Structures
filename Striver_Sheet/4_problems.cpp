/*

    Problem 76
    (https://leetcode.com/problems/number-of-islands/)
    200. Number of Islands

    void markIslands(vector<vector<char>> &grid, int x, int y){
        // cout << i << " , " << j << endl;
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '1'){
            return ;
        }
        // cout << x << " , " << y << endl;
        grid[x][y] = '0';
        // cout << grid[x][y] << endl;
        markIslands(grid, x+1, y);
        markIslands(grid, x, y+1);
        markIslands(grid, x-1, y);
        markIslands(grid, x, y-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count += 1;
                    markIslands(grid, i, j);
                }
            }
        }

        return count;
    }

*/

/*

    Problem 77
    (https://leetcode.com/problems/reverse-linked-list/)
    206. Reverse Linked List

    ListNode* reverseNode(ListNode* head){
        ListNode* reverse = NULL;
        ListNode* temp = head;
        while(temp){
            ListNode* nextNode = temp->next;
            temp->next = reverse;
            reverse = temp;
            temp = nextNode;
        }

        return reverse;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        return reverseNode(head);
    }
        
*/