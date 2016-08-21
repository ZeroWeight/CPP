#include <iostream>
const char* seq="   ";
int main(){
	std::cout<<'*';
	for(int i=1;i<10;i++){
		std::cout<<' ';
		std::cout<<seq<<i;
	}
	std::cout<<std::endl;
	for(int i=1;i<10;i++){
		std::cout<<i;
		for(int j=1;j<10;j++){
			if(i*(j-1)<10) std::cout<<' ';
			std::cout<<seq<<i*j;
		}
		std::cout<<std::endl;
	}
	return 0;
}
