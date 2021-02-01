//IMPORTANT: if the position given is outside the list, add() will place it at the end, and remove() and peek() will return -1
#include "AOList.h"
AOList::AOList(){
	top=nullptr;
}

//add value @ pos
void AOList::add(int new_value, int position){ //O(n) runtime
	//check if pos is valid
	if(position > -1){
		int counter=-1; 
		node *current=top;
		node *nextnode=top;
		node *new_node= new node();
		new_node->value = new_value;
		while(counter!=-2){
			counter++;
			//catches an empty list and end of list
			if(nextnode==nullptr){
				new_node->next = nextnode;
				//if our list wasnt empty, then we need to adjust current *
				if(current!=nullptr){
					current->next=new_node;
				}
				counter=-2; //end loop
			}
			//in position insertion
			else if(counter==position){
				new_node->next = nextnode;
				if(nextnode!=current){
					current->next=new_node;
				}
				
				counter=-2;
				
			}
			//iteration
			else{
				current=nextnode;
				nextnode=current->next;
			}
		}
		//is our new node the new top?
		if(new_node->next==top){
			top=new_node;
		}
	}
	//we could have an else case to handle an invalid position
}
// remove & return value @ pos
int AOList::remove(int position){ //O(n) runtime
	int result=-1;
	if(position > -1){
		int counter = -1;
		node *current=top;
		node *nextnode=top;
		while(counter!=-2){
			counter++;
			if(nextnode==nullptr){
				counter=-2;
			}
			else if(counter==position){
				result=nextnode->value;
				//if we are at the top of the list, top must move down ans possibly become nullptr
				if(current==nextnode){
					top=current->next;
				}
				else{
					current->next=nextnode->next;
				}
				//some operation could be included to free the memory
				counter=-2;
			}
			else{
				current=nextnode;
				nextnode=current->next;
			}
		}
	}
	return result;
	
}
// return value @ pos
int AOList::peek(int position){ //O(n) runtime
		int result=-1;
	if(position > -1){
		int counter = -1;
		node *current=top;
		node *nextnode=top;
		while(counter!=-2){
			counter++;
			if(nextnode==nullptr){
				counter=-2;
			}
			else if(counter==position){
				result=nextnode->value;
				counter=-2;
			}
			else{
				current=nextnode;
				nextnode=current->next;
			}
		}
	}
	return result;
	
}