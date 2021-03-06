#include"../Header_Files/Blockchain.hpp"
#include <vector>
#include <string>
#include<memory>
#include<stdexcept>
#include<nlohmann/json.hpp>
#include"../Header_Files/Hash.hpp"
#include"../Header_Files/Common.hpp"




Blockchain::Blockchain(int genesis)
{
	if (genesis == 0)
	{
		std::vector<std::string> v;
		v.push_back("Genesis Block!");
		//string header to_string(0)+string("00000000000000") +getMerkelRoot(v)
		auto hash_nonce_pair = Common::findHash(0, std::string("00000000000000"), v);
		this->blockchain.push_back(std::make_unique<Block>(0, std::string("00000000000000"),
		hash_nonce_pair.first, hash_nonce_pair.second, v));

		std::cout << "Created Blockchain" << std::endl;

	}
}

Block Blockchain::getBlock(int index)
{
	for (unsigned int i = 0; i < blockchain.size(); i++)
	{
		if (blockchain[i]->getIndex() == index)
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
int Blockchain::addBlock(int index, std::string prevHash, std::string hash, std::string nonce,
	std::vector<std::string> &merkle)
{
	std::string header = std::to_string(index) + prevHash + Common::getMerkleRoot(merkle) + nonce;//+getMerkelRoot(merkle)
	if (!hash::sha256(header).compare(hash) && (hash.substr(0, 2) == "00") && (index == blockchain.size()))
	{
		std::cout << "Block hashes match --- Adding Block " << hash.c_str() << std::endl;
		this->blockchain.push_back(std::make_unique<Block>(index, prevHash, hash, nonce, merkle));
		return 1;
	}
	std::cout << "Hash doesn't match creteria" << std::endl;
	return 0;
}

//Return hash of the lastest block, used for finding the previousHash when mining new block
std::string Blockchain::getLatestBlockHash(void)
{
	return this->blockchain[blockchain.size() - 1]->getHash();
}

std::string Blockchain::toJSON()
{
	nlohmann::json j;
	j["length"] = this->blockchain.size();
	for (int i = 0; i < (int)this->blockchain.size(); i++)
	{
		j["data"][this->blockchain[i]->getIndex()] = this->blockchain[i]->toJSON();
	}
	return j.dump(3);
}

int Blockchain::replaceChain(nlohmann::json chain)
{
	while (this->blockchain.size() > 1)
	{
		this->blockchain.pop_back();
	}
	for (int a = 0; a < chain["data"].get<int>(); a++)
	{
		auto block = chain["data"][a];
		std::vector < std::string> data = block["data"].get < std::vector<std::string>>();
		this->addBlock(block["index"], block["previousHash"], block["hash"], block["nonce"], data);
	}
	return 1;
}
