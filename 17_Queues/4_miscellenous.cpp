/*
    1700. Number of Students Unable to Eat Lunch
    (https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int n = students.size();
        queue<int> que;
        stack<int> st;
        int sqcount = 0;
        int circcount = 0;
        reverse(sandwiches.begin(), sandwiches.end());
        for(auto v:sandwiches){
            st.push(v);
        }
        for(auto v:students){
            if(v == 1){
                sqcount++;
            }else{
                circcount++;
            }
            que.push(v);
        }

        while(!st.empty()){

            int sandwich = st.top();
            // cout << que.size() <<  " - " << sqcount <<  " - " << circcount << endl;

        
            if(sandwich == 1){
                // sqr
                if(sqcount == 0){
                    return n;
                }
            }else{
                // circ
                if(circcount == 0){
                    return n;
                }
            }

            if(sandwich == que.front()){
                if(sandwich == 1){
                    sqcount--;
                }else{
                    circcount--;
                }
                st.pop();
                n--;
            }else{
                que.push(que.front());
            }
            que.pop();

        }

        return n;


    }
*/