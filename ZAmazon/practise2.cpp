#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solve_class(const vector<char>& a) {
    int tokens = 0;
    int coins_collected = 0;

    for (char c : a) {
        if (c == 'T') tokens++;
        else if (c == 'C') {
            if (tokens > 0) {
                coins_collected++;
            }
        }
    }
    return coins_collected;
}

int solution(string board) {
    int n = board.size();

    vector<char> cls[3];

    for (int i = 0; i < n; i++) {
        cls[i % 3].push_back(board[i]);
    }

    int ans = 0;
    for (int r = 0; r < 3; r++) {
        ans += solve_class(cls[r]);
    }
    return ans;
}



int solution2(std::vector<int> &numbers) {
    int freq[10] = {0};

    for (int num : numbers) {
        int d1 = num / 10;   
        int d2 = num % 10; 

        freq[d1]++;
        if (d2 != d1) freq[d2]++;
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans = std::max(ans, freq[i]);

    return ans;
}

int main() {
    vector<int> arr = {52, 25, 11, 52, 34, 55};
    cout << solution2(arr) << endl;
}
