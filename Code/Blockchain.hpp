#pragma once

#include "Block.hpp"

#include <cstdint>
#include <vector>

using namespace std;

class Blockchain {
    private:
        int powStrictness;
        string hashValidator;
        vector<Block> blocks;

        Block GetLastBlock() const;

    public:
        Blockchain(int _powStrictness);

        pair<int, double> AddBlock(Block block);
};
