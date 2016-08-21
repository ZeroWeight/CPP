#include <iostream>
#include <cstring>
char* combine(char*,char*);
int main(){
	char* a=new char[81];
	char* b=new char[81];
	std::cout<<"Enter string 1"<<std::endl;
	std::cin>>a;
	std::cout<<"Enter string 2"<<std::endl;
	std::cin>>b;
	char* res=combine(a,b);
	std::cout<<"The final string is"<<std::endl;
	std::cout<<res<<std::endl;
	return 0;
}
char* combine(char* a,char* b){
	int i=0;
	int n1=strlen(a),n2=strlen(b);
	char* res=new char[n1+n2];
	for(int j=0;j<n1;j++)
		res[i++]=a[j];
	for(int j=0;j<n2;j++)
		res[i++]=b[j];
	res[i]=0;
	return res;
}
