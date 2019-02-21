#pragma once
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <iostream>
#include <vector>
#include <string>
#include<memory>
#include<stdexcept>
#include<nlohmann/json.hpp>
#include"Block.hpp"
#include"Common.hpp"

class Blockchain
{
public:
	Blockchain(int genesis =1);
	Block getBlocks(int index);
	//Block getBlocks(std::string hash);
	int getNumBlocks(void);
	int addBlock(int index, std::string prevHash, std::string hash, std::string nonce, std::vector < std::string >  &merkel);
	std::string getLatestBlockHash(void);
	void toString(void);
	std::string toJSON(void);
	int replaceChain(nlohmann::json chain);

private:
	std::vector<std::unique_ptr<Block>> blockchain; //vector that is the blockchain

};














#endif // !BLOCKCHAIN_H
