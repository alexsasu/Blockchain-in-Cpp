#include "Blockchain.hpp"

int main() {
    int powStrictness;
    int blocksCount;

    cout << "Enter the strictness of the PoW mechanism (positive integer; ex: 6): ";
    cin >> powStrictness;
        if (powStrictness <= 0) {
        cout << "Invalid input: strictness of the PoW mechanism must be greater than zero" << '\n';
        return 0;
    }

    cout << "Enter the number of blocks to mine: ";
    cin >> blocksCount;
    if (blocksCount <= 0) {
        cout << "Invalid input: number of blocks must be greater than zero" << '\n';
        return 0;
    }

    cout << '\n' << '\n' << endl;

    Blockchain blockchain = Blockchain(powStrictness);
    double totalTimeSpentMining = 0;
    srand(time(NULL)); // initialize random seed for generating block transaction data

    for (int i = 1; i <= blocksCount; ++i) {
        string transactionData = "Block " + to_string(i) + " transaction data " + to_string(rand() % 10000);
        cout << "Block " << i << " data: \"" << transactionData << "\"" << '\n';
        cout << "Mining block " << i << "...\n";
        pair<int, double> miningInfo = blockchain.AddBlock(Block(i, transactionData));
        totalTimeSpentMining += miningInfo.second;
        cout << "In order to mine this block, a number of " << miningInfo.first << " hashes were tried\n";
        cout << "Mining process took: " << miningInfo.second << " seconds" << '\n' << endl;
    }

    cout << '\n' << endl;

    cout << "Finished mining\n";
    cout << "The total time spent mining was: "<< totalTimeSpentMining << " seconds\n";
    cout << "Average time spent mining on a block was: " << totalTimeSpentMining / blocksCount << " seconds";

    return 0;
}
