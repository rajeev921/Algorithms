/* input - 
int numFeatres=6;
int topFeatures=2;

string possibleFeatures=["storage", "battery", "hover", "alexa", "waterproof", "solar"]

int numFeatureRequests=7

string featureRequests=["I wish my kindle had even more storage", "I wish the battery life of my kindle lasted 2 years", "I read in bath and would enjoy a waterproof kindle", "waterproof and increased battery are my top two requests", "I wanted to take my kindle into the shower", "waterproof please waterproof", "It would be neat if my kindle would hover on my desk when not in use", "How cool it be if my kindle charged in the sun via solar power"]

output = ["waterproof", "battery"]

waterproof - 3
battery - 2
hover - 1
solar - 1 
storage - 1

*/
#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

vector<string> popularNFeatures(int numFeatres, int topFeatures, vector<string>& possibleFeatures, int numFeatureRequests, vector<string>& featureRequests) {
	int features{};

	map<string, int> frequent_str;

	for(auto s1 : featureRequests) {
		for(auto word : possibleFeatures) {
			if(s1.find(word) != std::string::npos) {
				frequent_str[word]++;
			}
		}	
	}	

	auto cmp= [&](pair<string, int> p1, pair<string, int> p2){
            return (p1.second < p2.second ||(p1.second==p2.second && p1.first > p2.first));
        };

	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);


	for(auto it = frequent_str.begin(); it != frequent_str.end(); ++it) {
		pq.push(make_pair(it->first, it->second));
		//cout << it->first << "    " << it->second << endl;
	}

	vector<string> res;
	for(int i=0; i < topFeatures; ++i) {
		cout << pq.top().first << endl;
		res.push_back(pq.top().first);
		pq.pop();
	}


	return {};
}

int main() {
	int numFeatres=6;
	int topFeatures=2;

	vector<string> possibleFeatures = {"storage", "battery", "hover", "alexa", "waterproof", "solar"};

	int numFeatureRequests=7;

	vector<string> featureRequests={"I wish my kindle had even more storage", "I wish the battery life of my kindle lasted 2 years", "I read in bath and would enjoy a waterproof kindle", "waterproof and increased battery are my top two requests", "I wanted to take my kindle into the shower", "waterproof please waterproof", "It would be neat if my kindle would hover on my desk when not in use", "How cool it be if my kindle charged in the sun via solar power"};

	vector<string> out = popularNFeatures(numFeatres, topFeatures, possibleFeatures, numFeatureRequests, featureRequests);
	
	for(auto str : out) {
		cout << str << endl;
	}

	return 0;
}