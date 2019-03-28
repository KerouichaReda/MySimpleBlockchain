#include"Header_Files/Blockchain.hpp"
#include<iostream>



int main()
{

	std::cout << "Test" << std::endl;
	std::vector<std::string> mydata;
	mydata.push_back("9d6535e9ad3fa7cc87f24b4e7e18f76cbce4d9cc0aa46418aada5338196630cb");
	mydata.push_back("dd71cb1439378cc340bc464c87d3c382167efcec8420f78f1e72726fa5b47db3 ");
	mydata.push_back("2a8cd536308771fa93593a84ef1f92de821c782ea099e251a14afc93efa892f0 ");
	
	Block MyBlock = Block(563849, "00000000000000000001fbe60c55caac208cd9d1d5e318f8fe3b732c8fafc247", "0000000000000000000bb03a224520c5ef7d3270d06c0aff09f39a003033e842", "2596959192", mydata);
	MyBlock.displayblock();
	//std::string header = std::to_string(index) + prevHash + nonce;
	

	////
	//Blockchain bc(0);
	//std::cout << bc.getNumBlocks() << std::endl;
	//bc.getBlock(0).displayblock();
	//std::vector<std::string> merkel;
	//std::string previousHash = bc.getBlock(0).getHash();
	//std::pair<std::string, std::string> p = Common::findHash(1, previousHash, mydata);
	//bc.addBlock(1, previousHash, p.first, p.second, merkel);

	//std::cout << bc.getNumBlocks() << std::endl;
	//bc.getBlock(1).displayblock();
	getchar();

	return 0;
}
