/**
 * Stack class
 */
#ifndef _STACK_H
#define _STACK_H

#include<string>

/**
 * This class defines a LIFO stack
 * The stack stores the orders ready to be dispatched.
 * The printLabel function in the superMarket.h header file
 * will pop an order and write its contents to a file.
 */
using namespace std;

class Stack {
	public:
		int size = 0;
		int top = -1;

		/**
		 * constructor
		 */
		Stack(void) = default;

		/**
		 * Destructor
		 */
		~Stack(void);

		/**
		 * Push an order object to the top of the stack
		 */
		virtual void push(Order & order) = 0;

		/**
		 * Pop the top order from the stack
		 * to be processed by the printLabel function
		 */
		virtual Order & pop(void) = 0;

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
