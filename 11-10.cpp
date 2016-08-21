#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <locale>
using namespace std;
int main(){
	locale loc("G");
	wcout.imbue(loc);
	wifstream in("11-10-in");
	wofstream out("11-10-out");
	in.imbue(loc);
	out.imbue(loc);
	wstring line;
	map<wchar_t,int>counter;
	while(getline(in,line))
		for(int i=0;i<line.length();++i)
			counter[line[i]]++;
	map<wchar_t,int>::iterator itor;
	int i=1;
	for(itor=counter.begin();itor!=counter.end();++i){
		out<<itor->first<<"\t"<<itor->second<<'\t';
		if(!(i%5))
			out<<endl;
	}
	in.close();
	out.close();
	return 0;
}
//fail and fail
//hehehe
