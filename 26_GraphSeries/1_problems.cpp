/*
    841. Keys and Rooms
    (https://leetcode.com/problems/keys-and-rooms/description/)

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> que;
        bool ans;
        unordered_map<int, bool> roomKeys;

        que.push(0);

        while(!que.empty()){
            int key = que.front();
            que.pop();

            if(roomKeys[key] == true){
                continue;
            }

            roomKeys[key] = true;
            for(auto keys:rooms[key]){
                que.push(keys);
            }

        }

        return rooms.size()==roomKeys.size();
    }
*/