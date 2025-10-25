class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq;
        double s=0,cs=0;
        int ct=0;
        
        for(auto it:arr){
            s+=it;
            pq.push(it);
        }
        
        cs=s;
        while(cs>s/2){
            auto t=pq.top();
            pq.pop();
            cs-=t/2;
            pq.push((1.0*t)/2);
            ct++;
        }
        
        return ct;
    }
};

