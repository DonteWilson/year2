#include <iostream>
#include <stdio.h>


void Danger(int x)
{
	printf("Help me\n", x);
}

int main()
{
	void(*people) (int);
	people = Danger;

	people(2);

	system("pause");
	return 0;
}

