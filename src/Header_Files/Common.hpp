#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<stdexcept>
#include"Hash.hpp"

namespace Common
{ 
std::string getMerkleRoot(const std::vector<std::string> &merkel)
{
	std::cout << "Finding Merkel Root..." << std::endl;
	if (merkel.empty())
	{
		return "";
	}
	else if (merkel.size() == 1)
	{
		return hash::sha256(merkel[0]);
	}
	std::vector < std::string> new_merkel = merkel;
	while (new_merkel.size() > 1)
	{
		if (new_merkel.size() % 2 == 1)
		{
			new_merkel.push_back(merkel.back());
		}
		std::vector<std::string> result;
		for (int i = 0; i < (int)new_merkel.size(); i += 2)
		{
			std::string var1 = hash::sha256(new_merkel[i]);
			std::string var2 = hash::sha256(new_merkel[i + 1]);
			std::string merkel_hash = hash::sha256(var1 + var2);
			result.push_back(merkel_hash);
		}
		new_merkel = result;
	}
	return new_merkel[0];
}

std::pair <std::string, std::string > findHash(int index, std::string prevHash, std::vector<std::string> &merkle)
{

	std::string header = std::to_string(index) + prevHash + getMerkleRoot(merkle);//+getMerkleRoot(merkle);
	unsigned int nonce;
	for (nonce = 0; nonce < 1000000; nonce++)
	{
		std::string blockhash = hash::sha256(header + std::to_string(nonce));
		if (blockhash.substr(0, 2) == "00")
		{
			return std::make_pair(blockhash, std::to_string(nonce));
			break;
		}
	}
	return std::make_pair("fail", "fail");
}
void print_hex(const char *label, const uint8_t *v, size_t len)
{
	size_t i;
	printf("%s: ", label);
	for ( i = 0; i < len; ++i)
	{
		printf("%02x", v[i]);
	}
	printf("\n");
}

}
#endif // !COMMON_HPP
