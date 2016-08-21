#include <iostream>
struct time{
	int year;
	int month;
	int date;
	int hrs;
	int minute;
	float sec;
};
int main(){
	time t;
	std::cout<<"Enter the value of the year"<<std::endl;
	std::cin>>t.year;
	std::cout<<"Enter the value of the month"<<std::endl;
	std::cin>>t.month;
	std::cout<<"Enter the value of the date"<<std::endl;
	std::cin>>t.date;
	std::cout<<"Enter the value of the hour"<<std::endl;
	std::cin>>t.hrs;
	std::cout<<"Enter the value of the minute"<<std::endl;
	std::cin>>t.minute;
	std::cout<<"Enter the value of the second"<<std::endl;
	std::cin>>t.sec;
	std::cout<<"you have just input"<<std::endl;
	std::cout<<std::endl<<t.year<<'-'<<t.month<<'-'<<t.date<<'\t'<<t.hrs<<':'<<t.minute<<':'<<t.sec<<std::endl;
}
