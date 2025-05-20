#include <iostream>
#include "QueueReconstructor.h"

int main() {
    std::vector<std::vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
    std::vector<std::vector<int>> result = QueueReconstructor::reconstructQueue(people);

    for (const auto& person : result) {
        std::cout << "[" << person[0] << "," << person[1] << "] ";
    }
    return 0;
}
