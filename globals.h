#ifndef __Globals__
#define __Globals__

#include <string>
#include <vector>
#include <list>

using namespace std;

bool Same(const string& a, const string& b);
bool Same(const char* a, const string& b);
bool Same(const string& a, const char* b);
int Roll(int min, int max);
void Tokenize(const string& line, vector<string>& arguments);

#endif //__Globals__

//Ref : https://github.com/d0n3val/zork