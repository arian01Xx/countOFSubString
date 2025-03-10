#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
	long long countOfSubstring(string word, int k){
		int frequencies[2][128]={};
		frequencies[0]['a']=frequencies[0]['e']=frequencies[0]['i']=frequencies[0]['o']=frequencies[0]['u']=1;

		long long response=0;
		int currentK=0, vowels=0, extraLeft=0, left=0;

		for(int right=0; right<word.length(); right++){
			char rightChar=word[right];
			if(frequencies[0][rightChar]){
				if(++frequencies[1][rightChar]==1) vowels++;
			}else currentK++;

			while(currentK>k){
				char leftChar=word[left++];
				if(frequencies[0][leftChar]){
					if(--frequencies[1][leftChar]==0) vowels--;
				}else currentK--;
				extraLeft=0;
			}

			while(vowels==5 && currentK==k && left<right && frequencies[0][word[left]] && frequencies[1][word[left]]>1){
				extraLeft++;
				frequencies[1][word[left++]]--;
			}
			if(currentK==k && vowels==5){
				response+=(1+extraLeft);
			}
			return response;
		}
	}
};

class GameOfLife{
public:
	void execute(){
		int cnt=0;

		vector<string> map={"01000010000000000001",
	                        "00010011010000000001",
	                        "01001010010000000001",
	                        "00010001100000000001",
	                        "01000001010000000001"};

	    for(){
	    	
	    }

	    print(map);
	}

	void print(vector<string> map){
		int life=223;
		for(int i=0; i<map.size(); i++){
	    	string it=map[i];
	    	for(char et: it){
	    		if(et=='0'){
	    			cout<<" ";
	    		}else cout<<char(life);
	    	}
	    	cout<<endl;
	    }
	};
};

int main(){
	GameOfLife game;

	game.execute();

	return 0;
}