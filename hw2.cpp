#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

class Commodity;
class Store;
class InputHandler;


class InputHandler {
public:
    /*
     * The function is used to read a full line into a string variable.
     * It read the redundant '\n' character to prevent the problem of getline function.
     * There is an overload version which can read from the specified data stream.
     * INPUT: None, or fstream
     * RETURN: Full line input by user
     * */
    static string readWholeLine() {
        string input;
        cin.get();
        getline(cin, input);
        return input;
    }

    static string readWholeLine(fstream& file) {
        string input;
        file.get();
        getline(file, input);
        return input;
    }

    /*
     * This function is used to configure whether the input string is a number
     * INPUT: A string
     * RETURN: Bool. True if input string is a number, otherwise false.
     */
    static bool isNum(string& str) {
        for (int i = 0; i < str.size(); i++) {
            if (!isdigit(str[i])) {
                return false;
            }
        }
        return true;
    }

    /*
     * Check the input string is a valid number.
     * First check the input is a number or not, then identify whether it is bigger than 0
     * INPUT: string
     * RETURN: bool
     */
    static bool isValidNum(string& str) {
        if (!isNum(str) || (isNum(str) && stoi(str) <= 0))
            return false;
        return true;
    }

    /*
     * Get a number from the user. This function will check the input validation.
     * INPUT: none
     * OUTPUT: integer, the input number
     */
    static int numberInput() {
        string input;
        cin >> input;
        while (!isValidNum(input)) {
            cout << "Please input again your input is NOT an integer or is lower than or equal to 0:" << endl;
            cin >> input;
        }
        return stoi(input);
    }

    /*
     * This function is used in function getInput. Check the input range is inside the specified range
     */
    static int inputCheck(string input, int maxChoiceLen, bool noZero) {
        // Change input to the general integer
        int choice = 0;
        for (int i = 0; i < input.size(); i++) {
            if (isdigit(input[i])) {
                choice = choice * 10 + (input[i] - '0');
            } else {
                return -1;
            }
        }

        if (noZero) {
            return (choice <= maxChoiceLen && choice > 0) ? choice : -1;
        } else {
            return (choice <= maxChoiceLen && choice >= 0) ? choice : -1;
        }
    }

    /*
     * Get the input from the user, and limit the input between the range [0, maxChoiceLen].
     * If noZero is signaled. Then the range will be [1, maxChoiceLen]
     * INPUT: integer, bool(option)
     * OUTPUT: integer, the choice number
     */
    static int getInput(int maxChoiceLen, bool noZero = false) {
        string input;

        cin >> input;
        int choice = inputCheck(input, maxChoiceLen, noZero);
        while (choice == -1) {
            cout << "your input is wrong, please input again:" << endl;
            cin >> input;
            choice = inputCheck(input, maxChoiceLen, noZero);
        }

        return choice;
    }
};

/*
 * Commodity is about an item which the user can buy and the manager can add or delete.
 * ATTRIBUTE:
 *  price: The price of the commodity, an integer.
 *  description: The text which describe the commodity detail, a string.
 *  commodityName: The name of the commodity, a string.
 */
class Commodity {
protected:
    int price;
    string description;
    string commodityName;

public:
    ~Commodity() = default;
    Commodity() {
        price = 0;
        description = "";
        commodityName = "";
    }

    Commodity(int price, string commodityName, string description) {
        this->price = price;
        this->commodityName = commodityName;
        this->description = description;
    }
    
    /*
     * This method will show the full information of the commodity to user interface.
     * There is a overloading version, with an argument amount which will output the information with the amount
     * INPUT: None, or an integer specify the amount of this commodity
     * RETURN: None
     */
    virtual void detail() {
        cout << commodityName << endl;
        cout << "price: " << price << endl;
        cout << "description: " << description << endl;
        cout << "----------------------------" << endl;
		}

    virtual void detail(int amount) {
        cout << commodityName << endl;
        cout << "price: " << price << endl;
        cout << "description: " << description << endl;
        cout << "x " << amount << endl;
        cout << "----------------------------" << endl;
    }

    /*
     * Use this function to get the information data from the user, this will init the object.
     * INPUT: none
     * OUTPUT: none
     */
    virtual void userSpecifiedCommodity() {
        cout << "Please input the commodity name:" << endl;
        commodityName = InputHandler::readWholeLine();
        cout << "Please input the commodity price:" << endl;
        price = InputHandler::numberInput();
        cout << "Please input the detail of the commodity:" << endl;
        description = InputHandler::readWholeLine();
    }

    /*
     * Save and load function is used to write the data to the file or read the data from the file.
     * According to the input parameter fstream, they complete the I/O on the specified file.
     * There have no definition of those method, because it is used to be override in the derived class.
     * INPUT: fstream
     * OUTPUT: none
     */
    virtual void save(fstream& file) {}

    virtual void load(fstream& file) {}

    /*
     * The getter function of commodityName
     */
    string getName() {
        return commodityName;
    }

    /*
     * The getter function of price
     */
    int getPrice() {
        return price;
    }
};



/*
 * [YOU SHOULD FINISH THREE TYPES OF DERIVED COMMODITY CLASS HERE]
 * Please try your best to complete the definition of three classes.
 * Use the knowledge you learned from this course.
 * You should follow the OOP concept.
 */
class phone:public Commodity{
	protected:
		int pixel;
		int capacity;
		int monitor;
	public:
		~phone() = default;
		phone(){
			pixel=0;
			capacity=0;
			monitor=0;
		}
		void detail() override
		{
			cout << commodityName << endl;
        	cout << "price: " << price << endl;
        	cout << "description: " << description << endl;
			cout<<"Pixel:"<<pixel<<"�U"<<endl;
			cout<<"Capacity:"<<capacity<<"GB"<<endl;
			cout<<"Monitor:"<<monitor<<"�T"<<endl; 
			cout << "----------------------------" << endl;
		}
		void detail(int amount) override
		{
			cout << commodityName << endl;
        	cout << "price: " << price << endl;
        	cout << "description: " << description << endl;
			cout<<"Pixel:"<<pixel<<"�U"<<endl;
			cout<<"Capacity:"<<capacity<<"GB"<<endl;
			cout<<"Monitor:"<<monitor<<"�T"<<endl;
			cout<<"x"<<amount<<endl;
			cout << "----------------------------" << endl;
		}
		void userSpecifiedCommodity() override
		{
	        cout << "Please input the commodity name:" << endl;
	        commodityName = InputHandler::readWholeLine();
	        cout << "Please input the commodity price:" << endl;
	        price = InputHandler::numberInput();
	        cout << "Please input the detail of the commodity:" << endl;
	        description = InputHandler::readWholeLine();
	        cout<<"What is the pixel of the phone:"<<endl;
			pixel=InputHandler::numberInput();cout<<"�U"<<endl; 
			cout<<"What is the capacity of the phone:"<<endl;
			capacity=InputHandler::numberInput();
			cout<<"What is the size of the phone:"<<endl;
			monitor=InputHandler::numberInput();
    	}
    	void save(fstream& file) override
    	{
    		file<<commodityName<<endl;
    		file<<price<<endl;
    		file<<description<<endl;
    		file<<pixel<<endl;
    		file<<capacity<<endl;
    		file<<monitor<<endl;
		}
		void load(fstream& file) override
		{
			getline(file, commodityName);
			file>>price;
			description = InputHandler::readWholeLine(file);
			file>>pixel>>capacity>>monitor;
		}
};
class clothes:public Commodity{
	protected:
		string kind;
		string color;
		string size;
		
	public:
		~clothes() = default;
		
		void detail() override
		{
			cout << commodityName << endl;
        	cout << "price: " << price << endl;
        	cout << "description: " << description << endl;
			cout<<"Kind:"<<kind<<endl;
			cout<<"Color:"<<color<<endl;
			cout<<"Size:"<<size<<endl; 
			cout << "----------------------------" << endl;
		}
		void detail(int amount) override
		{
			cout << commodityName << endl;
        	cout << "price: " << price << endl;
        	cout << "description: " << description << endl;
			cout<<"Kind:"<<kind<<endl;
			cout<<"Color:"<<color<<endl;
			cout<<"Size:"<<size<<endl;
			cout<<"x"<<amount<<endl;
			cout << "----------------------------" << endl;
		}
		void userSpecifiedCommodity() override
		{
	        cout << "Please input the commodity name:" << endl;
	        commodityName = InputHandler::readWholeLine();
	        cout << "Please input the commodity price:" << endl;
	        price = InputHandler::numberInput();
	        cout << "Please input the detail of the commodity:" << endl;
	        description = InputHandler::readWholeLine();
	        cout<<"What is the kind of the clothes:"<<endl;
			kind=InputHandler::readWholeLine(); 
			cout<<"What is the color of the clothes:"<<endl;
			color=InputHandler::readWholeLine();
			cout<<"What is the size of the clothes:"<<endl;
			size=InputHandler::readWholeLine();
    	}
    	void save(fstream& file) override
    	{
    		file<<commodityName<<endl;
    		file<<price<<endl;
    		file<<description<<endl;
    		file<<kind<<endl;
    		file<<color<<endl;
    		file<<size<<endl;
		}
		void load(fstream& file) override
		{
			getline(file, commodityName);
			file>>price;
			description = InputHandler::readWholeLine(file);
			kind=InputHandler::readWholeLine(file);
			color=InputHandler::readWholeLine(file);
			size=InputHandler::readWholeLine(file);
		}
};
class swatch:public Commodity{
	protected:
		string material;
		string color1;
		int weight;
	public:
		~swatch() = default;
		
		void detail() override
		{
			cout << commodityName << endl;
        	cout << "price: " << price << endl;
        	cout<<"Material:"<<material<<endl;
			cout<<"Color:"<<color1<<endl;
			cout<<"Weight:"<<weight<<endl;
			cout << "description: " << description << endl; 
			cout << "----------------------------" << endl;
		}
		void detail(int amount) override
		{
			cout << commodityName << endl;
        	cout << "price: " << price << endl;
        	cout << "description: " << description << endl;
        	cout<<"Material:"<<material<<endl;
			cout<<"Color:"<<color1<<endl;
			cout<<"Weight:"<<weight<<endl;
			cout<<"x"<<amount<<endl; 
			cout << "----------------------------" << endl;
		}
		void userSpecifiedCommodity() override
		{
	        cout << "Please input the commodity name:" << endl;
	        commodityName = InputHandler::readWholeLine();
	        cout << "Please input the commodity price:" << endl;
	        price = InputHandler::numberInput();
	        cout << "Please input the detail of the commodity:" << endl;
	        description = InputHandler::readWholeLine();
	        cout<<"What is the material of the swatch:"<<endl;
			material=InputHandler::readWholeLine(); 
			cout<<"What is the color of the swatch:"<<endl;
			color1=InputHandler::readWholeLine();
			cout<<"What is the weight of the swatch:"<<endl;
			weight=InputHandler::numberInput();
    	}
    	void save(fstream& file) override
    	{
    		file<<commodityName<<endl
    			<<price<<endl
    			<<description<<endl
    			<<material<<endl
    			<<color1<<endl
    			<<weight<<endl;
		}
		void load(fstream& file) override
		{
			getline(file, commodityName);
			file>>price;
			description = InputHandler::readWholeLine(file);
			material=InputHandler::readWholeLine(file);
			color1=InputHandler::readWholeLine(file);
			file>>weight;
		}
};

/*
 * [YOU NEED TO FINISH THIS CLASS]
 * This is a list storing the existing commodity in the store.
 * There are some method which can modify the content.
 * You may use any data structure to complete this class.
 */
class CommodityList {
private:
	unordered_map<string,vector<Commodity*>>commodities;
	vector<string>category={"phone","clothes","swatch"};
	string fileName="commodityList.txt";
public:

    CommodityList() {
		fstream file;
		file.open(fileName,ios::in);
		for(auto&cat:category){
			commodities[cat]=vector<Commodity*>();
		}
		if(file.is_open()){
			string cat;
			while(getline(file,cat)){
				int len=0;
				file>>len;
				file.get();
				for(int i=0;i<len;i++){
					Commodity*com;
					if(cat==category[0]){
						com=new phone();
					}else if(cat==category[1]){
						com=new clothes();
					}else if(cat==category[2]){
						com=new swatch();
						com->load(file);
						commodities[cat].push_back(com);
					}
			}
		}
	}
} 

    /*
     * Print the full information of the commodities inside the list
     * You must call Commodity.detail() to show the commodity information.
     * INPUT: None
     * RETURN: None
     */
    void showCommoditiesDetail() {
    	int no=1;
    	for(auto & entry : commodities){
    		cout<<entry.first<<":"<<endl;
			vector<Commodity*>& list=entry.second;
			for(auto item:list){
				cout<<no<<".  ";
				item->detail();
				no++;
			}
			cout<<endl; 
		}

    }

    /*
     * Print only the commodity name of the commodities inside the list
     * You don't need to use Commodity.detail() here, just call the Commodity.getName() function is ok
     * INPUT: None
     * RETURN: None
     */
    void showCommoditiesName() {
		int no=1;
		for(auto & entry : commodities){
			cout<<entry.first<<":"<<endl;
			vector<Commodity*>&list=entry.second;
			for(auto item:list){
				cout<<no<<".  "<<item->getName()<<endl;
				no++;
			}
			cout<<endl;
		}
		
    }

    /*
     * Check whether the list is empty or not
     * INPUT: None
     * RETURN: Bool. True if the list is empty, otherwise false
     */
    bool empty() {
    	for(auto & entry : commodities){
    		if(!entry.second.empty()){
    			return false;
			}
		}		return true;
    }

    /*
     * Return the size(or length) of the list
     * INPUT: None
     * RETURN: Integer. List size
     */
    int size() {
		int len=0;
		for(auto & entry : commodities){
			len+=(int)entry.second.size();
		}
		return len;
    }
    vector<string>getCategory(){
    	return category;
	}

    /*
     * Return a commodity object at specified position
     * INPUT: Integer. The index of that commodity
     * RETURN: Commodity. The wanted commodity object
     */
    Commodity* get(int index) {
		int catIndex=0;
		for(;catIndex<category.size();catIndex++){
			int len=(int)commodities[category[catIndex]].size();
			if(index>=len){
				index-=len;
			}else{
				break;
			}
		}
		return commodities[category[catIndex]][index];
    }

    /*
     * Push a new commodity object into the list
     * INPUT: Commodity. The object need to be pushed
     * RETURN: None
     */
    void add(Commodity* newCommodity,string& cat) {
		commodities[cat].push_back(newCommodity);
    }

    /*
     * Check the input commodity object is existing inside the list
     * If the commodity name is the same, we take those objects the same object
     * INPUT: Commodity. The object need to be checked
     * OUTPUT: Bool. True if the object existing, otherwise false
     */
    bool isExist(Commodity* commodity) {
		for(auto entry : commodities ){
			vector<Commodity*>list=entry.second;
			for(auto item : list){
				if(item->getName()==commodity->getName()){
					return true;
				}
			}
		}
		return false;
    }

    /*
     * Remove an object specified by the position
     * INPUT: Integer. The position of the object which need to be removed
     * OUTPUT: None
     */
    void remove(int index) {
    	int catIndex=0;
    	for(;catIndex<category.size();catIndex++){
    		int len=(int)commodities[category[catIndex]].size();
    		if(index>=len){
    			index-=len;
			}else{
				break;
			}
		}
		vector<Commodity*>&targetList=commodities[category[catIndex]];
		targetList.erase(targetList.begin()+index);
	}

    void save() {
		fstream file;
		file.open(fileName,ios::out | ios::trunc);
		for(auto & entry : commodities){
			string cat=entry.first;
			vector<Commodity*>&list=entry.second;
			file<<cat<<endl
				<<list.size()<<endl;
			for(auto&com : list){
				com->save(file);
			}
		} 
    }
};

/*
 * [YOU NEED TO FINISH THIS CLASS]
 * The shopping cart is used to store the commodities user wanted.
 * Because the same name represents the same object, if there is a commodity which have more than one object inside
 * the cart, then it will be store as the same object and the cart must keep the amount of the object.
 * You may use any data structure to complete this class.
 */
class ShoppingCart {
private:
	unordered_map<string, pair<Commodity*, int>> cart;
public:

    /*
     * Push an commodity object into the cart.
     * Be careful that if the input object is existing in the list, then keep the amount of that object rather than
     * actually push the object into the cart.
     * INPUT: Commodity. The object need to be pushed.
     * OUTPUT: None.
     */
    void push(Commodity* entry) {
		if(cart.count(entry->getName())){
			cart[entry->getName()].second++;
		}else{
			cart[entry->getName()].first = entry;
			cart[entry->getName()].second = 1;
		}
    }

    /*
     * Show the content of the cart to user interface.
     * INPUT: None.
     * OUTPUT: None.
     */
    void showCart() {
    	int no=1;
    	for(auto& item : cart){
    		pair<Commodity*, int>& entry = item.second;
    		cout<<no<<". "<<endl;
    		entry.first->detail(entry.second);
    		no++;
		}
	
    }

    /*
     * Return the cart size. (The same object must be seen as one entry)
     * INPUT: None.
     * OUTPUT: Integer. The cart size.
     */
    int size() {
    	return (int) cart.size();
    }

    /*
     * Remove an entry from the cart. Don't care about the amount of the commodity, just remove it.
     * INPUT: The order of the entry.
     * OUTPUT: None.
     */
    void remove(int index) {
		auto item = cart.begin();
		for(int i = 0 ; i < index; i++){
			item++;
		}
		cart.erase(item);
    }

    /*
     * Check the total amount of price for the user.
     * Remember to clear the list after checkout.
     * INPUT: None.
     * OUTPUT: Integer. The total price.
     */
    int checkOut() {
    	int total_price = 0;
    	for(auto& item : cart){
    		pair<Commodity*, int>& entry = item.second;
    		total_price += entry.first->getPrice() * entry.second;
		}
		
		cart.clear();
		return total_price;
		
    }

    /*
     * Check if the cart have nothing inside.
     * INPUT: None.
     * OUTPUT: Bool. True if the cart is empty, otherwise false.
     */
    bool empty() {
		return cart.empty();
    }
};

/*
 * [DO NOT MODIFY ANY CODE HERE]
 * The Store class manage the flow of control, and the interface showing to the user.
 * Store use status to choose the interface to show. As the result, status control is very important here.
 * If you can understand the code here, you will have great work on the above two class.
 * The detail of Store is in the README
 */
class Store {
private:
    enum UMode {USER, MANAGER} userStatus;
    enum SMode {OPENING, DECIDING, SHOPPING, CART_CHECKING, CHECK_OUT, MANAGING, CLOSE} storeStatus;
    CommodityList commodityList;
    ShoppingCart cart;
    
      /*
       * You should finish this method, because you need to identify the type of commodity, and instantiate a
       * corresponding derived commodity class here.
       */
    void commodityInput() {
    	Commodity*newCom;
    	
    	vector<string> category = commodityList.getCategory();
    	
        cout << "Which type of commodity you want to add?" << endl;
        cout<<"1.Phone"<<"   "<<"2.Clothes"<<"    "<<"3.Swatch"<<endl;
		
		int d = InputHandler::getInput(3);
		if(d==1)
		{
			newCom = new phone();
	        
		}
		else if(d==2)
		{
			newCom = new clothes();
			
		}else if(d==3){
			newCom = new swatch();
		}
	
		newCom->userSpecifiedCommodity();
		
		if(commodityList.isExist(newCom)){
			cout<<"[WARNING]"<<newCom->getName()
				<<" is exist in the store.If you want to edit it, please delete it first"<<endl;
		}else{
			commodityList.add(newCom, category[d - 1]);
		}
      

    }

    void deleteCommodity() {
        if (commodityList.empty()) {
            cout << "No commodity inside the store" << endl;
            return;
        }

        int choice;
        cout << "There are existing commodity in our store:" << endl;
        commodityList.showCommoditiesName();
        cout << "Or type 0 to regret" << endl
             << "Which one do you want to delete?" << endl;

        choice = InputHandler::getInput(commodityList.size());

        if (choice != 0) {
            commodityList.remove(choice - 1);
        }
    }

    void showCommodity() {
        if (commodityList.empty()) {
            cout << "No commodity inside the store" << endl;
            return;
        }

        cout << "Here are all commodity in our store:" << endl;
        commodityList.showCommoditiesDetail();
        cout << endl;
    }

    void askMode() {
        string input;

        cout << "Are you a general user or a manager?" << endl
             << "1. general user, 2. manager" << endl
             << "Or type 0 to close the store" << endl;

        int choice = InputHandler::getInput(2);

        userStatus = (choice == 2) ? UMode::MANAGER : UMode::USER;

        if (choice == 0) {
            storeStatus = SMode::CLOSE;
        } else if (userStatus == UMode::USER) {
            storeStatus = SMode::DECIDING;
        } else if (userStatus == UMode::MANAGER) {
            storeStatus = SMode::MANAGING;
        }
    }

    void decideService() {
        string input;

        cout << "Below are our service:" << endl
             << "1. Buy the commodity you want" << endl
             << "2. Check your shopping cart" << endl
             << "3. Check out" << endl
             << "Or type 0 to exit user mode" << endl
             << "You may choose what you need:" << endl;

        int choice = InputHandler::getInput(3);

        if (choice == 1) {
            storeStatus = SMode::SHOPPING;
        } else if (choice == 2) {
            storeStatus = SMode::CART_CHECKING;
        } else if (choice == 3) {
            storeStatus = SMode::CHECK_OUT;
        } else if (choice == 0) {
            storeStatus = SMode::OPENING;
        }
    }

    void chooseCommodity() {
        string input;
        showCommodity();
        cout << "Or input 0 to exit shopping" << endl;

        int choice = InputHandler::getInput(commodityList.size());

        // Push the commodity into shopping cart here
        if (choice == 0) {
            storeStatus = SMode::DECIDING;
        } else {
            // May be some bug here, test later
            cart.push(commodityList.get(choice - 1));
        }
    }

    void showCart() {
        if (cart.empty()) {
            cout << "Your shopping cart is empty" << endl;
            storeStatus = SMode::DECIDING;
            return;
        }

        int choice;
        do {
            cout << "Here is the current cart content:" << endl;
            cart.showCart();

            cout << "Do you want to delete the entry from the cart?" << endl
                 << "1. yes, 2. no" << endl;

            choice = InputHandler::getInput(2, true);

            if (choice == 1) {
                cout << "Which one do you want to delete(type the commodity index)?" << endl
                     << "Or type 0 to regret" << endl;
                int index = InputHandler::getInput(cart.size());
                // **
                if (index == 0) {
                    break;
                }
                cart.remove(index - 1);
            }
        } while (choice == 1);

        cout << "Do you want to checkout?" << endl
             << "1. yes, 2. No, I want to buy more" << endl;
        choice = InputHandler::getInput(2, true);
        if (choice == 1) {
            storeStatus = SMode::CHECK_OUT;
        } else {
            storeStatus = SMode::DECIDING;
        }
    }

    void checkOut() {
        if (cart.empty()) {
            cout << "Your shopping cart is empty, nothing can checkout" << endl;
        } else {
            cout << "Here is the current cart content:" << endl;
            cart.showCart();
            cout << "Are you sure you want to buy all of them?" << endl
                 << "1. Yes, sure, 2. No, I want to buy more" << endl;

            int choice = InputHandler::getInput(2, true);

            if (choice == 1) {
                int amount = cart.checkOut();
                cout << "Total Money: " << amount << endl;
                cout << "Thank you for your coming!" << endl;
                cout << "------------------------------" << endl << endl;
            }
        }

        storeStatus = SMode::DECIDING;
    }

    void managerInterface() {
        cout << "Here are some manager services you can use:" << endl
             << "1. Add new commodity" << endl
             << "2. Delete commodity from the commodity list" << endl
             << "3. Show all existing commodity" << endl
             << "Or type 0 to exit manager mode" << endl
             << "Which action do you need?" << endl;

        int choice = InputHandler::getInput(3);

        if (choice == 1) {
            commodityInput();
            
        } else if (choice == 2) {
            deleteCommodity();
        } else if (choice == 3) {
            showCommodity();
        } else if (choice == 0) {
            storeStatus = SMode::OPENING;
        }
    }

    void userInterface() {
        if (storeStatus == SMode::OPENING) {
            askMode();
        } else if (storeStatus == SMode::DECIDING) {
            decideService();
        } else if (storeStatus == SMode::SHOPPING) {
            chooseCommodity();
        } else if (storeStatus == SMode::CART_CHECKING) {
            showCart();
        } else if (storeStatus == SMode::CHECK_OUT) {
            checkOut();
        } else if (storeStatus == SMode::MANAGING) {
            managerInterface();
        } else if (storeStatus == SMode::CLOSE) {
            return;
        }
    }

public:
    Store() {
        userStatus = UMode::USER;
        storeStatus = SMode::CLOSE;
    }

    void open() {
        storeStatus = SMode::OPENING;
        while (storeStatus != SMode::CLOSE) {
            userInterface();
        }
        commodityList.save();
    }
};


int main() {
    Store csStore;
    csStore.open();
    return 0;
}
