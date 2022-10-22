class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key_to_values[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        const map<int, string>& values = key_to_values[key];
        auto it = values.lower_bound(-timestamp);
        if (it == values.end()) {
            return "";
        }
        return it->second;
    }
private:
    unordered_map<string, map<int, string>> key_to_values;
};
