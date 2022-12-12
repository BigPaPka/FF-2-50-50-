#include "pch.h"
#include "CppUnitTest.h"
#include "..\FF2\FF2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
	public:

		


		TEST_METHOD(fordFulkersonTest)
		{
			Graph graph("S O 3\nS P 3\nO Q 3\nO P 2\nP R 2\nQ R 4\nQ T 2\nR T 3\n");
			Assert::AreEqual(fordFulkerson(graph, "S", "T"), 5);
		}
	};
}