class Solution {
    vector<int> heap;

    void heapifydown(int i){
        int left=2*i+1;
        int right=2*i+2;

        int largest=i;

        if(left<heap.size() && heap[left]>heap[largest]){
            largest=left;
        }
        if(right<heap.size() && heap[right]>heap[largest]){
            largest=right;
        }

        if(largest!=i){
            swap(heap[i], heap[largest]);
            heapifydown(largest);
        }
    }

    void heapifyup(int i){
        int parent = (i-1)/2;

        if(i>0 && heap[i]>heap[parent]){
            swap(heap[i],heap[parent]);
            heapifyup(parent);
        }
    }
public:
    void insert(int i){
        heap.push_back(i);
        heapifyup(heap.size()-1);
    }

    int extractMax(){
        if(heap.empty()) return -1;

        int maxi = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty()){
          heapifydown(0);
        }

        return maxi;
    }
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            insert(nums[i]);
        }
        int ans=-1;
        while(k--){
            ans = extractMax();
        }
        return ans;
    }
};