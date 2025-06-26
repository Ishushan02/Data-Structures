/*

Weekly Contest 400

    3168. Minimum Number of Chairs in a Waiting Room
    int minimumChairs(string s) {

        int requiredChairs = 0;
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'E'){
                if(count == 0){
                    requiredChairs += 1;
                    count = 0;
                }else{
                    count -= 1;
                }
            }else{
                count += 1;
            }
        }

        return requiredChairs;
    }


    3169. Count Days Without Meetings
    struct sortFn{
        bool operator()(vector<int>& a, vector<int> &b){
            if(a[0] < b[0]){
                return true;
            }else{
                if(a[0] == b[0]){
                    return a[1] <= b[1];
                }
                return false;
            }
        }
    };
    
    int countDays(int days, vector<vector<int>>& meetings) {
    
        sort(meetings.begin(), meetings.end(), sortFn());
        int freeDays = 0;
        int endTime = meetings[0][1];
        freeDays = 0;
        // cout << freeDays << endl;
        for(int i = 1; i < meetings.size(); i++){
            int initial = meetings[i][0];
            meetings[i][0] = max(meetings[i][0], endTime);
            endTime = max(endTime, meetings[i][1]);
            // cout << meetings[i][0] << " , " << meetings[i][1] << endl;
        }

        int prev = -1;
        for(int i = 0; i < meetings.size(); i++){
            // cout << meetings[i][0] << " , " << meetings[i][1] << endl;
            if(meetings[i][1] >= meetings[i][0] ){
                if(meetings[i][0] > prev){
                    freeDays += (meetings[i][1] - meetings[i][0] + 1);
                }else {
                    freeDays += (meetings[i][1] - meetings[i][0]);
                }
                prev = meetings[i][1];
            }
            
        }
        cout << freeDays << endl;
        return days - freeDays;
    }

*/