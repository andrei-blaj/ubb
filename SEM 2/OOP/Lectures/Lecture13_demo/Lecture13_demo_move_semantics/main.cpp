#include "DynamicVector.h"
#include <Windows.h>
#include <vector>

DynamicVector create()
{
	DynamicVector v;
	v.add(1);
	v.add(2);

	return v;
}

int main()
{
	system("color f4");

	{
		DynamicVector v1;
		v1.add(100);
		v1 = create();
	}

	system("pause");

	return 0;
}