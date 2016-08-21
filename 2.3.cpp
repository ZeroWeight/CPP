#include <iostream>
const float pi=3.1415926;
int main(){
	char mode;
	double r;
	double a,b;
	while(true){
		std::cout<<"Enter the seleted mode"<<std::endl;
		std::cout<<"(C) Cricle\t(R) Rectangular\t(S) Square\t(Q) Quit"<<std::endl;
		switch(mode=std::cin.get()){
			case 'C':case 'c':
				std::cout<<"Enter the radius"<<std::endl;
				std::cin>>r;
				std::cout<<"The size is "<<r*r*pi<<std::endl;
				break;
			case 'R':case 'r':
				std::cout<<"Enter the length and the width"<<std::endl;
				std::cin>>a>>b;
				std::cout<<"The size is "<<a*b<<std::endl;
				break;
			case 'S':case 's':
				std::cout<<"Enter the length"<<std::endl;
				std::cin>>a;
				std::cout<<"The size is "<<a*a<<std::endl;
				break;
				
		}
	}
	return 0;
}
