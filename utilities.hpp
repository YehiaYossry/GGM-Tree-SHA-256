#include <iostream>
#include <bitset>
using namespace std;
#ifndef UTILITIES
#define UTILITIES
bitset<32> add(const bitset<32> &a, const bitset<32> &b);
bitset<256> hex64ToBitset256(const string &hex);
bitset<32> hex8ToBitset32(const string &hex);
string hexToBinary(const string &hex);
string toBinary(int n);
string toHex(const bitset<32> &bits);
string intToBinaryString(int n);
bitset<32> rotateRight(const bitset<32> &b, int n);
bitset<32> shiftRight(const bitset<32> &b, int n);
bitset<32> smallSigma0(const bitset<32> &b);
bitset<32> smallSigma1(const bitset<32> &b);
bitset<32> BigSigma1(const bitset<32> &e);
bitset<32> BigSigma0(const bitset<32> &a);
bitset<32> ch(const bitset<32> &e, const bitset<32> &f, const bitset<32> &g);
bitset<32> Maj(const bitset<32> &a, const bitset<32> &b, const bitset<32> &c);
#endif
