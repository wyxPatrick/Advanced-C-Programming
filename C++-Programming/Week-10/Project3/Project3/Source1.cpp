int sum(const int* array, int num, int(*func)(int n))
{
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += func(array[i]);
	}
	return sum;
}