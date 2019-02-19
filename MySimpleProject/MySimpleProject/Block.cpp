#include "Block.hpp"
Block::Block(int Index, std::string PreviousHash, std::string Hash, std::string nonce, std::vector<std::string> data)
{
	std::cout << "Initializing Block " << Index << " --- Hash: s" << Hash.c_str() << std::endl;
	this->index = Index;
	this->previousHash = PreviousHash;
	this->blockHash = Hash;
	this->nonce = nonce;
	this->data = data;
	
	
}
int Block::getIndex(void)
{
	return this->index;
}
std::string Block::getHash()
{
	return this->blockHash;
}
void Block::toString()
{
	std::cout << index << std::endl;
	std::cout << blockHash << std::endl;	
}