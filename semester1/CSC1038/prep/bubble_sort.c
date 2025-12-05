int bubbleSort(int numbers[], int length)
{
	for(int i = 0; i < length; ++i)
	{
		for(int j = i + 1; j < length; ++j)
		{
			if(numbers[i] > numbers[j])
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp; 
			}
		}
	}

	printArray(numbers, length);
}