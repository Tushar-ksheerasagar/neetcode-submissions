class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2,nums1);
        
        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;
        while(low<=high){

            int partitionA = low + (high - low)/2;
            int partitionB = (m + n + 1)/2 - partitionA;

            int leftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1]; 
            int rightA = (partitionA == m) ? INT_MAX : nums1[partitionA]; 

            int leftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int rightB = (partitionB == n) ? INT_MAX : nums2[partitionB]; 

            if(leftA <= rightB && leftB <= rightA){
                if((m+n) % 2 == 0){
                    return (max(leftA,leftB) + min(rightA,rightB))/2.0;
                }
                else return max(leftA, leftB);
            }
            else if(leftA > rightB){
                high = partitionA - 1;
            }
            else low = partitionA + 1;
        }
        return 0.0;
    }
};
