#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <map>
#include <string>
#include <algorithm>
#include <tuple>
#include <functional>
#include <array>
#include <list>
#include <thread>
#include <numeric>

int mostFreqenlyCalledEmail(std::vector<std::string>& emails){
	std::unordered_map<std::string, int> freq;

	for(std::string& email : emails){
		//handle redirection email
		std::string realEmail = "";
		int atSignIndex = -1;
		for(int i=0;i<email.size();i++){
			if(email[i]=='@'){
				atSignIndex = i;
				break;
			}
		}
		std::string domainAddress = email.substr(atSignIndex, email.size()-atSignIndex);
		std::string nameOfEmail = email.substr(0, atSignIndex);
		for(char c : nameOfEmail){
			if(c=='+') break;
			else if(c=='.') continue;
			else realEmail.push_back(c);
		}
		realEmail+=domainAddress;

		freq[realEmail]++;
	}

	//find max value in hash map
	int res = 0;
	for(auto [key, value] : freq){
		res = std::max(res, value);
	}

	return res;
}


int main()
{
    std::vector<std::string> emails = {"frank+hiring@google.com", "fr.ank@google.com"};
    std::cout << mostFreqenlyCalledEmail(emails) << std::endl;
    return 0;
}
