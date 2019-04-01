#include <iostream>
#include "Header_Files/sha256.hpp"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    string input = "Blockchaindelali";
    string output1 = sha256(input);
    cout << "sha256('"<< input << "'):"<<endl << output1 << endl;
    return 0;
}

