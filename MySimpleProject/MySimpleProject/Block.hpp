#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Block
{
public:
	Block(int Index, string PreviousHash , string Hash, string nonce);
	int getIndex(void);
	string getHash();
	//vector<string> getData();
	void toString();



private:
	int index;
	string previousHash;
	string blockHash;
	string nonce;
	//vector<string> data;


};


#endif // !BLOCK_H

