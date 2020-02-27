#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

bool if_okey(int argc, char* argv[]){
	size_t len1,len2,len3;
	std::string str1 = argv[1], str2 = argv[2], str3 = argv[3];
	int int1 = std::stoi(argv[1],&len1), int2 = std::stoi(argv[2],&len2), int3 = std::stoi(argv[3],&len3);

	if (!(len1==str1.length())) {printf("bad integer value %s for MAX_N_OUT\n", argv[1]); return false;}
	if (!(len2==str2.length())) {printf("bad integer value %s for MIN_WORD_LEN\n", argv[2]); return false;}
	if (!(len3==str3.length())) {printf("bad integer value %s for MAX_WORD_LEN\n", argv[3]); return false;}
	if (int2 > int3) {printf("MIN_WORD_LEN %d is greater than MAX_WORD_LEN %d\n", int2, int3); return false;}
	return true;
}

std::string transform(std::string word){
	int difference = 'a'-'A';
	std::string word_tmp = word;
	for(char &a : word) {
		if('A'<=a && a<='Z') a+=difference;
		if('a'<=a && a<='z') a+=0;
		else word_tmp.erase(std::remove(word_tmp.begin(), word_tmp.end(),a), word_tmp.end());;
	}
	return word_tmp;
}

int main(int argc, char* argv[]){
	std::ifstream in(argv[4]);

	if (!in) printf("File is not valid.\n");

	size_t len1,len2,len3;
	int int1 = std::stoi(argv[1],&len1), int2 = std::stoi(argv[2],&len2), int3 = std::stoi(argv[3],&len3), totalwords = 0;
	if (if_okey(argc, argv)){
        	std::string word;
        	map<std::string, unsigned int> word_counts;
		
        	while (in >> word) {
			word = transform(word);
			if(word.length() <= int3 && word.length() >= int2){
        			if (word_counts.find(word) != word_counts.end())word_counts[word]++;
        			else {word_counts[word] = 1; totalwords++;}
			}
        	}
		if ( int1 < totalwords ) { printf("More words than MAX_N_OUT given.\n"); return 0; }
        	map<std::string, unsigned int>::iterator iter;
        	for (iter = word_counts.begin(); iter != word_counts.end(); ++iter) cout << iter->first <<": "<< iter->second <<" times."<< "\n";
	}
	return 0;
}
