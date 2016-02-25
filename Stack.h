/**
 * Stack class
 */
#ifndef _STACK_H
#define _STACK_H

#include<string>

typedef int StackItemType;

/**
 * This class defines a LIFO stack
 * The stack stores the orders ready to be dispatched.
 * The printLabel function in the superMarket.h header file
 * will pop an order and write its contents to a file.
 */
using namespace std;

class Stack {
	private:
		StackItemType *items;
	public:
		int size = 0;
		int top = -1;

		/**
		 * constructor
		 */
		Stack(void) = default {
			top = -1;
			size = 0;
			items = NULL;
		}

		/**
		 * Destructor
		 */
		~Stack(void);

		/**
		 * Push an order object to the top of the stack
		 */
		virtual void push(Order & order) {
			if (top + 1 >= size) {
				items = (StackItemType *) realloc(items, (size * sizeOf(StackItemType));
			}
			
			items[++top] = order;

		}

		/**
		 * Pop the top order from the stack
		 * to be processed by the printLabel function
		 */
		virtual Order & pop(void) = 0 {
			items[top--];
		}

		/**
		 * Returns the current number of elements
		 * in the stack
		 */
		int stackSize(void){
			return size;
		};

		/**
		 * Determine if the stack is empty
		 */
		bool isEmpty(void) {
			return stackSize() == 0;
		}
};

#endif //_STACK_H
