//#include <stdio.h>
//#include <windows.h>
//
//int main() 
//{
//	system("color f4");
//
//	int a[5]; // create an array with 5 elements
//	int b[] = { 1, 2, 3, 5, 7 };	// create and initialize array b
//
//	a[0] = 1; //index start from 0
//	a[1] = 2;
//
//	printf("a[0]=%d \n", a[0]);
//	printf("a[1]=%d \n", a[1]);
//
//	//!!! a[2] uninitialised
//	printf("a[2]=%d \n", a[2]);	// -858993460 is 0xcccccccc in hex (-858993460/0xcccccccc is the value for uninitialized int in VS).
//
//	printf("b[0]=%d \n", b[0]);
//	b[0] = 10;
//	printf("b[0]=%d \n", b[0]);
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("Address of b[%d]=%p\n", i, &b[i]);
//	}
//
//	printf("Address of b[0]: %p\n", &b[0]);
//	printf("Vector b: %p\n", b);
//	
//	printf("b[3] is %d\n", b[3]);
//	printf("Value found at address b + 3 is %d\n", *(b + 3));
//
//	system("pause");
//	return 0;
//}