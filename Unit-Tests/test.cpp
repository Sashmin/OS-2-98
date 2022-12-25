#include "pch.h"
#include "../../OS-2-98/Functions.cpp"

class TestArray : public ::testing::Test
{
protected:
	ArrayToChangeF* testArr;

	void SetUp()
	{
		testArr = new ArrayToChangeF;
		testArr->arr_size = 5;
		testArr->array = new double[5];
		testArr->array[0] = 2;
		testArr->array[1] = 3;
		testArr->array[2] = 6;
		testArr->array[3] = 2;
		testArr->array[4] = 2;
	}

	void TearDown()
	{
		delete[] testArr->array;
		delete testArr;
	}
};

TEST_F(TestArray, min_max_test)
{
	min_max_f(testArr);
	EXPECT_DOUBLE_EQ(testArr->max_elem, 6);
	EXPECT_DOUBLE_EQ(testArr->min_elem, 2);
}

TEST_F(TestArray, average_test)
{
	average_f(testArr);
	EXPECT_DOUBLE_EQ(testArr->average, 3);
}