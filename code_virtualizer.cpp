//////////////////////////////////////////
// Code Virtualizer Example.
//////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> code = {0x48, 0x31, 0xc0, 0x50, 0x68, 0x2f, 0x2f, 0x73, 0x68, 0x68, 0x2f, 0x62, 0x69, 0x6e, 0x89, 0xe3, 0x31, 0xd2, 0x52, 0x53, 0x89, 0xe1, 0xb0, 0x0b, 0xcd, 0x80};

void decrypt(vector<char> &v, int key)
{
    for (int i = 0; i < v.size(); i++) {
        v[i] ^= key;
    }
}

void scramble(vector<char> &v)
{
    random_shuffle(v.begin(), v.end());
}

int main()
{
    srand(time(NULL));
    int key = rand();
    decrypt(code, key);
    scramble(code);
    int (*func)() = (int (*)()) &code[0];
    func();
    return 0;
}
