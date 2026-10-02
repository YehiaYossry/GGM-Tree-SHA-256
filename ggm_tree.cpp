#include "ggm_tree.hpp"
#include "utilities.hpp"
#include "prg.hpp"
#include <iostream>
#include <string>
using namespace std;
GgmTree::GgmTree()
{
    key = "1111111111111111111111111111111111111111111111111111111111111111";
    seed = key;
}
string GgmTree::start(string path)
{
    SHA256 generator;
    string output;
    path = pathInBinary(path);
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '0')
        {
            generator.Padding(seed, "00");
        }
        else
        {
            generator.Padding(seed, "01");
        }
        generator.splitIntoWords();
        generator.WtCalculator();
        generator.changingValues();
        generator.changeHashValues();
        seed = generator.getOutput();
    }
    output = seed;
    return output;
}
string GgmTree::pathInBinary(string path)
{
    string path_binary = "";
    for (int i = 0; i < path.length(); i++)
    {
        path_binary += intToBinaryString((int)path[i]); // changing the char to int using asci code
    }

    return path_binary;
}