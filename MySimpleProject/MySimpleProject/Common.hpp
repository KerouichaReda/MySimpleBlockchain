#ifndef COMMON_HPP
#define COMMON_HPP

#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<stdexcept>
#include"Hash.hpp"


std::pair <std::string, std::string > findHash(int index, std::string prevHash, std::vector<std::string> &merkle)
{
	std::string header = std::to_string(index) + prevHash;//getMerkelRoot(merkle);
	unsigned int nonce;
	for (nonce = 0; nonce < 10000000; nonce++)
	{
		std::string blockhash = sha256(header + std::to_string(nonce));
		if (blockhash.substr(0,2)=="00")
		{
			return std::make_pair(blockhash, std::to_string(nonce));
			break;
		}
	}
	return std::make_pair("fail", "fail");
}
#endif // !COMMON_HPP
