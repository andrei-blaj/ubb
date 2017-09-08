#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int stringGreater(const string& a, const string& b)
{
	return a > b;
}

int main()
{
	system("color f4");

	// *******************************************************************************************************************
	// std::vector
	vector<int> integers{ 1, 2, 3, 4, 5 };
	vector<string> strings{ "Hello", ",", "you", "brilliant", "students" };

	cout << "The size of the vectors of strings is: " << strings.size() << endl;
	strings.push_back("!");
	cout << "We added another element, now the size of the vectors of strings is: " << strings.size() << endl;
	strings[5] += "!!";
	for (auto s : strings)
		cout << s << " ";
	cout << endl;

	// iterating through a vector with iterators
	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++)
		cout << *it << " ";
	cout << endl;

	// erase elements
	integers.erase(integers.begin());
	integers.erase(integers.begin() + 3);

	// insert the elements back
	integers.insert(integers.begin(), 1);
	integers.insert(integers.begin() + 4, 5);

	// *******************************************************************************************************************
	// STL algorithms
	// compute the sum of the elements from a vector

	// version 1
	int sum = 0;
	for (int i = 0; i < integers.size(); i++)
		sum += integers[i];

	// version 2
	sum = 0;
	for (const auto& el : integers) 
		sum += el;

	// version 3 - accumulate algorithm
	sum = accumulate(integers.begin(), integers.end(), 0); // accumulate - in header <numeric>

	// --------------------------------------------------------------------------------------------------------------------
	// find algorithm
	auto it = find(strings.begin(), strings.end(), "brilliant");
	*it = "amazing";

	// --------------------------------------------------------------------------------------------------------------------
	// sort algorithm
	sort(strings.begin(), strings.end());
	sort(strings.begin(), strings.end(), stringGreater);
	
	// --------------------------------------------------------------------------------------------------------------------
	// algorithms with lambdas
	int evenNumbers = count_if(integers.begin(), integers.end(), [](int x) {return x % 2 == 0; });

	vector<int> oddNumbers(5);
	auto isOdd = [](int x) { return x % 2 == 1; }; // the return type is deduced from what is returned in the function
	bool _2isOdd = isOdd(2);
	copy_if(integers.begin(), integers.end(), oddNumbers.begin(), isOdd);

	// specifying a return type for a lambda
	auto lambdaSum = [](double x, double y) -> int { return x + y; };
	cout << "Lambda sum: " << lambdaSum(1.2, 3.3) << endl;

	sort(strings.begin(), strings.end(), [](const string& a, const string& b) { return a < b; });

	for_each(integers.begin(), integers.end(), [](int x) { cout << x << " "; });

	vector<int> doublesOfIntegers(5);
	transform(integers.begin(), integers.end(), doublesOfIntegers.begin(), [](int x) { return x * 2; });

	// using capture lists
	int factor = 3;
	auto multiply = [factor](int x) { return x * factor; };		// auto multiply = [&factor](int x) { return x* factor; };
	int result = multiply(10);	// what is the value of res in the 2 cases: auto multiply = [factor](int x) { return x* factor; };     auto multiply = [&factor](int x) { return x* factor; }; ?
	factor++;
	result = multiply(10);  // what is the value of res in the 2 cases: auto multiply = [factor](int x) { return x* factor; };     auto multiply = [&factor](int x) { return x* factor; }; ?

	system("pause");
	return 0;
}
