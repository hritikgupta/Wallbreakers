// 852. Peak Index in a Mountain Array (https://leetcode.com/problems/peak-index-in-a-mountain-array/)
// Author: Hritik Gupta

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        if(A.size() == 0)
            return 0;
        
        int low = 0, high = A.size()-1;
        
        while(low <= high){
            int mid = low+(high-low)/2;
            
            if(mid>=1 && mid < A.size() && A[mid] > A[mid+1] && A[mid] > A[mid-1])
                return mid;
            if(mid >= 1 && A[mid] > A[mid-1])
                low = mid+1;
            else high = mid-1;
        }
        return 0;
    }
};

/*

        .
1,3,5,6,8,9,7,4,2,0
                  .   
low = 5
high = 9
mid = 7

*/