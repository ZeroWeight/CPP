#include <iostream>
#include <string>
void reverse(std::string& s){
	if(s.length()<=1) return;
	std::string sub1=s.substr(0,s.length()>>1);
	std::string sub2=s.substr(s.length()>>1,s.length()-(s.length()>>1));
	reverse(sub2);
	reverse(sub1);
	s.clear();
	s+=sub2;
	s+=sub1;
	return;
}
int main(){
	std::string a="HelloWorldCpp";
	reverse(a);
	std::cout<<a<<std::endl;
	return 0;
}
