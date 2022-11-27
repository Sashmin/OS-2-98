#include <Windows.h>
#include <stdio.h>
#include <float.h>

struct ArrayToChange
{
	int arr_size;
	double* array;
	int min_elem;
	int max_elem;
	double average;
};

DWORD WINAPI min_max(LPVOID array_struct)
{
	ArrayToChange* arrToChObjPtr = static_cast<ArrayToChange*>(array_struct);
	double min = DBL_MAX;
	double max = DBL_MIN;
	double* arrPtr = arrToChObjPtr->array;

	for (int i = 0; i < arrToChObjPtr->arr_size; i++)
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

	arrToChObjPtr->max_elem = max;
	arrToChObjPtr->min_elem = min;

	return 0;
}

DWORD WINAPI average(LPVOID array_struct)
{
	ArrayToChange* arrToChObjPtr = static_cast<ArrayToChange*>(array_struct);
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

int main()
{
	ArrayToChange mainArray;

	printf("Enter the size of the array: ");
	scanf_s("%d", &mainArray.arr_size);

	mainArray.array = new double[mainArray.arr_size];

	for (int i = 0; i < mainArray.arr_size; i++)
	{
		printf("Element %d: ", i + 1);
		scanf_s("%lf", &mainArray.array[i]);
	}

	printf("\n");

	HANDLE hMin_max = CreateThread(
		nullptr,
		0,
		min_max,
		&mainArray,
		0,
		nullptr
	);

	WaitForSingleObject(hMin_max, INFINITE);
	CloseHandle(hMin_max);

	printf("\n");

	HANDLE hAverage = CreateThread(
		nullptr,
		0,
		average,
		&mainArray,
		0,
		nullptr
	);

	WaitForSingleObject(hAverage, INFINITE);
	CloseHandle(hAverage);

	printf("\n");
	printf("\n");
	printf("Processed array: ");

	for (int i = 0; i < mainArray.arr_size; i++)
	{
		if (mainArray.array[i] == mainArray.max_elem ||
			mainArray.array[i] == mainArray.min_elem)
		{
			mainArray.array[i] = mainArray.average;
		}

		printf("%.2lf ", mainArray.array[i]);
	}
}

