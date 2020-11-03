#include <stdio.h>
#define N 128

struct word
       	{
		int first;
		int len;
		long long weight;
	};

int compare(struct word t, struct word c)
{
	while (t.len > c.len)
	{
		--t.len;
//		t.weight -= 60;
		t.weight /= 3;	
	}	
	while (c.len > t.len)
	{
		--c.len;
//		c.weight -= 60;
		c.weight /= 3;	
	}	

	if (c.weight >= t.weight)
		return 1;
	else 
		return 0;
}

int main()
{
	struct word words[N/2] = {0}; 
	struct word temp = {0};
	int temp_count = 0;
	char str[N] = {'\0'};
	int num[N] = {0};
	int count = 0;

	printf("Type string: ");
	str[0] = getchar();
	num[0] = str[0];
	for (int i = 1; i < N - 1; ++i)		//read string
	{
		str[i] = getchar();
		if ( str[i-1] == ' ' || str[i] == ' ') 
			num[i] = str[i];
		if (str[i] == '\0' || str[i] == '\n')
		{
			num[i] = ' ';
			break;
		}
	}

	for (int i = 'A'; i <= 'z'; ++i)	// add weight and count words
	for (int j = 0; j < N; ++j) 
	{
		if (i == num[j])
		{
			words[count].first = j;
			while (num[j] != ' ')
			{
			       words[count].weight *= 3;
			       words[count].weight += str[j] - 40;
			       ++j;
			}
			words[count].len = j - words[count].first;
			++count;
		}
	}

	for (int i = count-1; i >= 0; --i)		//sort
	{
		for (int j = i; j >= 0; --j)
			if (compare(temp, words[j]))
			{
				temp = words[j];
				temp_count = j;
			}
		words[temp_count] = words[i];
		words[i] = temp;
		temp.weight = 0;
	}

	for (int i = 0; i < count; ++i)		//print words
	{
		int j = words[i].len;
		int k = words[i].first;
		while (j > 0)
		{
			putchar(str[k]);
			++k;
			--j;
		}
		printf("\n");
	}


	return 0;
}
