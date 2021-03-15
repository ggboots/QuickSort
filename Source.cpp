#include <iostream>
#include <string>

using namespace std;

void display(int arr[], int arraySize)
{
	for (int i = 0; i <= arraySize - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(int a[], int low, int high)
{
	
	int pivot = a[low];
	int i = low, j = high+1;

	while (i < j)
	{
		do {
			i++;
		} while (a[i] <= pivot); // stop loop once value in a[i] > pivot

		do {
			j--;
		} while (a[j] > pivot);
		
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	
		swap(a[low], a[j]);
		
		return j;
	}

}

void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int partitionIndex = partition(a, low, high);
		quickSort(a, low, partitionIndex); // first half of split
		quickSort(a, partitionIndex + 1, high); // second half of split
	}
}

void main() {
	int a[10] = { 34,11,50,5,3,87,2,8,10,30 };
	cout << "unsorted" << endl;
	display(a, 10);
	cout << "Quick sorted" << endl;
	quickSort(a, 0, 9);
	display(a, 10);

	system("pause");
}