#include<iostream>
#include"Block.hpp"
using namespace std;

int main()
{
	Block MyBlock=Block(1, "asdasdasdasd", "adsfasdfcvzxas", "first try to block block chain");
	cout << MyBlock.getHash() << endl;
	cout << MyBlock.getIndex() << endl;
	getchar();
	return 0;
}