#include "pch.h"
#include "CppUnitTest.h"
#include "D:\лаба313\ConsoleApplication2\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(TestCalculateY)
    {
    public:

        TEST_METHOD(TestCalculateY_NegativeX) {
            double x = -1.0;
            int n = 3;
            double expected_y = 0.0;  
            double y = calculate_y(n, x);
            Assert::AreEqual(expected_y, y);
        }

        
        TEST_METHOD(TestCalculateY_PositiveX) {
            double x = 1.0;
            int n = 2;
            double expected_y = 2.5;  
            double y = calculate_y(n, x);
            Assert::AreEqual(expected_y, y, 0.0001); 
        }

       
        TEST_METHOD(TestCalculateY_ZeroX) {
            double x = 0.0;
            int n = 1;
            double expected_y = 0.0;  
            double y = calculate_y(n, x);
            Assert::AreEqual(expected_y, y);
        }

       
    }; 
}