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
			Queue *newPtr = new Queue;

			newPtr->Order = newOrder;
			newPtr->next = NULL;
			
			if(isEmpty()) {
				head = newPtr;
			}
			else {
				tail->next = newPtr;
			}

			tail = newPtr;
		}

		/**
		 * Remove a queue member from the
		 * front of the queue
		 */
		virtual Order & dequeue(void) {
			if (isEmpty()) return false;

			Queue *tempPtr = head;
			if (head == tail) {
				head = NULL;
				tail = NULL;
			}
			else head = head->next;
			
			tempPtr->next = NULL;
			delete tempPtr;
			return true;
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
