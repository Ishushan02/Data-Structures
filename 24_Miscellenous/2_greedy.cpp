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