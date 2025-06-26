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




*/