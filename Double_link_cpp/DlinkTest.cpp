#include <iostream>
#include "DoubleLink.h"
using namespace std;

void int_test()
{
	int iarr[4] = { 10,20,30,40 };
	cout << "\n----int test----" << endl;

	//´´½¨Ë«Á´±í
	DoubleLink<int>* pdlink = new DoubleLink<int>();

	pdlink->insert(0, 20);
	pdlink->append_last(10);
	pdlink->insert_first(30);

	cout << "is empty()=" << pdlink->is_empty() << endl;

	cout << "size()=" << pdlink->size() << endl;

	int sz = pdlink->size();
	for (int i = 0; i < sz; i++)
		cout << "pdlink(" << i << ")=" << pdlink->get(i) << endl;
}

int main()
{
	int_test();
	system("pause");
}