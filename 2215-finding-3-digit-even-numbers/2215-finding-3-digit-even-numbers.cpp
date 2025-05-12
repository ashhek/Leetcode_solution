class Solution {
public:
    bool isFound(int num, map<int, int>& mp) {
        int lastDigit = num % 10;
        if (lastDigit % 2 != 0)
            return false;

        map<int, int> mp2;
        int temp = num;
        while (temp) {
            mp2[temp % 10]++;
            temp /= 10;
        }

        for (auto it : mp2) {
            if (mp[it.first] < it.second)
                return false;
        }

        return true;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int, int> mp;
        for (int digit : digits) {
            mp[digit]++;
        }
        vector<int> res;

        for (int i = 100; i <= 999; ++i) {
            if (isFound(i, mp)) {
                res.push_back(i);
            }
        }
        return res;
    }
};