//905. Sort Array By Parity (https://leetcode.com/problems/sort-array-by-parity/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int i = 0;
        for(int j=0; j<A.size(); j++){
            if(A[j] %2 != 0)
                continue;
            else{
                swap(A[i], A[j]);
                i++;
            }
        }
        return A;
    }
};


/*
Have 2 pointers beginning from start of vector: i, j
1) if A[j] is odd, move j forward
2) if A[j] is even, swap with A[i] and move both i and j forward

Time: O(N)
Space: O(1)

*/