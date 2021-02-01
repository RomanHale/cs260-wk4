#include <iostream>
#include "AOList.cpp"

using std::cout;
using std::cin;
using std::endl;
int main(int argc, char **argv) {
	AOList *myAOList= new AOList;
	cout<<"Attempting to peek an empty AOList at pos 0: "<<myAOList->peek(0)<<endl; //expected result: -1
	cout<<"Attempting to remove from an empty AOList at pos 0: "<<myAOList->remove(0)<<endl; //expected result: -1
	myAOList->add(1,0);
	cout<<"Adding value 1 @ pos 0: then peeking at pos 0: "<<myAOList->peek(0)<<endl;
	myAOList->add(2,0);
	cout<<"Adding value 2 @ pos 0: then peeking at pos 0: "<<myAOList->peek(0)<<endl;
		myAOList->add(3,0);
	cout<<"Adding value 3 @ pos 0: then peeking at pos 0: "<<myAOList->peek(0)<<endl;
	myAOList->add(7,1);
	cout<<"Adding value 7 @ pos 1 then peeking pos 1: "<<myAOList->peek(1)<<endl;//expected result: 7
	cout<<"Peeking positions 0,1,2,3: "<< myAOList->peek(0)<<", "<<myAOList->peek(1) <<", "<<myAOList->peek(2) <<", "<<myAOList->peek(3) <<endl;// expected result: 3,7,2,1
	cout<<"Removing 7 from pos 1 and returning it here: "<<myAOList->remove(1)<<endl;
	cout<<"Peeking positions 0,1,2,3: "<< myAOList->peek(0)<<", "<<myAOList->peek(1) <<", "<<myAOList->peek(2) <<", "<<myAOList->peek(3) <<endl;// expected result: 3,2,1,-1
	cout<<"Let's remove the front and end of the list, test, and call it a day: "<<endl<<"Front of list: "<<myAOList->remove(0)<<"	Back of list: "<<myAOList->remove(1)<<endl;// expected results: 3,1
	cout<<"Our magic surviving value is: " <<myAOList->peek(0)<<endl;//expected result: 2
}