#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	ifstream ifs("text.txt");

	if(!ifs){
		cerr<<"File was not found.\n";
		return 0;
	}

	string word{};
	float letters{0};
	int total{0};
	float average{0};
	string min{};
	string max{};

	while (ifs>>word){

		if(total==0){
			min=word;
		}

		total++;
		letters=word.size()+letters;

		if(word.size()>=max.size()){
			max=word;
		}

		if(word.size()<=min.size()){
			min=word;
		}
	}

	if(total==0){
		cerr<<"File is empty.\n";
		return 0;
	}

	average=letters/total;

	cout<<"There are "
			<<total
			<<" words in the file.\n";

	cout<<"The shortest word was "
			<<min
			<<" with "
			<<min.size()
			<<" character(s).\n";

	cout<<"The longest word was "
			<<max
			<<" with "
			<<max.size()
			<<" character(s).\n";

	cout<<"The average length was "
			<<setprecision(2) <<fixed <<average
			<<" character(s).\n";
}
