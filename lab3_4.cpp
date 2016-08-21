#include <iostream>
int fib(int);
int main(){
	//This is a test of the function fib()
	for(int i=1;i<40;i++)
		std::cout<<fib(i)<<std::endl;
	return 0;
}
int fib(int n){
	//Well, professor deng has already told us that it is unwise to use the recursion :(
	if(n<=2) return 1;
	else return fib(n-1)+fib(n-2);
}
