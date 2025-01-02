class Solution {
public:
    string lastSubstring(string s) {
        vector<int> q[2];
        int step = 0;
        for(int i = 0;i < s.size();i++)
            q[0].push_back(i);
        while(q[0].size() != 1){
            step++;
            q[1].clear();
            for(int i = 0;i < q[0].size();i++){
                if(q[0][i] + step - 1 < s.size()) {
                    char max_char = q[1].size() > 0 ? s[q[1].back() + step - 1]:'0';
                    if(s[q[0][i] + step - 1] > max_char){
                        q[1] = {q[0][i]};
                    } else if(s[q[0][i] + step - 1] == max_char)
                        q[1].push_back(q[0][i]);
                }
            }
            int left = 0,max_size = 0,step1 = 0;
            q[0].clear();
            while(left < q[1].size()){
                int right = left + 1;
                while(right < q[1].size() && q[1][right] - step == q[1][right-1]){
                    right++;
                }
                if(right - left > max_size){
                    max_size = right - left;
                    step1 = step * max_size;
                    q[0]= {q[1][left]};
                } else if (right - left == max_size){
                    q[0].push_back(q[1][left]);
                }
                left = right;
            }
            step = step1;
        }
        return s.substr(q[0][0]);
    }
};