#include <iterator>
#include <iostream>
#include <string>
#include <regex>
#include <list>
#include <map>

using namespace std;

int main()
{

    string str;

    // define list of patterns
    map<string,string> patterns;
	patterns["[0-9]+"] = "NUM";
	patterns["[a-z]+"] = "ID";
	patterns["[A-Z]+"] = "ID";
	patterns["[\\=]"] = "ASSIGN";
	patterns["[\\+]"] = "SUM";
	patterns["[\\-]"] = "MINUS";
	patterns["[\\*]"] = "TIMES";
	patterns["[\\/]"] = "DIV";
	patterns["[\\(]"] = "RPAR";
	patterns["[\\)]"] = "LPAR";

    map< size_t, pair<string,string> > matches;

	cout << "Enter a Sting :";
	getline(cin, str);
	cout << endl;
	

    for ( auto pat = patterns.begin(); pat != patterns.end(); ++pat )
    {
        regex r(pat->first);
        auto words_begin = sregex_iterator( str.begin(), str.end(), r );
        auto words_end   = sregex_iterator();

        for ( auto it = words_begin; it != words_end; ++it )
            matches[ it->position() ] = make_pair( it->str(), pat->second );
    }

	cout<<"TOKENS" << "   " << "SYMBOLIC NAMES"<< endl ;
    for ( auto match = matches.begin(); match != matches.end(); ++match )

		
        cout << match->second.first << "      " << match->second.second << endl;
	
	cout << endl;
	system("pause");
}