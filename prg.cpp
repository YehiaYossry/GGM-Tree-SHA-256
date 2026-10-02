#include <iostream>
#include <bitset>
#include <vector>
#include "utilities.hpp"
#include "prg.hpp"
using namespace std;

const vector<string> SHA256::K = {
    "428a2f98", "71374491", "b5c0fbcf", "e9b5dba5", "3956c25b", "59f111f1", "923f82a4", "ab1c5ed5",
    "d807aa98", "12835b01", "243185be", "550c7dc3", "72be5d74", "80deb1fe", "9bdc06a7", "c19bf174",
    "e49b69c1", "efbe4786", "0fc19dc6", "240ca1cc", "2de92c6f", "4a7484aa", "5cb0a9dc", "76f988da",
    "983e5152", "a831c66d", "b00327c8", "bf597fc7", "c6e00bf3", "d5a79147", "06ca6351", "14292967",
    "27b70a85", "2e1b2138", "4d2c6dfc", "53380d13", "650a7354", "766a0abb", "81c2c92e", "92722c85",
    "a2bfe8a1", "a81a664b", "c24b8b70", "c76c51a3", "d192e819", "d6990624", "f40e3585", "106aa070",
    "19a4c116", "1e376c08", "2748774c", "34b0bcb5", "391c0cb3", "4ed8aa4a", "5b9cca4f", "682e6ff3",
    "748f82ee", "78a5636f", "84c87814", "8cc70208", "90befffa", "a4506ceb", "bef9a3f7", "c67178f2"};
SHA256::SHA256()
{
    H = {
        "6a09e667", "bb67ae85", "3c6ef372", "a54ff53a",
        "510e527f", "9b05688c", "1f83d9ab", "5be0cd19"};
    A_To_H = H;
}
void SHA256::WtCalculator()
{
    W.resize(64);
    for (int i = 0; i < 16; i++)
    {
        W[i] = M[i];
    }
    for (int i = 16; i < 64; i++)
    {
        bitset<32> smallSigma0Result = smallSigma0(W[i - 15]);
        bitset<32> smallSigma1Result = smallSigma1(W[i - 2]);
        bitset<32> result = add(smallSigma0Result, smallSigma1Result);
        result = add(result, W[i - 7]);
        result = add(result, W[i - 16]);
        W[i] = result;
    }
}
void SHA256::changingValues()
{
    for (int i = 0; i < 64; i++)
    {
        bitset<32> T1 = add(hex8ToBitset32(A_To_H[7]), BigSigma1(hex8ToBitset32(A_To_H[4])));
        T1 = add(T1, ch(hex8ToBitset32(A_To_H[4]), hex8ToBitset32(A_To_H[5]), hex8ToBitset32(A_To_H[6])));
        T1 = add(T1, hex8ToBitset32(K[i]));
        T1 = add(T1, W[i]);

        bitset<32> T2 = add(BigSigma1(hex8ToBitset32(A_To_H[0])), Maj(hex8ToBitset32(A_To_H[0]), hex8ToBitset32(A_To_H[1]), hex8ToBitset32(A_To_H[2])));
        A_To_H[7] = A_To_H[6];
        A_To_H[6] = A_To_H[5];
        A_To_H[5] = A_To_H[4];
        A_To_H[4] = toHex(add(hex8ToBitset32(A_To_H[3]), T1));
        A_To_H[3] = A_To_H[2];
        A_To_H[2] = A_To_H[1];
        A_To_H[1] = A_To_H[0];
        A_To_H[0] = toHex(add(T1, T2));
    }
}
void SHA256::changeHashValues()
{
    for (int i = 0; i < 8; i++)
    {
        H[i] = toHex(add(hex8ToBitset32(H[i]), hex8ToBitset32(A_To_H[i])));
    }
}
void SHA256::splitIntoWords()
{
    M.resize(16);
    for (int word = 0; word < 16; word++)
    {

        bitset<32> temp;
        for (int b = 0; b < 32; b++)
        {
            temp[b] = message[word * 32 + b];
        }

        M[16 - word - 1] = temp;
    }
}
void SHA256::Padding(const string &parent, string input)
{

    string padded = hexToBinary(parent + input) + '1';
    int size = padded.size() - 1;
    for (int i = size + 1; i < 512 - 64; i++)
    {
        padded += '0';
    }
    string Length = toBinary(size);
    padded += Length;
    for (int i = 0; i < 512; i++)
    {
        message[512 - i - 1] = (padded[i] == '1');
    }
}
string SHA256::getOutput()
{
    string output = "";
    for (int i = 0; i < 8; i++)
    {
        output += H[i];
    }
    return output;
}
bitset<512> SHA256::getMessage()
{
    return message;
}
vector<bitset<32>> SHA256::getM()
{
    return M;
}
vector<bitset<32>> SHA256::getW()
{
    return W;
}
vector<string> SHA256::getA_To_H()
{
    return A_To_H;
}
vector<string> SHA256::getH()
{
    return H;
}