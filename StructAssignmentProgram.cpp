#include <iostream>
#include <conio.h>

using namespace std;

struct StudentS1
{
	struct StudentS2 *p1;	
};

struct StudentS2
{
	struct StudentS3 *p2;	
};

struct StudentS3
{
	struct StudentS1 *p3;	
};

int main()
{
	// Creating Objects
	StudentS1 x;
	StudentS2 y;
	StudentS3 z;
	
	// Displaying Addresses
	cout << "Address S2: " << x.p1 << endl;
	cout << "Address S3: " << y.p2 << endl;
	cout << "Address S1: " << z.p3 << endl;
	
	return 0;
}

