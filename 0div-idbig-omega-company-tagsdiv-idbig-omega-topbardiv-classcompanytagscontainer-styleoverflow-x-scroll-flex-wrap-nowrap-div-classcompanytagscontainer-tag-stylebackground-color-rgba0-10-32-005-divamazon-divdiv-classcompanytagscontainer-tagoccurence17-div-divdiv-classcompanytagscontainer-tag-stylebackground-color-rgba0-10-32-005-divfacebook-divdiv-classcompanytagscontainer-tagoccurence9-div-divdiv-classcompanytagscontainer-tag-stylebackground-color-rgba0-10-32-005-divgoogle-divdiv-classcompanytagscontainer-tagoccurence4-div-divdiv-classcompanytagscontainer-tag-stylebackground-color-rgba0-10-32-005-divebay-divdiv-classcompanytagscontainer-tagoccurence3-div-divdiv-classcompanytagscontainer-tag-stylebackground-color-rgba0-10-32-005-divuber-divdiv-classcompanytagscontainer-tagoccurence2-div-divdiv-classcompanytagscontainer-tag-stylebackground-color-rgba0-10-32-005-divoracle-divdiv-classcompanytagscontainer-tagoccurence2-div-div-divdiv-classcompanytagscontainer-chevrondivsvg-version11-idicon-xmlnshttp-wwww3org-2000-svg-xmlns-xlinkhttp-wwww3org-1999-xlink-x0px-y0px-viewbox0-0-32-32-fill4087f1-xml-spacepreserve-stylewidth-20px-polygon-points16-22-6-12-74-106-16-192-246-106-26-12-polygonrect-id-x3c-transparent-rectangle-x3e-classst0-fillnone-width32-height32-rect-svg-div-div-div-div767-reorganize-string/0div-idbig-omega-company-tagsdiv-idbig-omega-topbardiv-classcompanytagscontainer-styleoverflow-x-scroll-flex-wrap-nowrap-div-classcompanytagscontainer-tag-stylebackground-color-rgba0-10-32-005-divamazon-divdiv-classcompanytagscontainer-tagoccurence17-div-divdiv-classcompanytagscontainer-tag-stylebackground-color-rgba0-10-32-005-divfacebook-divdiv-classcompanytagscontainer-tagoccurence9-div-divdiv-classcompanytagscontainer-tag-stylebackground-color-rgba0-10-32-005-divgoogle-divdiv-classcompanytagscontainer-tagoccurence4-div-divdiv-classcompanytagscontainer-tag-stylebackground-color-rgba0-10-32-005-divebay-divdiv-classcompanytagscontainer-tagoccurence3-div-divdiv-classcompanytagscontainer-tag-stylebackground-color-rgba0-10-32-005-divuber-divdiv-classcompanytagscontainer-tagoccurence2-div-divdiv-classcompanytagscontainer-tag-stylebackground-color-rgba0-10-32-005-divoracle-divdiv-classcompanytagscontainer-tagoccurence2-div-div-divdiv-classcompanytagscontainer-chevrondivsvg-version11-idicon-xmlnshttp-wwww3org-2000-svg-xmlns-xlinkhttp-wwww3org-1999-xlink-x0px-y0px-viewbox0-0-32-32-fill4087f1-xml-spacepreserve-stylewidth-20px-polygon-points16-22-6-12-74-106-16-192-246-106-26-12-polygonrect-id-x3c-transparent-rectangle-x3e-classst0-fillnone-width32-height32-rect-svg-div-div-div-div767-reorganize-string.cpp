class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        map<char,int>mp;
        for(auto it:s)mp[it]++; 

        for(auto it:mp){
            pq.push({it.second, it.first});
        }
        string res;

        while(pq.size()>1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            res += top1.second;
            res += top2.second;

            top1.first--;
            top2.first--;

            if(top1.first>0) pq.push(top1);
            if(top2.first>0) pq.push(top2);
        }
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            if(tp.first>1) return "";
            else res += tp.second;
        }
        return res;
    }
};