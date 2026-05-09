/*
    774. Minimize Max Distance to Gas Station
    (https://leetcode.com/problems/minimize-max-distance-to-gas-station/description/)

    bool canAddGasStation(vector<int>& stations, double space, int k){
        int count = 0;
        int n = stations.size();

        for(int i = 1; i < n; i++){
            int spc = stations[i] - stations[i - 1];
            count += (int)(spc / space);
        }

        return count <= k;
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        int n = stations.size();
        double start = 0;
        double end = stations[n-1];
        double mid = (start + end)/2;
        double currAns = 0.0;
        double prevAns = 0.0;

        while(end - start > 1e-6){
            // cout << mid << endl;
            if(canAddGasStation(stations, mid, k)){
                currAns = mid;
                end = mid;
            }else{
                start = mid;
            }
            mid = (start + end)/2;
        }

        return currAns;
    }
*/