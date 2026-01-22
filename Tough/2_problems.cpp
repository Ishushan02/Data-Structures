
/*
VVI Question
(https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem)


    int ncr(int n){ //(nC2 - n(n-1)/2)
        int ans = 1;
        ans = n * (n-1) / 2;
        return ans;
    }

    int sherlockAndAnagrams(string s) {
        map<string, int> data;
        int sbs = 0;
        for(int i = 0; i < s.length();i++){
            for(int j = i; j < s.length();j++){
                sbs+=1;
                string subst = s.substr(i, j-i+1);
                sort(subst.begin(), subst.end());
                data[subst]++;
            }
        }

        // cout << " Substr " << sbs << endl;
        int ans = 0;

        for(auto each:data){
            if(each.second >= 2){
                ans += ncr(each.second);
            }
        }

        return ans;

    }
*/