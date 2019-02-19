#include<iostream>
#include"Block.hpp"


int main()
{
	std::vector<std::string> mydata;
	mydata.push_back("Transaction 1");
	mydata.push_back("Transaction 2");
	mydata.push_back("Transaction 3");
	Block MyBlock=Block(1, "asdasdasdasd", "adsfasdfcvzxas", "first try to block block chain",mydata);
	std::cout << MyBlock.getHash() << std::endl;
	std::cout << MyBlock.getIndex() << std::endl;
	getchar();
	return 0;
}