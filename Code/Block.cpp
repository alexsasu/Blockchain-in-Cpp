#include "Block.hpp"
#include "SHA256.hpp"
#include <chrono>

Block::Block(int _index, const string& _transactionData) : index(_index), transactionData(_transactionData) {
    creationTime = time(NULL);
    nonce = 0;
}

string Block::GetHash() {
    return hash;
}

pair<int, double> Block::MineBlock(int powStrictness, string hashValidator) {
    int hashesTriedCount = 0;
    auto start_time = chrono::high_resolution_clock::now();
    do {
        ++nonce;
        hash = CalculateHash();
        ++hashesTriedCount;
    } while (hash.substr(0, powStrictness) != hashValidator);
    auto end_time = chrono::high_resolution_clock::now();
    double mineDuration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    mineDuration /= 1000000;

    cout << "Block " << index << " mined. Hash: " << hash << '\n';

    return make_pair(hashesTriedCount, mineDuration);
}

string Block::CalculateHash() const {
    stringstream ss;
    ss << index << transactionData << creationTime << nonce << previousHash;

    return sha256(ss.str());
}
