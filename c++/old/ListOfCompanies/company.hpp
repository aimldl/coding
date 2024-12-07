#ifndef __COMPANY_HPP_
#define __COMPANY_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <set>

using namespace std;

class company
{
public:
	company();
	~company();
	void run();
private:
	string line;
	string input_file;
	string src_file;
	string output_file;	
	
	set<string> set_of_companies;
	set<string>::iterator itr;
};

#endif
