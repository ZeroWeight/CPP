#include <iostream>
#include <fstream>
class Dog{
private:
	int itsWeight;
	int itsNumberDayAlive;
public:
	Dog(int weight,long days):itsWeight(weight),itsNumberDayAlive(days){}
	int getWeight() const {return itsWeight;}
	void setWeight(int weight){itsWeight=weight;}
	long getDaysAlive()const { return itsNumberDayAlive;}
	void setDaysAlive(long days){itsNumberDayAlive=days;}
};
int main(){
	char filename[81];
	std::cout<<"Please enter the file name: ";
	std::cin>>filename;
	std::ofstream fout(filename);
	if(!fout){
		std::cerr<<"Unable to open "<<filename<<" for writing"<<std::endl;
		exit(1);
	}
	Dog dog1(5,10);
	fout.write((char*)&dog1,sizeof dog1);
	fout.close();
	std::ifstream fin(filename);
	if(!fin){
		std::cerr<<"Unable to open "<<filename<<" for writing"<<std::endl;
		exit(1);
	}
	Dog dog2(2,2);
	std::cout<<"dog2 weight: "<<dog2.getWeight()<<std::endl;
	std::cout<<"dog2 days: "<<dog2.getDaysAlive()<<std::endl;
	fin.read((char*)&dog2,sizeof dog2);
	std::cout<<"dog2 weight: "<<dog2.getWeight()<<std::endl;
	std::cout<<"dog2 days: "<<dog2.getDaysAlive()<<std::endl;
	fin.close();
	return 0;
}
