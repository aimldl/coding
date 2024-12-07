#include "company.hpp"

company::company()
{
//	input_file  = "data/list_of_companies_20160908.txt";
	input_file  = "data/test.txt";
	output_file = "output/list_of_uniq_company_names_20160908.txt";
	src_file    = "output/src_of_company_names_20160908.txt";
}

company::~company()
{
}

void
company::run()
{
	ifstream ifs;
	ofstream ofs;
	
	int count;
	
	ifs.open(input_file.c_str(), ios::in);
	if (!ifs.is_open())
	  cerr << input_file << " was not opened." << endl;
	
	ofs.open(src_file.c_str());
	
	int loc;
	count = 0;
	while ( !ifs.eof() )
	{
		getline(ifs, line);
//		cout << line[1] << ":" << line << endl;
//		getchar();
		// Skip a line starting with #
		if ( !( line.length() == 0 ||
		     line[0] == '#') )
		{
			set_of_companies.insert(line);
			count++;
		}
	}
	ifs.close();
	ofs.close();
	
	ofs.open(output_file.c_str());
	for (itr = set_of_companies.begin(); itr!= set_of_companies.end();itr++)
	{
		ofs << *itr << endl;
	}
	ofs.close();
	cout << " Number of inserted companies   = " << count << endl;
	cout << " Number of unique company names = " << set_of_companies.size() << endl;
}


//		if ( line.length() == 0 ||
//		     line[1] == '#' )
//		{
//		  loc = line.find('#');
//		  ofs << line.substr(loc+2,line.length()-loc-2) << endl;
////		  cout << line[1] << ": " << line << endl;
//		}
//		else
//		{
//			set_of_companies.insert(line);
//			count++;
//		}

