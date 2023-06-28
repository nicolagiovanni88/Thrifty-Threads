#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class to represent a garment item
class Garment {
private:
	string type;
	string size;
	string color;
	int price;
public:
	Garment();
	Garment(string t, string s, string c, int p);
	string getType(){ return type; }
	string getSize(){ return size; }
	string getColor(){ return color; }
	int getPrice(){ return price; }
};

Garment::Garment(){
	type = "";
	size = "";
	color = "";
	price = 0;
}

Garment::Garment(string t, string s, string c, int p) {
	type = t;
	size = s;
	color = c;
	price = p;
}

// class to represent a thrifty threads store
class ThriftyThreads {
private:
	string storeName;
	vector<Garment> inventory;
public:
	ThriftyThreads(string name);
	void addItem(Garment g);
	string getStoreName();
	vector<Garment> getInventory();
};

ThriftyThreads::ThriftyThreads(string name) {
	storeName = name;
}

void ThriftyThreads::addItem(Garment g) {
	inventory.push_back(g);
}

string ThriftyThreads::getStoreName() {
	return storeName;
}

vector<Garment> ThriftyThreads::getInventory() {
	return inventory;
}

// class to represent a customer
class Customer {
private:
	string name;
	vector<Garment> cart;
public:
	Customer(string n);
	void addToCart(Garment g);
	string getName();
	vector<Garment> getCart();
	int calcTotal();
};

Customer::Customer(string n) {
	name = n;
}

void Customer::addToCart(Garment g) {
	cart.push_back(g);
}

string Customer::getName() {
	return name;
}

vector<Garment> Customer::getCart() {
	return cart;
}

int Customer::calcTotal() {
	int total = 0;
	for (int i = 0; i < cart.size(); i++) {
		total += cart[i].getPrice();
	}
	return total;
}

// Main function for test purposes
int main() {
	// create a new thrifty threads store
	ThriftyThreads tt("Thrifty Threads");

	// create some garments and add them to the store
	Garment g1("shirt", "XL", "white", 15);
	Garment g2("pants", "34", "black", 25);
	Garment g3("dress", "S", "red", 30);
	tt.addItem(g1);
	tt.addItem(g2);
	tt.addItem(g3);

	// create a customer
	Customer c("John");

	// add some items to the customer's cart
	c.addToCart(g1);
	c.addToCart(g2);

	// calculate the total
	cout << c.getName() << " total: $" << c.calcTotal() << endl;

	return 0;
}