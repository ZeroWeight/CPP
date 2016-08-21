#include <iostream>
int** trans(int**,int,int);
int main(){
	int row,col;
	std::cout<<"Enter the row and the col of the matrix"<<std::endl;
	std::cin>>row>>col;
	int** mat=new int* [row];
	for(int i=0;i<row;i++)
		mat[i]=new int[col];
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			std::cin>>mat[i][j];
	int**tr_mat=trans(mat,row,col);
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++)
			std::cout<<tr_mat[i][j]<<'\t';
		std::cout<<std::endl;
	}
	return 0;
}
int** trans(int**a,int row,int col){
	int** b=new int* [col];
	for(int i=0;i<col;i++)
		b[i]=new int [row];
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			b[j][i]=a[i][j];
	return b;
}
