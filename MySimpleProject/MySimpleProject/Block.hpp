#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>
#include <string>

class Block
{
public:
	Block(int Index, std::string PreviousHash , std::string Hash, std::string nonce, std::vector<std::string> data);
	int getIndex(void);
	std::string getHash();
	std::vector<std::string> getData();
	void toString();



private:
	int index;
	std::string previousHash;
	std::string blockHash;
	std::string nonce;
	std::vector<std::string> data;


};


#endif // !BLOCK_H

