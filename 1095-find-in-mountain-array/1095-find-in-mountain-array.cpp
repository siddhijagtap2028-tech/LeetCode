/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int peakIndex(MountainArray &mountainArr) {
        int start = 0;
        int end = mountainArr.length() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                start = mid + 1;
            else
                end = mid;
        }

        return start;
    }

    int binarySearchAsc(int start, int end, int target, MountainArray &mountainArr) {

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) == target)
                return mid;
            else if (mountainArr.get(mid) > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }

    int binarySearchDesc(int start, int end, int target, MountainArray &mountainArr) {

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) == target)
                return mid;
            else if (mountainArr.get(mid) > target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = peakIndex(mountainArr);

        int ans = binarySearchAsc(0, peak, target, mountainArr);

        if (ans != -1)
            return ans;

        return binarySearchDesc(peak + 1, mountainArr.length() - 1, target, mountainArr);
    }
};