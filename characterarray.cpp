/* Zoilo Mercedes
 * Character Array
 * https://leetcode.com/discuss/interview-question/124571/Character-Array/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool ArraysAreEqual(vector<string>& a, vector<string>& b){
	if(a.size() != b.size())
		return false;

	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i])
			return false;
	}

	return true;
}

void ArrayPass(vector<string>& a, int& i){
	if(i < a.size()){
		if(a[i] == "<"){
			if(i > 0){
				a.erase(a.begin() + i);
				a.erase(a.begin() + i -1);
				i=i-2;
			}
		}
		i++;
	}
}

bool ArrayCompare(vector<string>& a, vector<string>& b){
	if(ArraysAreEqual(a,b))
		return true;

	int indexA = 0;
	int indexB = 0;

	while(indexA < a.size()  || indexB < b.size()){
		ArrayPass(a, indexA);
		ArrayPass(b, indexB);
	}	

	return ArraysAreEqual(a,b);
}

int main(){
	
	vector<vector<string>> holder = {{"1","2","3","<","<","<","4","<","5"},{"1","2","<","8","<","<","5","5","<"},{"1","2","3","<","4","<","5"},{"1","2"},{"1","2","3","<","4","<"},{"1","2"}};

	for(int i = 0; i< holder.size();i=i+2){
		if(ArrayCompare(holder[i], holder[i+1]))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
}