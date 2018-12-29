#include "Block.hpp"
Block::Block(int Index, string PreviousHash, string Hash, string nonce)
{
	cout << "Initializing Block " << Index << " --- Hash: s" << Hash.c_str() << endl;
	this->index = Index;
	this->previousHash = PreviousHash;
	this->blockHash = Hash;
	this->nonce = nonce;
	
}
int Block::getIndex(void)
{
	return this->index;
}
string Block::getHash()
{
	return this->blockHash;
}
