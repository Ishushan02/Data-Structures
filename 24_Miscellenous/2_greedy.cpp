/*

    Greedy Algorithm - The greedy method to choose local Optimum Solution

*/

/*

    DEFKIN Problem

*/

/*

    //(https://www.spoj.com/submit/DEFKIN/)

#include <iostream>
#include<vector>
using namespace std;

 
void dfsSolution(int i, int j, int w, int h, vector<vector<int>> &grid, vector<vector<int>> &visited, int &count){
	visited[i][j] = 1;
	grid[i][j] = 1;
	count += 1;
	
	vector<int> dx = {0,1,-1,0};
	vector<int> dy = {1,0,0,-1};
	
	for(int k = 0; k < 4; k++){
		int x = i + dx[k];
		int y = j + dy[k];
		
		if(x >= 0 && x < w && y >= 0 && y < h && visited[x][y] == 0 && grid[x][y] == 0){
			dfsSolution(x, y, w, h, grid, visited, count);
		}
	}
	
}
 
int main() {
	// your code goes here
	
	int T = 0;
	cin >> T;
	
	// cout << "Total Test Cases: " << T << endl;
	
	for(int t = 0; t < T; t++){
		int width;
		int height;
		int towers;
		
		cin>> width;
		cin>> height;
		cin>> towers;
		
		// cout << "Width: " << width << " Height: " << height << " Towers: " << towers << endl;
		
		vector<int> x_coord;
		vector<int> y_coord;
		
		for(int i = 0; i < towers; i++){
			int x;
			int y;
			cin >> x;
			cin >> y;
			x_coord.push_back(x-1);
			y_coord.push_back(y-1);
		}
		
		vector<vector<int> > grid(width, vector<int>(height, 0));
		
		for(auto coord:x_coord){
			for(int col = 0; col < height; col++){
				grid[coord][col] = 1;
			}
		}
		
		for(auto coord:y_coord){
			for(int row = 0; row < width; row++){
				grid[row][coord] = 1;
			}
		}
		
		
				
		
		// for(int i = 0; i< width; i++){
		// 	for(int j = 0; j < height; j++){
		// 		cout << grid[i][j] << " ";
		// 	}cout << endl;
		// }
		
		vector<vector<int> > visited(width, vector<int>(height, 0));
		
		int ans = 0;
		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				if(visited[i][j] == 0 && grid[i][j] == 0){
					int count = 0;
					dfsSolution(i, j, width, height, grid, visited, count);
					ans = max(count, ans);
				}
			}
		}
		
		cout << ans << endl;
		
		
		
	}
	
	return 0;
} 

*/

/*
    Huffman Encoding
    (https://www.geeksforgeeks.org/problems/huffman-encoding3345/1)

    class Node{

    public:
        pair<int, char> data;
        Node* left;
        Node* right;

        Node(pair<int, char> val){
            this->data = val;
            left = NULL;
            right = NULL;
        }
    };

    class Solution
    {   
    
	public:
	    unordered_map<char, string> ansMap;
	    vector<string> ans;
	    
	    void preOrder(Node* root, string s){
	        if(root == NULL){
	            return ;
	        }
	        
	        
	        pair<int, char> rootVal = root->data;
            if (rootVal.second) {
                ansMap[rootVal.second] = s;
                ans.push_back(s);
            }
	        preOrder(root->left, s + '0');
	        preOrder(root->right, s + '1');
	        
	    }
	    
	    struct cmp {
            bool operator()(pair<int, Node*> a, pair<int, Node*> b) {
                return a.first > b.first;
            }
        };
    	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<
		    pair<int, Node*>,
		    vector<pair<int, Node*>>,
		    cmp> que;
		    
		    for(int i = 0; i < N; i++){
		        Node* temp = new Node({f[i], S[i]});
		        que.push({f[i], temp});
		    }
		    
		    
		    while(que.size() > 1){
		      //  cout << "Here "<< endl;
		        pair<int, Node*> val1 = que.top();
		        que.pop();
		        pair<int, Node*> val2 = que.top();
		        que.pop();
		        
		        int lval = val1.first;
		        int rval = val2.first;
		        
		        
		        int value = lval + rval;
		        char c = '\0';
		        
		        Node* temp = new Node({value, c});
		        temp->left = val1.second;
		        temp->right = val2.second;
		        que.push({value, temp});
		        
		    }
		    
		    string s;
		    pair<int, Node*> val = que.top();
		    Node* root = val.second;
		    
		    preOrder(root, s);
		    
		  //  for(auto &value:ansMap){
		  //      cout << value.first << ": " << value.second << endl;
		  //  }
		  
		    
		  //  vector<string> ans;
		    
		    
		    return ans;
		    
		    
		}
    };
*/