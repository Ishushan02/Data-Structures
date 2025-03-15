/*
    Design Spreadsheet
    (https://leetcode.com//problems/design-spreadsheet/description/)

    #include <vector>
    #include <unordered_map>
    using namespace std;
    class Spreadsheet {
    public:

    vector<vector<int>> matrix;
    unordered_map<char, int> colVal;
    unordered_map<int, int> rowVal;

    Spreadsheet(int rows) {
        matrix = vector<vector<int>>(rows+1, vector<int>(26, 0));
        char c = 'A';
        for(auto i = 0; i <= 25; i++){
            colVal[c] = i;
            c++;
        }
        for(auto i = 0; i <=rows; i++){
            rowVal[i] = i;
        }
    }
    
    void setCell(string cell, int value) {
        char colchar = cell[0];
        pair<int, int> Val = getNum(cell, 1);
        int row = Val.first;

        int col = colVal[colchar];
        // cout << row <<", " << col << ": "<< "";
        matrix[row][col] = value;
        // cout << row <<", " << col << ": " << matrix[row][col] << endl;
        
    }
    
    void resetCell(string cell) {
        char colchar = cell[0];
        pair<int, int> Val = getNum(cell, 1);
        int row = Val.first;

        int col = colVal[colchar];
        matrix[row][col] = 0;
    }

    pair<int, int> getNum(string formula, int i){
        
        int ans = 0;
        while(isdigit(formula[i])){
            int n = formula[i] - '0';
            ans = (ans * 10) + n;
            i++;
        }

        return {ans, i};
    }
    
    int getValue(string formula) {
        int firstVal = 0;
        int secondVal = 0;
        // is cell
        if(isalpha(formula[1])){
            // cout << " Alphabet "<< endl;
            char colchar = formula[1];
            pair<int, int> values = getNum(formula, 2);
            int id = values.second + 1;
            int row = values.first;
            int col = colVal[colchar];
            // cout << row << ""<< colchar << endl;
            firstVal = matrix[row][col];
            // second is Num or alphabet
            if(isalpha(formula[id])){
                char colchar = formula[id];
                pair<int, int> values = getNum(formula, id+1);
                // int id = values.second + 1;
                int row = values.first;
                int col = colVal[colchar];
                // cout << row << ""<< colchar << endl;
                secondVal = matrix[row][col];
            }else{
                pair<int, int> value = getNum(formula, id);
                // cout << value.first << endl;
                secondVal = value.first;
            }
        }else{
            // number
            // cout << "Here"<< endl;
            pair<int, int> value = getNum(formula, 1);
            firstVal = value.first;
            // cout << " First is Num : "<< firstVal << endl;
            int idx = value.second + 1;
            // cout << value.first << endl;
            
            if(isalpha(formula[idx])){
                // cout << formula[idx] << endl;
                char colchar = formula[idx];
                pair<int, int> values = getNum(formula, idx+1);
                // int id = values.second + 1;
                int row = values.first;
                int col = colVal[colchar];
                // cout << row << ""<< colchar << endl;
                secondVal = matrix[row][col];
                // cout << secondVal << endl;
            }else{
                pair<int, int> values = getNum(formula, idx);
                // cout << values.first << endl;
                secondVal = values.first;
            }
        }

        return firstVal + secondVal;
        
    }
    
    };


*/