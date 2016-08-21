#include <iostream>
double F2C(double F);
int main(){
	//This is a test for the function F2C
	double F;
	std::cout<<"Enter the Fahrenheit temperature"<<std::endl;
	std::cin>>F;
	std::cout<<"The Celsius temperature is"<<F2C(F)<<std::endl;
	return 0;
}
double F2C(double F){
	return (F-32)*5/9;
}
