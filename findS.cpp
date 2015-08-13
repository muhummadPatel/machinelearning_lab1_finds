#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


const int numAttributes = 6;
const int 	SKY = 0,
			AIRTEMP = 1,
			HUMIDITY = 2,
			WIND = 3,
			WATER = 4,
			FORECAST = 5;
const int OUTCOME = 6;


vector<string> hypothesis(numAttributes);
void initHypothesis(){
	fill(hypothesis.begin(), hypothesis.end(), "-");
}

vector<vector<string>> training_instances = {
	{"Sunny", "Warm", "Normal", "Strong", "Warm", "Same", "Yes"},
	{"Sunny", "Warm", "High", "Strong", "Warm", "Same", "Yes"},
	{"Rainy", "Cold", "High", "Strong", "Warm", "Change", "No"},
	{"Sunny", "Warm", "High", "Strong", "Cool", "Change", "Yes"}
};

int main(){
	initHypothesis();

	for(auto instance_it = training_instances.begin(); instance_it != training_instances.end(); ++instance_it){
		if((*instance_it)[OUTCOME] == "Yes"){

			for(int i = 0; i < numAttributes; i ++){
				if(hypothesis[i] == "?" || hypothesis[i] == (*instance_it)[i]){
					continue;
				}else{
					if(hypothesis[i] == "-"){
						hypothesis[i] = (*instance_it)[i];
					}else{
						hypothesis[i] = "?";
					}
				}
			}

		}
	}

	auto print = [](string s)->void{cout << s << " ";};
	for_each(hypothesis.begin(), hypothesis.end(), print);
	cout << endl;

	return 0;
}