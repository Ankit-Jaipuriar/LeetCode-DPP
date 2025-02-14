class ProductOfNumbers {
private:
    vector<int> prefixProduct;
public:
    ProductOfNumbers() {
        prefixProduct = {1}; // Initialize with 1 to handle multiplication
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProduct = {1}; // Reset on encountering 0
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefixProduct.size();
        if (k >= size) return 0; // If k exceeds available numbers, return 0
        return prefixProduct.back() / prefixProduct[size - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */