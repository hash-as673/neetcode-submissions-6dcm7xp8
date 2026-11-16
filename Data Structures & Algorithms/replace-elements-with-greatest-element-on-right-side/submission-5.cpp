#include <utility>

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int current_greatest {-1};
        for (auto i{std::ssize(arr) - 1}; i>= 0 ;--i){
            const int old_val{ std::exchange(arr[i], current_greatest)};
            current_greatest = std::max(current_greatest, old_val);
        }
        return std::move(arr);
    }
};