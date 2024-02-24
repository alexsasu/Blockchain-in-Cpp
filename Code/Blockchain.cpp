#include "Blockchain.hpp"

Blockchain::Blockchain(int _powStrictness) {
    blocks.push_back(Block(0, "Genesis Block"));

    powStrictness = _powStrictness;

    char charHashValidator[powStrictness + 1];
    for (int i = 0; i < powStrictness; ++i) {
        charHashValidator[i] = '0';
    }
    charHashValidator[powStrictness] = '\0';
    hashValidator = charHashValidator;
}

pair<int, double> Blockchain::AddBlock(Block block) {
    block.previousHash = GetLastBlock().GetHash();
    pair<int, double> miningInfo = block.MineBlock(powStrictness, hashValidator);
    blocks.push_back(block);

    return miningInfo;
}

Block Blockchain::GetLastBlock() const {
    return blocks.back();
}
