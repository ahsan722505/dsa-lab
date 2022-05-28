#include<iostream>

using namespace std;

class nArray{
	int *array;
	int n;
	int *u;
public:
	nArray(int n, int *d)
	{
		int i, entries = 1;
		this->n = n;
		u = new int[n];
		for(i=0; i<n;i++)
		{
			u[i] = d[i];
			entries *= u[i];
		}
		array = new int[entries];
	}

	int& operator () (int *dim)
	{
        cout << "called" << '\n';
		int i, index = 0, temp = 1;
		index = dim[n-1];
		for(i = n - 2; i >= 0; i--)
		{
			index += dim[i] * (temp * u[i+1]);
			temp *= u[i+1];
		}
		
		return array[index];
	}

	~nArray()
	{
		delete[] array;
		delete[] u;
	}
};

int main()
{
	int dim[] = {5, 5, 5};
	nArray arr(3, dim);
	int find[] = {4, 4, 4};
	arr(find) = 7;
	cout << arr(find);
	cout << '\n';

	int dim2[] = {4, 4, 5, 9, 1};
	int find2[] = {1, 1, 1, 1, 1};
	nArray arr2(5, dim2);
	arr2(find2) = 23;
	cout << arr2(find2);

	cout << '\n';
	int find3[] = {1, 1, 1, 5, 1};
	cout << arr2(find3);

	return 0;
}