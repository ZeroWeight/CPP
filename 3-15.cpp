#include <iostream>
int GetPower(int x,int y);
double GetPower(double x,int y);
int main(){
	int ix,pow;
	double dx;
	std::cout<<"Enter an int base number: ";
	std::cin>>ix;
	std::cout<<"Enter a double base number: ";
	std::cin>>dx;
	std::cout<<"To what power? ";
	std::cin>>pow;
	std::cout<<ix<<" to the "<<pow<<"th power is "<<GetPower(ix,pow)<<std::endl;
	std::cout<<dx<<" to the "<<pow<<"th power is "<<GetPower(dx,pow)<<std::endl;
	return 0;
}
int GetPower(int x,int y){
	if(y){
		if (y==1) 
			return x;
		else
			return GetPower(x,y>>1)*GetPower(x,y-(y>>1));
	}
	else return 1;
}
double GetPower(double x,int y){
	if(y){
		if (y==1) 
			return x;
		else
			return GetPower(x,y>>1)*GetPower(x,y-(y>>1));
	}
	else return 1;
}
