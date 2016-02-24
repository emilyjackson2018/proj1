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
		Order(const int orderNumber, const string &name, const string &item,const string &category, const string &shipArea);

		/**
		 * copy constructor
		 */
		Order(const Order &);

		/**
		 * copy operator
		 */
		Order & operator = (const Order &);

		/**
		 * Destructor
		 */
		~Order(void);
};
