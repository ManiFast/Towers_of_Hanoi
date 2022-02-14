#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string path = "script.ahk";

int hanoi(int n, int i, int k);		// n = count, i = from, k = to
void f12();
void f13();
void f21();
void f23();
void f31();
void f32();

//-----------------------------------------------------------

int main()
{
	int n, i, k;
	cout << "Input n(height), from(i), to(k): ";
	cin >> n >> i >> k;

	ofstream file(path);

	if (!file.is_open()) { cout << "Error !" << endl; return -1; }
	file << "Sleep, 2000\n";
	file.close();

	//hanoi(8, 1, 2);
	hanoi(n, i, k);

	
	cout << endl; return 0;
}

//-------------------------------------------------------------

int hanoi(int n, int i, int k)
{
	//ofstream file(path, ofstream::app);
	ofstream file(path, ofstream::app);

	if (n == 1)
	{
		cout << i << " " << k << endl;
		if      (i == 1 && k == 2) f12();
		else if (i == 1 && k == 3) f13();
		else if (i == 2 && k == 1) f21();
		else if (i == 2 && k == 3) f23();
		else if (i == 3 && k == 1) f31();
		else if (i == 3 && k == 2) f32();
	}
	else
	{
		int tmp = 6 - i - k;
		hanoi(n - 1, i, tmp);
		cout << i << " " << k << endl;	// Main moment
		if      (i == 1 && k == 2) f12();
		else if (i == 1 && k == 3) f13();
		else if (i == 2 && k == 1) f21();
		else if (i == 2 && k == 3) f23();
		else if (i == 3 && k == 1) f31();
		else if (i == 3 && k == 2) f32();
		hanoi(n - 1, tmp, k);
	}

	//file << endl << "return";
	file.close();
	return 0;
}

void f12()
{
	ofstream file(path, ofstream::app);

	file << "MouseMove, 491, 429, 1\nClick\nSleep, 3" << endl;
}

void f13()
{
	ofstream file(path, ofstream::app);

	file << "MouseMove, 486, 449, 1\nClick\nSleep, 3" << endl;
}

void f21()
{
	ofstream file(path, ofstream::app);

	file << "MouseMove, 855, 438, 1\nClick\nSleep, 3" << endl;
}

void f23()
{
	ofstream file(path, ofstream::app);

	file << "MouseMove, 849, 450, 1\nClick\nSleep, 3" << endl;
}

void f31()
{
	ofstream file(path, ofstream::app);

	file << "MouseMove, 1206, 427, 1\nClick\nSleep, 3" << endl;
}

void f32()
{
	ofstream file(path, ofstream::app);

	file << "MouseMove, 1207, 448, 1\nClick\nSleep, 3" << endl;
}

//MouseMove, 800, 500, 1
//return