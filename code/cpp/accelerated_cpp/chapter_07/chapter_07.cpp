
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include "grammar.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <file path>.\n", argv[0]);
        return -1;
    }

    ifstream ifs(argv[1]);
    if (!ifs.is_open())
    {
        cerr << "open file failed, path: " << argv[1] << endl;
        return -1;
    }

    vector<string> sentence = GenSentence(ReadGrammar(ifs));
    if (!sentence.empty())
        cout << sentence[0] << "\t";

    for (vector<string>::const_iterator cit = sentence.begin() + 1;
        cit != sentence.end(); ++cit)
    {
        cout << *cit << " ";
    }
    cout << endl;

    return 0;
}
