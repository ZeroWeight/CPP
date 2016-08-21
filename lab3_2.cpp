#include <iostream>
#include <cstdlib>
#include <ctime>
int Max1(int,int);
int Max1(int,int,int);
double Max1(double,double);
double Max1(double,double,double);
int main(){
	srand(time(0));
	//This is a test of the function Max1(int,int)
	int a=rand();
	int b=rand();
	std::cout<<"The larger of "<<a<<" and "<<b<<" is "<<Max1(a,b)<<std::endl;
	a=rand();
	b=rand();
	int c=rand();
	std::cout<<"The largest of "<<a<<" and "<<b<<" and "<<c<<" is "<<Max1(a,b,c)<<std::endl;
	double d=(double)rand()/rand();
	double e=(double)rand()/rand();
	std::cout<<"The larger of "<<d<<" and "<<e<<" is "<<Max1(d,e)<<std::endl;
	d=(double)rand()/rand();
	e=(double)rand()/rand();
	double f=(double)rand()/rand();
	std::cout<<"The largest of "<<d<<" and "<<e<<" and "<<f<<" is "<<Max1(d,e,f)<<std::endl;
	return 0;
}
int Max1(int a,int b){
	return a>b?a:b;
}
int Max1(int a,int b,int c){
	return Max1(a,Max1(b,c));
}
double Max1(double a,double b){
	return a>b?a:b;
}
double Max1(double a,double b,double c){
	return Max1(a,Max1(b,c));
}
