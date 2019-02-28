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

std::vector<std::string> Block::getData()
{
	return this->data;
}

void Block::displayblock()
{
	int i=0;
	std::cout <<"Block Index:"<< index << std::endl;
	std::cout <<"Block Hash:" << blockHash << std::endl;	
	for (std::vector<std::string>::iterator p = data.begin(); p != data.end(); p++)
	{

		std::cout <<"Transaction "<<i<<": "<< *p << std::endl;
		i++;
	}
}

nlohmann::json Block::toJSON()
{
	nlohmann::json j;
	j["index"] = this->index;
	j["hash"] = this->blockHash;
	j["previoushash"] = this->previousHash;
	j["nonce"] = this->nonce;
	j["data"] = this->data;

	return j;
}