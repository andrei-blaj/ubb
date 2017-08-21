#include <stdio.h>
#include <windows.h>

int* f() 
{
	int localVar = 7;
	printf("Value of local variable in function: %d.\n", localVar);
	return &localVar;
}

int a(int x)
{
	x++;
}

int main()
{
	system("color f4");
	int* p1 = NULL;
	
	if (p1 == NULL)
		printf("p1 is NULL.\n");
	
	//// try to dereference p1 -> Error
	//printf("The value at the address pointed to by p1 is: %d", *p1);

	//// before dereferencing a pointer, always check whether or not it is null
	if (p1 != NULL)
		printf("The value at the address pointed to by p1 is: %d.\n", *p1);

	// ------------------------------------------------------------------------------------
	// Dangling pointer
	int* p2 = f();
	int x = 1;
	// any functions called will overwrite the stack storage allocated for localVar
	a(x);
	printf("p2: %d.\n", *p2);

	return 0;
}
