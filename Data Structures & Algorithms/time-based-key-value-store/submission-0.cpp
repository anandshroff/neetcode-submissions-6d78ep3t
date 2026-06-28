class TimeMap {
    unordered_map<string, vector<pair<string, int>>>keyStore;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        auto values = keyStore[key];
        int l = 0;
        int h = values.size()-1;
        string result = "";

        while(l<=h){
            int mid = l + (h-l)/2;

            if(values[mid].second <= timestamp){
                result = values[mid].first;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return result;
    }
};
