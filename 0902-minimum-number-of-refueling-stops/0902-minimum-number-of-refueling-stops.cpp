class Solution {
    vector<int> heap;

    void heapifydown(int i){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;
        
        if(left < heap.size() && heap[left] > heap[largest]){
            largest = left;
        }
        if(right < heap.size() && heap[right] > heap[largest]){
            largest = right;
        }

        if(largest != i){
            swap(heap[i], heap[largest]);
            heapifydown(largest);
        }
    }

    void heapifyup(int i){
        int parent = (i - 1) / 2;

        if(i > 0 && heap[i] > heap[parent]){
            swap(heap[i], heap[parent]);
            heapifyup(parent);
        }
    }

public:
    void insert(int val){
        heap.push_back(val);
        heapifyup(heap.size() - 1);
    }

    int extractMax(){
        if(heap.empty()) return -1;

        int maxi = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty()) {
            heapifydown(0);
        }

        return maxi;
    }

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxReach = startFuel;
        int cnt = 0;

        int i = 0;
        while(maxReach < target) {
            while(i < stations.size() && stations[i][0] <= maxReach) {
                insert(stations[i][1]);
                i++;
            }

            if(heap.empty()) return -1;
            maxReach += extractMax();
            cnt++;
        }

        return cnt;
    }
};
