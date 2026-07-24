class MedianFinder {
public:
    vector<int> ans;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ans.push_back(num);
    }
    
    double findMedian() {
        sort(ans.begin(),ans.end());
        int n = ans.size();
        if(n%2==1) return ans[n/2];
        return (ans[n/2-1] + ans[n/2])/2.0;
    }
};
