#include "pch.h"
#include "CppUnitTest.h"
#include "../QueueReconstruction/QueueReconstructor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueReconstructionTests
{
    TEST_CLASS(QueueReconstruction)
    {
    public:

        void AssertEqualVectors(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual) {
            Assert::AreEqual(expected.size(), actual.size());
            for (size_t i = 0; i < expected.size(); ++i) {
                Assert::AreEqual(expected[i][0], actual[i][0]);
                Assert::AreEqual(expected[i][1], actual[i][1]);
            }
        }

        TEST_METHOD(TestExample1)
        {
            std::vector<std::vector<int>> input = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
            std::vector<std::vector<int>> expected = { {5,0},{7,0},{5,2},{6,1},{4,4},{7,1} };
            auto result = QueueReconstructor::reconstructQueue(input);
            AssertEqualVectors(expected, result);
        }

        TEST_METHOD(TestExample2)
        {
            std::vector<std::vector<int>> input = { {6,0},{5,0},{4,0},{3,2},{2,2},{1,4} };
            std::vector<std::vector<int>> expected = { {4,0},{5,0},{2,2},{3,2},{1,4},{6,0} };
            auto result = QueueReconstructor::reconstructQueue(input);
            AssertEqualVectors(expected, result);
        }

        TEST_METHOD(TestEmpty)
        {
            std::vector<std::vector<int>> input = {};
            std::vector<std::vector<int>> expected = {};
            auto result = QueueReconstructor::reconstructQueue(input);
            AssertEqualVectors(expected, result);
        }

        TEST_METHOD(TestSingle)
        {
            std::vector<std::vector<int>> input = { {5, 0} };
            std::vector<std::vector<int>> expected = { {5, 0} };
            auto result = QueueReconstructor::reconstructQueue(input);
            AssertEqualVectors(expected, result);
        }
        TEST_METHOD(Test_Example1) {
            std::vector<std::vector<int>> input = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
            std::vector<std::vector<int>> expected = { {5,0},{7,0},{5,2},{6,1},{4,4},{7,1} };
            Assert::IsTrue(QueueReconstructor::reconstructQueue(input) == expected);
        }

        TEST_METHOD(Test_Example2) {
            std::vector<std::vector<int>> input = { {6,0},{5,0},{4,0},{3,2},{2,2},{1,4} };
            std::vector<std::vector<int>> expected = { {4,0},{5,0},{2,2},{3,2},{1,4},{6,0} };
            Assert::IsTrue(QueueReconstructor::reconstructQueue(input) == expected);
        }

        TEST_METHOD(Test_Empty) {
            std::vector<std::vector<int>> input = {};
            std::vector<std::vector<int>> expected = {};
            Assert::IsTrue(QueueReconstructor::reconstructQueue(input) == expected);
        }

        TEST_METHOD(Test_SingleElement) {
            std::vector<std::vector<int>> input = { {5,0} };
            std::vector<std::vector<int>> expected = { {5,0} };
            Assert::IsTrue(QueueReconstructor::reconstructQueue(input) == expected);
        }

        TEST_METHOD(Test_AllSameHeightZeroK) {
            std::vector<std::vector<int>> input = { {5,0},{5,0},{5,0} };
            std::vector<std::vector<int>> expected = { {5,0},{5,0},{5,0} };
            Assert::IsTrue(QueueReconstructor::reconstructQueue(input) == expected);
        }

        TEST_METHOD(Test_AllSameHeightNonZeroK) {
            std::vector<std::vector<int>> input = { {5,0},{5,1},{5,2} };
            std::vector<std::vector<int>> expected = { {5,0},{5,1},{5,2} };
            Assert::IsTrue(QueueReconstructor::reconstructQueue(input) == expected);
        }

        TEST_METHOD(Test_MaxHeightZeroK) {
            std::vector<std::vector<int>> input = { {1000000,0},{999999,0} };
            std::vector<std::vector<int>> expected = { {999999,0},{1000000,0} };
            Assert::IsTrue(QueueReconstructor::reconstructQueue(input) == expected);
        }

        TEST_METHOD(Test_ReversedInput) {
            std::vector<std::vector<int>> input = { {4,4},{6,1},{5,2},{7,1},{4,0},{7,0},{5,0} };
            std::vector<std::vector<int>> expected = { {5,0},{7,0},{5,2},{6,1},{4,4},{7,1},{4,0} };
            Assert::IsTrue(QueueReconstructor::reconstructQueue(input) == QueueReconstructor::reconstructQueue(input)); // проверка на устойчивость
        }
    };
}