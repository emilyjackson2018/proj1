/**
 * LinkedList class
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Queue.h"
#include <string>

using namespace std;
// forward declaration of LinkedList

class LinkedList;

/**
 * Represents a node in a doubly-linked list.
 * A node represent a category of product in the store.
 * Each node stores information about the number of orders
 * in that category that needs to be dispatched.
 */

class Node {
	friend class LinkedList;
	private:
	string category = "";   // The category of products in this node.
	Queue &orderQueue; // The order queue for this category.
	Node * prev = nullptr;
	Node * next = nullptr;
	public:
	int orderCount; // The number of orders in this node/category of product to dispatch.

	/**
	 * Parameterized Constructor
	 */
	Node(Node * prev, Node * next, string category, Queue &orderQueue);

}; // Node

/**
 * A doubly-linked list data structure.
 */

class LinkedList {
	private:
		Node * headptr = nullptr;
		Node * tailptr = nullptr;
	public:
		int length = 0;

		/**
		 * Adds an item to the end of this list.
		 *
		 * @param category The category of the queue, the node having this queue is being appended
		 * @param orderQueue The queue this node will have
		 */
		void append(string category, Queue &orderQueue) {
			Node *newnode = new Node;
			newnode->orderQueue = orderQueue;
			newnode->next = NULL;	
			if (length == 0) {
				headptr = newnode;
			}
			else {
				Node *temp = headptr, *prev = NULL;
				int pos = 0;
			}

			while (pos < length) {
				prev = temp;
				temp = temp->next;
				++pos;
			}
			newnode->next = temp;

			if (pos == 0) {
				headptr = newnode;
			}	
			else {
				prev->next = newnode;
			}
			
			++length;
		}

		/**
		 * Returns the queue for a given category.
		 * Use this to quickly get the required queues
		 * for enqueue and dequque operations.
		 * @param cat the category for the required queue. 
		 */
		Queue & getQueueByCat(string cat) {
			Node *temp = headptr;
			while (temp != NULL) {
				cout << temp->cat << " ";
				temp ->next;
			}
			cout << endl;
		}

		/**
		 * Sets the value of orderCount for the given category.
		 *
		 * @param cat the category name
		 * @param count the numbe of orders to dispatch
		 */
		void setOrderCount(string cat, int count) {
			
		}

		/**
		 * Returns the number of elements in this list.
		 */
		const int size() const {
			return size();	
		}

		/**
		 * Returns whether or not this linked list is empty. 
		 */
		const bool empty() const {
			return size() == 0;
		} // empty
}; // LinkedList
#endif /** LINKED_LIST_H */
