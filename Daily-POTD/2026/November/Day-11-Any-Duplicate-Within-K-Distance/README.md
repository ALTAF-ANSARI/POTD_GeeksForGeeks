# Any Duplicate Within K Distance

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Technique](https://img.shields.io/badge/Technique-Sliding%20Window-orange)
![Data Structure](https://img.shields.io/badge/Data%20Structure-Unordered%20Set-purple)

**Platform:** GeeksforGeeks  
**POTD Date:** November 11, 2026  
**Topics:** Array, Hashing, Sliding Window, Unordered Set  
**Solution:** [`solution.cpp`](./solution.cpp)

---

## 1. Problem Statement

Given an array of integers `arr[]` and an integer `k`, determine whether there exist two distinct indices `i` and `j` such that:

- `arr[i] == arr[j]`
- The absolute difference between their indices is at most `k`, i.e. `|i - j| <= k`.

Return `true` if such a pair exists; otherwise, return `false`.

### Example 1

**Input:**
```text
arr = [1, 5, 4, 5, 1], k = 3
```

**Output:** `true`

**Explanation:** The value `5` occurs at indices `1` and `3`. Their distance is `|3 - 1| = 2`, which is less than or equal to `k = 3`.

### Example 2

**Input:**
```text
arr = [10, 2, 3, 4, 10, 5], k = 3
```

**Output:** `false`

**Explanation:** The value `10` occurs at indices `0` and `4`. Their distance is `|4 - 0| = 4`, which is greater than `k = 3`. No other value is repeated.

### Example 3

**Input:**
```text
arr = [5, 1, 3, 2, 4], k = 3
```

**Output:** `false`

**Explanation:** All elements are distinct, so no valid pair exists.

---

## 2. Understanding the Problem

We need to find whether any value appears again within a distance of at most `k) indices.

The important point is that we do not need to compare every pair of indices. While traversing the array, we only need to remember the elements present in the previous `k` positions.

For every current element:

1. Check whether it is already present in the set.
2. If it is present, the same value appeared within the allowed distance. Return `true`.
3. Otherwise, insert it into the set.
4. If the window has moved beyond the allowed size, remove the element that is now too far behind.

This is the **Sliding Window + Hashing** technique.

---

## 3. Approach — Sliding Window Using Unordered Set

We maintain:

- `left`: the starting index of the current window.
- `right`: the index currently being processed.
- `st`: an unordered set containing the values in the active window.

### Why use an unordered set?

An `unordered_set` stores only unique values and provides average **O(1)** time for insertion, deletion, and lookup.

Therefore, we can quickly determine whether the current value has appeared in the active window.

### Algorithm

1. Initialize `left = 0) and an empty unordered set.
2. Traverse the array using `right) from `0) to `n - 1`.
3. Before inserting the current value, search for `arr[right]` in the set.
4. If it already exists, return `true`.
5. Otherwise, insert `arr[right]`.
6. If `right - left >= k`, remove `arr[left]` and increment `left`.
7. If the loop finishes without finding a duplicate, return `false`.

### Important window observation

Before processing index `right`, the set contains values from the previous at most `k` indices.

After inserting the current value, if `right - left >= k`, the element at `left` is at distance greater than `k` from the next index to be processed. We remove it to keep the window valid.

**Order matters:** Check for a duplicate before removing the oldest element. This ensures a duplicate exactly `k` positions away is still detected.

---

## 4. Dry Run

Consider Example 1:

```text
arr = [1, 5, 4, 5, 1]
k = 3
```

Initially:

- `left = 0`
- `st = {}`

| right | Current value | Set before checking | Action | Set after action |
|---:|---:|---|---|---|
| 0 | 1 | `{}` | Not found; insert 1 | `{1}` |
| 1 | 5 | `{1}` | Not found; insert 5 | `{1, 5}` |
| 2 | 4 | `{1, 5}` | Not found; insert 4 | `{1, 5, 4}` |
| 3 | 5 | `{1, 5, 4}` | 5 already exists | Return `true` |

At index `3`, the value `5` is already present in the set from index `1`.

```text
Duplicate indices: 1 and 3
Distance: |3 - 1| = 2
Allowed distance: k = 3
```

Since `2 <= 3`, a valid duplicate exists.

<badge color="success">Output: true</badge>

### Window movement illustration

```text
Index:    0   1   2   3   4
Array:    1   5   4   5   1
              ^       ^
          first 5   repeated 5

Distance = 3 - 1 = 2 <= k
```

---

## 5. C++ Solution

The implementation below follows the GeeksforGeeks function signature.

```cpp
class Solution {
public:
    bool checkWithinK(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0;
        unordered_set<int> st;

        for (int right = 0; right < n; right++) {
            if (st.find(arr[right]) != st.end()) {
                return true;
            } else {
                st.insert(arr[right]);

                if (right - left >= k) {
                    st.erase(arr[left]);
                    left++;
                }
            }
        }

        return false;
    }
};
```

### Code Explanation

| Code | Explanation |
|---|---|
| `int n = arr.size();` | Stores the number of elements. |
| `int left = 0;` | Tracks the beginning of the active window. |
| `unordered_set<int> st;` | Stores values from the recent window. |
| `for (int right = 0; right < n; right++)` | Processes every array element once. |
| `st.find(arr[right]) != st.end()` | Checks whether the current value already exists in the window. |
| `return true;` | A duplicate within distance `k` has been found. |
| `st.insert(arr[right]);` | Adds the current value to the set. |
| `right - left >= k` | Checks whether the oldest element must leave the window. |
| `st.erase(arr[left]);` | Removes the value that is too far behind. |
| `left++;` | Moves the window's starting index forward. |
| `return false;` | No valid duplicate was found. |

---

## 6. Complexity Analysis

Let `n` be the size of the array.

| Complexity | Analysis |
|---|---|
| **Time** | **O(n)** average — each element is processed once, and unordered-set operations take O(1) average time. |
| **Auxiliary Space** | **O(min(n, k))** — the set stores at most the values in the active window. |

**Note:** Unordered-set operations can take O(n) in the worst case due to hash collisions, so the theoretical worst-case time can be O(n²). The expected/average complexity is O(n).

---

## 7. Edge Cases

| Case | Input | Expected output | Reason |
|---|---|---|---|
| Single element | `[7], k = 1` | `false` | No pair of distinct indices exists. |
| All elements distinct | `[1, 2, 3, 4], k = 2` | `false` | No repeated value exists. |
| Adjacent duplicate | `[1, 2, 1], k = 1` | `false` | Distance is 2, greater than 1. |
| Duplicate exactly at distance k | `[1, 2, 3, 1], k = 3` | `true` | Distance is exactly 3. |
| Duplicate outside the window | `[1, 2, 3, 1], k = 2` | `false` | Distance is 3, greater than 2. |
| Same value repeated nearby | `[4, 4], k = 1` | `true` | Duplicate distance is 1. |

---

## 8. Key DSA Learnings

- **Sliding Window:** Maintain only the relevant range of elements instead of considering the entire processed prefix.
- **Hashing:** Use a set to check whether an element has appeared in the current window.
- **Window maintenance:** Remove elements that are no longer within the allowed index distance.
- **Efficient lookup:** An unordered set gives average O(1) search, insertion, and deletion.
- **Boundary handling:** Check for a duplicate before removing the oldest element so that distance exactly `k` is included.

### Pattern to Remember

**Duplicate within K distance → Sliding Window + Hash Set.**

This pattern is useful in problems involving nearby duplicates, repeated elements in a range, and fixed-size windows.

---

## 9. Interview Explanation

"I use a sliding window with an unordered set. The set stores the elements from the previous at most k indices. For every new element, I first check whether it is already present. If it is, then the same value exists at an index whose distance is at most k, so I return true. Otherwise, I insert the current element. I then remove the element that becomes more than k positions behind. Since every element is inserted and removed at most once, the average time complexity is O(n), and the auxiliary space complexity is O(min(n, k))."

---

## 10. Final Takeaway

Instead of comparing every pair, remember only the values that can still form a valid pair with the current index.

**Check → Insert → Remove outdated element → Move forward.**

---

[⬅ Back to November POTD](../README.md) · [GeeksforGeeks Practice](https://www.geeksforgeeks.org/problem-of-the-day/)
