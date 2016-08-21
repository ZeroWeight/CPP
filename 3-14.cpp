#include<iostream>
float p(int n,int x);
int main(){
	int n,x;
	std::cout<<"Please Enter the integer n"<<std::endl;
	std::cin>>n;
	std::cout<<"Please Enter the integer x"<<std::endl;
	std::cin>>x;
	std::cout<<"n="<<n<<std::endl;
	std::cout<<"x="<<x<<std::endl;
	std::cout<<"P="<<n<<'('<<x<<")="<<p(n,x)<<std::endl;
	return 0;
}
float p(int n,int x){
	if(n){
		if(n==1)
			return x;
		else 
			return ((2*n-1)*x*p(n-1,x)-(n-1)*p(n-2,x))/n;
	}
	else return 1.0f;
}
