#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
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
int main(int argc, char** argv){
vector<string> dictionary = {
    "tarp",
    "given",
    "score",
    "refund",
    "only",
    "trap",
    "work",
    "earn",
    "course",
    "pepper",
    "part"
};
set<string> result = word_amalgamation(dictionary, "artp");
   cout<<result.size()<<endl;
 bool i= result.find("trap") != result.end();
  bool i2= result.find("tarp") != result.end();
   bool i3= result.find("part") != result.end();
cout <<i << endl;
cout <<i2 << endl;
cout <<i3 << endl;

}
