#pragma once
#include <vector>
#include <algorithm>

class QueueReconstructor {
public:
    static std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
            });

        std::vector<std::vector<int>> queue;
        for (const auto& person : people) {
            queue.insert(queue.begin() + person[1], person);
        }
        return queue;
    }
};
