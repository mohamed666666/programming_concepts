#include <cstdarg>
#include <iostream>

using namespace std;

/*

double Avg(int ni, int nd, ...)
{
int i; double d=0;
va_list v; // Used to iterate over the variable parameters
va_start(v, nd); // Start the variable parameters after nd
for(i=0; i<ni; i++) d+=va_arg(v, int); // Get ni integers
for(i=0; i<nd; i++) d+=va_arg(v, double); // Get nd doubles
va_end(v); // Finalize traversal
return d/(ni+nd);
}




int main()
{
    cout << Avg(2,3, 1,1, 1.0,1.0,1.0) << endl; // 1 (Correct)
cout << Avg(3,1, 1,2,3, 4.0) << endl; // 2.5 (Correct)
cout << Avg(1,1, 1, 1.0) << endl; // 1 (Correct)
cout << Avg(1,1, 1, 1); // 0.5 (Incorrect parameter types and result)
return 0; // The above error because last integer is interpreted as double!
    return 0;
}*/




struct Length
{
	int meters;
	float centimeters;
};

int main()
{
	Length *ptr, l;

	ptr = &l;

	cout << "Enter meters: ";
	cin >> (*ptr).meters;
	cout << "Enter centimeters: ";
	cin >> (*ptr).centimeters;
	cout << "Length = " << (*ptr).meters << " meters " << (*ptr).centimeters << " centimeters";

	return 0;
}
