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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        auto binarySearch = [&](int left, int right, int target, bool ascending) -> int {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int midVal = mountainArr.get(mid);

                if (midVal == target) {
                    return mid;
                }
                if (ascending) {
                    if (midVal < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (midVal > target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
            return -1;
        };

        int left = 0, right = n - 1, peak = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        peak = left;

        int result = binarySearch(0, peak, target, true);
        if (result != -1) {
            return result;
        }

        return binarySearch(peak + 1, n - 1, target, false);
    }
};

// https://leetcode.com/problems/find-in-mountain-array/
