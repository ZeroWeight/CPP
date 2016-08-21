#include<iostream>
int gcd(int i,int j);
int lcm(const int& i,const int& j);
int main(){
	int i,j;
	std::cout<<"Please enter two positive integers"<<std::endl;
	std::cin>>i>>j;
	std::cout<<"The gcd of "<<i<<" and "<<j<<" is "<<gcd(i,j)<<std::endl;
	std::cout<<"The lcm of "<<i<<" and "<<j<<" is "<<lcm(i,j)<<std::endl;
}
int lcm(const int& i,const int& j){
	return i/gcd(i,j)*j;
}
int gcd(int i,int j){
	while(j){
		int temp;
		temp=i%j;
		i=j;
		j=temp;
	}
	return i;
}
