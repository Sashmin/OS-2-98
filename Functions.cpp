#include <stdio.h>
#include <float.h>
#include <math.h>
#include <Windows.h>

struct ArrayToChangeF
{
	int arr_size;
	double* array;
	int min_elem;
	int max_elem;
	double average;
};

int min_max_f(ArrayToChangeF* arr_obj)
{
	double min = DBL_MAX;
	double max = DBL_MIN;
	double* arrPtr = arr_obj->array;

	for (int i = 0; i < arr_obj->arr_size; i++)
	{
		Sleep(7);
		if (arrPtr[i] < min) {
			min = arrPtr[i];
		}

		Sleep(7);
		if (arrPtr[i] > max) {
			max = arrPtr[i];
		}
	}

	printf("max element value is: %.lf \n", max);
	printf("min element value is: %.lf", min);

	arr_obj->max_elem = max;
	arr_obj->min_elem = min;

	return 0;
}

int average_f(ArrayToChangeF* arrToChObjPtr)
{
	double sum = 0;
	double* arrPtr = arrToChObjPtr->array;

	for (int i = 0; i < arrToChObjPtr->arr_size; i++) {
		sum += arrPtr[i];
	}

	double average = sum / arrToChObjPtr->arr_size;
	printf("Average of all elements in the array: %.2lf", average);

	arrToChObjPtr->average = average;

	return 0;
}