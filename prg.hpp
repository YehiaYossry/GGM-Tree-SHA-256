#ifndef PRG256
#define PRG256
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
class SHA256
{
private:
    bitset<512> message;
    vector<bitset<32>> M;
    vector<string> H;
    const static vector<string> K;
    vector<string> A_To_H;
    vector<bitset<32>> W;

public:
    SHA256();
    bitset<512> getMessage();
    vector<bitset<32>> getM();
    vector<bitset<32>> getW();
    vector<string> getA_To_H();
    vector<string> getH();
    void WtCalculator();
    void changingValues();
    void changeHashValues();
    void splitIntoWords();
    void Padding(const string &parent, string input);
    string getOutput();
};
#endif