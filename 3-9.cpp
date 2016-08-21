#include <iostream>
#define _DEBUG_
bool is_prime(int a);
int main(int agrc,char** argv){
	int i;
	std::cout<<"Please enter a integer"<<std::endl;
	std::cin>>i;
	if(is_prime(i))
		std::cout<<i<<" is a prime number"<<std::endl;
	else
		std::cout<<i<<" is not a prime number"<<std::endl;	
	return 0;
}
bool is_prime(int a){
	if(a<=1) return false;
	else if (a==2) return true;
	else {
		for(int i=2;i*i<=a;i++)
			if(!(a%i)) return false;
	}
	return true;
}
