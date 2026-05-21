class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int it:nums){
            pq.push(it);
            if(pq.size() > K){
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};
