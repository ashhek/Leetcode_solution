class Solution {
    void seive(vector<int>&prime) {
    vector<int>isPrime(1001, true);
        isPrime[0] = false, isPrime[1] = false;
        for(int i=2; i<=1000; ++i) {
            if(isPrime[i]) {
                for(int j=i*i; j<=1000; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        for(int i=2; i<=1000; ++i) {
            if(isPrime[i]) {
                prime.push_back(i);
            }
        }
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int>prime;
        seive(prime);

        for(int i = nums.size()-2; i>=0; --i) {
            if(nums[i] < nums[i+1]) continue;
            int next = nums[i+1]; 

            bool isFound = false;
            for(int j=0; j<prime.size(); ++j) {
                if(prime[j] >= nums[i]) {
                    return false;
                }
                int temp = nums[i];
                nums[i] -= prime[j];
                if(nums[i] < next) {
                    isFound = true;
                    break;
                }
                nums[i] = temp;
            }
            if(!isFound) return false;
        }
        for(auto it : nums) cout << it << endl;
        return true;
    }
};