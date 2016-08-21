#include <iostream>
int sum(int n);
int main(){
	int i;
	std::cout<<"Enter a integer"<<std::endl;
	std::cin>>i;
	switch(i){	
	case 1:
		std::cout<<"1 = "<<sum(i)<<std::endl;
		break;
	case 2:
		std::cout<<"1 + 2 = "<<sum(i)<<std::endl;
		break;
	case 3:
		std::cout<<"1 + 2 + 3 = "<<sum(i)<<std::endl;
		break;
	default:
		std::cout<<"1 + 2 + ... + "<<i<<" = "<<sum(i)<<std::endl;
		break;
	}
	return 0;
}
int sum(int n){
	if(n==1) return 1;
	else return n+sum(n-1);
}
