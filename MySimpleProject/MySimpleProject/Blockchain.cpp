#include "Blockchain.hpp"



Blockchain::Blockchain(int genesis)
{
	if (genesis == 0)
	{
		std::vector<std::string> v;
		v.push_back("Genesis Block!");
		auto hash_nonce_pair = findHash(0, std::string("00000000000000"), v);

		this->blockchain.push_back(std::make_unique<Block>(0, std::string("00000000000000"), hash_nonce_pair.first, hash_nonce_pair.second));

		std::cout << "Created Blockchain" << std::endl;
		
	}
}

Block Blockchain::getBlock(int index)
{
	for (int i = 0; i < blockchain.size(); i++)
	{
		if (blockchain[i]->getIndex()==index)
		{
			return *(blockchain[i]);
		}
	}
	throw std::invalid_argument("Index does not exist");
}

int Blockchain::getNumBlocks()
{
	return this->blockchain.size();
}

// Checks wether data fits with the right hash -> add block
int Blockchain::addBlock(int index, std::string prevHash, std::string hash, std::string nonce, std::vector<std::string> &merkle)
{
	std::string header = std::to_string(index) + prevHash + nonce;//+getMerkelRoot(merkle)
	if (!sha256(header).compare(hash) && (hash.substr(0,2)=="00") && (index==blockchain.size()))
	{
		std::cout << "Block hashes match --- Adding Block " << hash.c_str() << std::endl;
		this->blockchain.push_back(std::make_unique<Block>(index, prevHash, hash, nonce, merkle));
		return 1;
	}
	std::cout << "Hash doesn't match creteria" << std::endl;
}