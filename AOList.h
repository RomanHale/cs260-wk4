#include "AOList_node.h"
class AOList {
	private:
		node *top;
	public:
		AOList();
		void add(int new_value, int position);
		int remove(int position);
		int peek(int position);
	
};