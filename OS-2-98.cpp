#include <Windows.h>
#include <stdio.h>

struct ArrayToChange
{
	int arr_size;
	int* array;
	int min_elem;
	int max_elem;
	double average;
};

DWORD WINAPI min_max(LPVOID array_struct)
{
	ArrayToChange* arrToChObjPtr = static_cast<ArrayToChange*>(array_struct);
	int min = INT_MAX;
	int max = INT_MIN;
	int* arrPtr = arrToChObjPtr->array;

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

	printf("max element value is: %d \n", max);
	printf("min element value is: %d", min);

	arrToChObjPtr->max_elem = max;
	arrToChObjPtr->min_elem = min;

	return 0;
}

int main()
{
	ArrayToChange mainArray;

	printf("Enter the size of the array: ");
	scanf_s("%d", &mainArray.arr_size);

	mainArray.array = new int[mainArray.arr_size];

	for (int i = 0; i < mainArray.arr_size; i++)
	{
		printf("Element %d: ", i + 1);
		scanf_s("%d", &mainArray.array[i]);
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
}

