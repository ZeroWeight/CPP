#include <iostream>
int main(){
	//while loop
	std::cout<<"---While Loop---"<<std::endl;
	int i=2;
	while(i<101){
		int j=2;
		bool prim=true;
		while(j*j<=i){
			if(!(i%j)) {
				prim=false;
				break;
			}
			++j;
		}
		if(prim){
			std::cout<<i<<std::endl;
		}
		++i;	
	}
	std::cout<<"----------\n"<<std::endl;
	//do-while loop
	std::cout<<"---Do-while Loop---"<<std::endl;
	i=2;
	do{
		int j=2;
		bool prim=true;
		do{
			if(!(i%j)&&i!=j) {
				prim=false;
				break;
			}
		}while(++j*j<i);
		if(prim){
			std::cout<<i<<std::endl;
		}
	}while(i++<100);
	std::cout<<"----------\n"<<std::endl;
	//for loop
	std::cout<<"---For Loop---"<<std::endl;
	for(i=2;i<101;i++){
		bool prim=true;
		for(int j=2;j*j<=i;++j)
			if(!(i%j)) {
				prim=false;
				break;
			}
		if(prim){
			std::cout<<i<<std::endl;
		}		
	}
	std::cout<<"----------\n"<<std::endl;
	return 0;
}
