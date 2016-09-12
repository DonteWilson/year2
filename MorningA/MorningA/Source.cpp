#include <iostream>
//Write a function that takes another Func as a parameter. The passed function need only to add two numbers. Can the passed function be overloaded? Explain why/why not

//Answer:
// Yes, the pass function can be overloaded as long as the return type is the same. The return type is important because the if the return type is different then you can't overload the function.
//The paramter of the function does not interfere with the function being overloaded.
typedef int(*funcptr)();
int A, B;
void func(int(*f)(int))
{
	for( int A = 0;A++;)
	{
		(*f)(A);

	}
}

int add()
{
	A = 5;
	B = 6;
	return A + B;

}

int add(const int& A, const int& B)
{
	return A + B;
}
int main()
{
	int answer;
	answer = add();

	std::cout << A << " + " << B << " = " << answer <<"\n";
	

	system("pause");
	return 0;
}