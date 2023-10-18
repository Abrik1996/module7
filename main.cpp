#include "IntArray.h"
void main()
{
	IntArray* A = new IntArray(0);
	A->show();
	A->add_toend(3);
	A->add_toend(4);
	A->add_tostart(1);
	A->add_toend(5);
	A->show();
	A->add_toend(6);
	A->show();
	A->resize(10);
	A->show();
	A->resize(2);
	A->show();
	A->erase();
	IntArray* B = new IntArray(A);
	B->add_tostart(1);
	B->add_toend(6);
	B->show();
	A->show();
	B->show_index(1);
	B->show_index(2);
	B->show_index(3);
	B->show();
	std::cout << "length " << B->get_length() << std::endl;
	B->del_index(3);
	B->del_index(2);
	B->show();
	IntArray* Error2 = new IntArray(0);
	Error2->erase();
	delete Error2;
	delete A;
	delete B;
	IntArray* Test = new IntArray(0);
	Test->resize(INT_MAX);
	Test->add_toend(1);
	delete Test;
	IntArray* Test2 = new IntArray(-1);
	delete Test2;
	return;
}