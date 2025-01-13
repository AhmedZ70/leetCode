class Solution {
private:
    vector<int> mergeArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;
        
        // Traverse both arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        
        // Copy remaining elements of nums1, if any
        while (i < nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }
        
        // Copy remaining elements of nums2, if any
        while (j < nums2.size()) {
            result.push_back(nums2[j]);
            j++;
        }
        
        return result;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // merge the 2 arrays 
        // from the merged array (sorted)
        // if size is even using  %2 == 0
        //      (nums[mid] + nums[mid + 1]) / 2
        //  else return nums[mid]
        vector<int> mergedArrays = mergeArrays(nums1, nums2);
        int n = mergedArrays.size();
        int mid = n / 2;
        if (n % 2 == 0) {
            return (mergedArrays[mid - 1] + mergedArrays[mid]) / 2.0;
        } else {
            return mergedArrays[mid];
        }
    }
};