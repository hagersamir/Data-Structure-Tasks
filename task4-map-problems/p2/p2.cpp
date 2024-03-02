#include "p2.h"
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

set<string> word_amalgamation(vector<string> dictionary, string scrambled_word){
    string s;
    set<string> H;
	map<string,string> m;
	for (int i = 0; i < dictionary.size(); i++)
    {
        s = dictionary[i];
		string temp=s;
		sort(s.begin(),s.end());
		m[temp]=s;
	}
        s = scrambled_word ; 
		sort(s.begin(),s.end());
		for(map<string,string>::iterator it=m.begin();it!=m.end();it++){
			if(it->second==s) {
				H.insert(it->first);
			}
		}
	return H;
}