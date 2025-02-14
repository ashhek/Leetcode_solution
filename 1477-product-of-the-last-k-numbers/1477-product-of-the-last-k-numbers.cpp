class ProductOfNumbers {
public:
    vector<int>nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        long long prod = 1;
        for(int i = nums.size()-1; i>=nums.size()-k && i<nums.size(); --i) {
            prod *= nums[i];
        }
        return (int)prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */