#pragma once

#include <cstdint>
#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;

class Block {
    private:
        int index;
        unsigned long long nonce;
        string transactionData;
        string hash;
        time_t creationTime;
        string CalculateHash() const;

    public:
        string previousHash;

        Block(int _index, const string& _transactionData);

        string GetHash();

        pair<int,double> MineBlock(int powStrictness, string hashValidator);
};
