#include <iostream>
#include <bitset>
#include <vector>
#include "utilities.hpp"
using namespace std;

bitset<32> add(const bitset<32> &a, const bitset<32> &b)
{
    bitset<32> result;
    bool carry = false;

    for (int i = 0; i < 32; i++)
    {
        bool bit_a = a[i];
        bool bit_b = b[i];
        result[i] = bit_a ^ bit_b ^ carry;
        carry = (bit_a && bit_b) || (bit_a && carry) || (bit_b && carry);
    }
    return result;
}
bitset<256> hex64ToBitset256(const string &hex)
{
    bitset<256> bits;

    if (hex.length() != 64)
        return bits;

    int bitIndex = 255;

    for (char c : hex)
    {
        bitset<4> nibble;

        switch (c)
        {
        case '0':
            nibble = std::bitset<4>("0000");
            break;
        case '1':
            nibble = std::bitset<4>("0001");
            break;
        case '2':
            nibble = std::bitset<4>("0010");
            break;
        case '3':
            nibble = std::bitset<4>("0011");
            break;
        case '4':
            nibble = std::bitset<4>("0100");
            break;
        case '5':
            nibble = std::bitset<4>("0101");
            break;
        case '6':
            nibble = std::bitset<4>("0110");
            break;
        case '7':
            nibble = std::bitset<4>("0111");
            break;
        case '8':
            nibble = std::bitset<4>("1000");
            break;
        case '9':
            nibble = std::bitset<4>("1001");
            break;

        case 'A':
        case 'a':
            nibble = std::bitset<4>("1010");
            break;
        case 'B':
        case 'b':
            nibble = std::bitset<4>("1011");
            break;
        case 'C':
        case 'c':
            nibble = std::bitset<4>("1100");
            break;
        case 'D':
        case 'd':
            nibble = std::bitset<4>("1101");
            break;
        case 'E':
        case 'e':
            nibble = std::bitset<4>("1110");
            break;
        case 'F':
        case 'f':
            nibble = std::bitset<4>("1111");
            break;

        default:
            return bitset<256>();
        }

        for (int i = 3; i >= 0; --i)
        {
            bits[bitIndex--] = nibble[i];
        }
    }

    return bits;
}
bitset<32> hex8ToBitset32(const string &hex)
{
    bitset<32> bits;

    if (hex.length() != 8)
        return bits;

    int bitIndex = 31;

    for (char c : hex)
    {
        bitset<4> nibble;

        switch (c)
        {
        case '0':
            nibble = std::bitset<4>("0000");
            break;
        case '1':
            nibble = std::bitset<4>("0001");
            break;
        case '2':
            nibble = std::bitset<4>("0010");
            break;
        case '3':
            nibble = std::bitset<4>("0011");
            break;
        case '4':
            nibble = std::bitset<4>("0100");
            break;
        case '5':
            nibble = std::bitset<4>("0101");
            break;
        case '6':
            nibble = std::bitset<4>("0110");
            break;
        case '7':
            nibble = std::bitset<4>("0111");
            break;
        case '8':
            nibble = std::bitset<4>("1000");
            break;
        case '9':
            nibble = std::bitset<4>("1001");
            break;

        case 'A':
        case 'a':
            nibble = std::bitset<4>("1010");
            break;
        case 'B':
        case 'b':
            nibble = std::bitset<4>("1011");
            break;
        case 'C':
        case 'c':
            nibble = std::bitset<4>("1100");
            break;
        case 'D':
        case 'd':
            nibble = std::bitset<4>("1101");
            break;
        case 'E':
        case 'e':
            nibble = std::bitset<4>("1110");
            break;
        case 'F':
        case 'f':
            nibble = std::bitset<4>("1111");
            break;

        default:
            return bitset<32>();
        }

        for (int i = 3; i >= 0; --i)
        {
            bits[bitIndex--] = nibble[i];
        }
    }

    return bits;
}
string hexToBinary(const string &hex)
{
    string bin = "";

    for (int i = 0; i < hex.size(); i++)
    {
        char c = hex[i];
        switch (c)
        {
        case '0':
            bin += "0000";
            break;
        case '1':
            bin += "0001";
            break;
        case '2':
            bin += "0010";
            break;
        case '3':
            bin += "0011";
            break;
        case '4':
            bin += "0100";
            break;
        case '5':
            bin += "0101";
            break;
        case '6':
            bin += "0110";
            break;
        case '7':
            bin += "0111";
            break;
        case '8':
            bin += "1000";
            break;
        case '9':
            bin += "1001";
            break;
        case 'A':
        case 'a':
            bin += "1010";
            break;
        case 'B':
        case 'b':
            bin += "1011";
            break;
        case 'C':
        case 'c':
            bin += "1100";
            break;
        case 'D':
        case 'd':
            bin += "1101";
            break;
        case 'E':
        case 'e':
            bin += "1110";
            break;
        case 'F':
        case 'f':
            bin += "1111";
            break;
        default:
            bin += "????"; // error
        }
    }

    return bin;
}
string toBinary(int n)
{
    bitset<64> b(n);
    return b.to_string();
}
string toHex(const bitset<32> &bits)
{
    string result = "";

    for (int i = 28; i >= 0; i -= 4)
    {
        bitset<4> nibble;
        nibble[3] = bits[i + 3];
        nibble[2] = bits[i + 2];
        nibble[1] = bits[i + 1];
        nibble[0] = bits[i];

        switch (nibble.to_ulong())
        {
        case 0b0000:
            result += '0';
            break;
        case 0b0001:
            result += '1';
            break;
        case 0b0010:
            result += '2';
            break;
        case 0b0011:
            result += '3';
            break;
        case 0b0100:
            result += '4';
            break;
        case 0b0101:
            result += '5';
            break;
        case 0b0110:
            result += '6';
            break;
        case 0b0111:
            result += '7';
            break;
        case 0b1000:
            result += '8';
            break;
        case 0b1001:
            result += '9';
            break;
        case 0b1010:
            result += 'a';
            break;
        case 0b1011:
            result += 'b';
            break;
        case 0b1100:
            result += 'c';
            break;
        case 0b1101:
            result += 'd';
            break;
        case 0b1110:
            result += 'e';
            break;
        case 0b1111:
            result += 'f';
            break;
        }
    }

    return result;
}
string intToBinaryString(int n)
{
    string s = "";
    while (n > 0)
    {
        string bit;
        if (n % 2 == 0)
            bit = "0";
        else
            bit = "1";
        s = bit + s;
        n /= 2;
    }
    if (s.empty())
    {
        s = "0";
    }

    return s;
}
bitset<32> rotateRight(const bitset<32> &b, int n)
{
    bitset<32> result;
    int numOfRotations = n % 32;

    for (int i = 0; i < numOfRotations; i++)
        result[32 - numOfRotations + i] = b[i];

    for (int i = numOfRotations; i < 32; i++)
        result[i - numOfRotations] = b[i];

    return result;
}
bitset<32> shiftRight(const bitset<32> &b, int n)
{
    bitset<32> result = b >> n;
    return result;
}
bitset<32> smallSigma0(const bitset<32> &b)
{
    bitset<32> b1 = rotateRight(b, 7);
    bitset<32> b2 = rotateRight(b, 18);
    bitset<32> b3 = shiftRight(b, 3);
    bitset<32> result = b1 ^ b2 ^ b3;
    return result;
}
bitset<32> smallSigma1(const bitset<32> &b)
{
    bitset<32> b1 = rotateRight(b, 17);
    bitset<32> b2 = rotateRight(b, 19);
    bitset<32> b3 = shiftRight(b, 10);
    bitset<32> result = b1 ^ b2 ^ b3;
    return result;
}
bitset<32> BigSigma1(const bitset<32> &e)
{
    bitset<32> result;
    result = rotateRight(e, 6) ^ rotateRight(e, 11) ^ rotateRight(e, 25);
    return result;
}
bitset<32> BigSigma0(const bitset<32> &a)
{
    bitset<32> result;
    result = rotateRight(a, 2) ^ rotateRight(a, 13) ^ rotateRight(a, 22);
    return result;
}
bitset<32> ch(const bitset<32> &e, const bitset<32> &f, const bitset<32> &g)
{
    bitset<32> result;

    for (int i = 0; i < 32; i++)
    {
        if (e[i] == 1)
            result[i] = f[i];
        else
            result[i] = g[i];
    }

    return result;
}
bitset<32> Maj(const bitset<32> &a, const bitset<32> &b, const bitset<32> &c)
{
    return (a & b) | (a & c) | (b & c);
}