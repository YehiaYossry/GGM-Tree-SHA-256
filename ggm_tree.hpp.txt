#include <iostream>
using namespace std;
#ifndef GGMTREE
#define GGMTREE
class GgmTree
{
public:
    GgmTree();
    string start(string path);
    string pathInBinary(string path);

private:
    string seed;
    string key;
    string path;
};
#endif