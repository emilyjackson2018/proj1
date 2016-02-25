/**
 * Queue class
 */

#ifndef _QUEUE_H
#define _QUEUE_H

/**
 * The queue will store orders until the order dispatcher
 * dequeues the order and pushes it onto a stack.
 * Each category of product will have different order queues.
 */
#include <string>
#include "Order.h"
using namespace std;

class Queue {
	private LinkedList list;
	public:
		int head = 0;
		int tail = -1;
		string category = ""; // the product category whose orders are stored in this queue.

		int *backPtr;
		int *frontPtr;

		/**
		 * Default constructor
		 */
		Queue(void) = default {
			tail = head = NULL;
		}

		/**
		 * Constructor
		 */
		Queue(string category) {
			tail = head = category;
		}

		/**
		 * Destructor
		 */
		~Queue(void) { 
			while (!isEmpty()) {
				dequeue();
			}
		}

		/**
		 * Insert a member into the queue
		 * at the end
		 */
		virtual void enqueue(Order &) {
			LinkedList *newPtr = new LinkedList;

			newPtr->list = list;
			newPtr->next = NULL;
			
			if(isEmpty()) {
				frontPtr = newPtr;
			}
			else {
				backPtr->next = newPtr;
			}

			backPtr = newPtr;
		}

		/**
		 * Remove a queue member from the
		 * front of the queue
		 */
		virtual Order & dequeue(void) {
			Queue *tempPtr = frontPtr;
			if (frontPtr == backpPtr) {
				frontPtr = NULL;
				backPtr = NULL;
			}
			else frontPtr = frontPtr->next;
			
			tempPtr->next = NULL;
			delete tempPtr;
		}

		/**
		 * Returns the current size of the queue
		 */
		virtual int queueSize(void) {
			return list.size();
		}

		/**
		 * Returns true if the queue is empty
		 */
		bool isEmpty() {
			return queueSize() == 0;
		}
};

#endif //_QUEUE_H
