/**
 * Order class
 */
#include <string>
using namespace std;

class Order {
	public:
		int orderNumber = -1;
		string name = "";
		string item = "";
		string category = "";
		string shipArea = "";

		/**
		 * Default Constructor
		 */
		Order() = default;


		/**
		 * Constructor
		 */
		Order(const int orderNumber, const string &name, const string &item,const string &category, const string &shipArea) {
			this->orderNumber = orderNumber;
			this->name = name;
			this->item = item;
			this->category = category;
			this->shipArea = shipArea;
			
		}

		/**
		 * copy constructor
		 */
		Order(const Order & order) {
			this->orderNumber = orderNumber;
			this->name = name;
			this->item = item;
			this->category = category;
			this->shipArea = shipArea;
		}

		/**
		 * copy operator
		 */
		Order & operator = (const Order & order) {
			orderNumber = order.orderNumber;
			name = order.name;
			item = order.item;
			category = order.category;
			shipArea = order.shipArea;	
		}	

		/**
		 * Destructor
		 */
		~Order(void) {
			delete Order;
		}
};
