#include <iostream>
void trans(int[3][3]);
inline void swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
int main(){
	int a[3][3];
	std::cout<<"Enter the 3*3 matrix"<<std::endl;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			std::cin>>a[i][j];
	trans(a);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			std::cout<<a[i][j]<<'\t';
		std::cout<<std::endl;
	}
	return 0;
}
void trans(int a[3][3]){
	for(int i=0;i<3;i++)
		for(int j=i+1;j<3;j++)
			swap(a[i][j],a[j][i]);
	return;
}
