
class comp {
    public:
        bool operator() (pair<string, int> &p1, pair<string, int> &p2) {
            if(p1.second < p2.second) return true;
            else if(p1.second > p2.second) return false;
            else if(p1.first < p2.first) return false;
            return true;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // step 1
        unordered_map<string, int> mp;
        for(auto word : words) {
            mp[word]++;
        }

        
        priority_queue< pair<string, int> , vector<pair<string, int>>, comp> pq;
        for(auto e : mp) {
            pq.push({e.first, e.second});
        }


        vector<string> ans;
        while(!pq.empty() && k > 0) {
            pair<string, int> s = pq.top();
            pq.pop();
            ans.push_back(s.first);
            k--;
        }

        
        return ans;
    }
};