#include <iostream>
#include <string>

using namespace std;

// Class to represent inventory item for sale
class InventoryItem {
private:
    string name;
    int quantity;
    double price;

public:
    // Default constructor
    InventoryItem() {
        name = "";
        quantity = 0;
        price = 0;
    }

    // Overloaded constructor
    InventoryItem(string n, int q, double p) {
        name = n;
        quantity = q;
        price = p;
    }

    // Accessors
    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }

    // Mutators
    void setName(string n) {
        name = n;
    }

    void setQuantity(int q) {
        quantity = q;
    }

    void setPrice(double p) {
        price = p;
    }
};

// Class to represent a line item in a customer's order
class LineItem {
private:
    InventoryItem item;
    int quantity;

public:
    // Default constructor
    LineItem() {
        item = InventoryItem();
        quantity = 0;
    }

    // Overloaded constructor
    LineItem(InventoryItem i, int q) {
        item = i;
        quantity = q;
    }

    // Accessors
    InventoryItem getItem() const {
        return item;
    }

    int getQuantity() const {
        return quantity;
    }

    double getLineTotal() const {
        return item.getPrice() * quantity;
    }

    // Mutators
    void setItem(InventoryItem i) {
        item = i;
    }

    void setQuantity(int q) {
        quantity = q;
    }
};

// Class to represent a customer's order
class Order {
private:
    int orderNumber;
    LineItem items[50];
    int itemCount;

public:
    // Default constructor
    Order() {
        orderNumber = 0;
        itemCount = 0;
    }

    // Overloaded constructor
    Order(int num, LineItem list[], int count) {
        orderNumber = num;
        itemCount = count;

        for (int i = 0; i < count; i++) {
            items[i] = list[i];
        }
    }

    // Accessors
    int getOrderNumber() const {
        return orderNumber;
    }

    int getItemCount() const {
        return itemCount;
    }

    LineItem getLineItem(int position) const {
        if (position >= 0 && position < itemCount) {
            return items[position];
        }
        else {
            return LineItem();
        }
    }

    double getOrderTotal() {
        double total = 0.0;

        for (int i = 0; i < itemCount; i++) {
            total += items[i].getLineTotal();
        }

        return total;
    }

    // Mutators
    void setOrderNumber(int num) {
        orderNumber = num;
    }

    void setItemCount(int count) {
        itemCount = count;
    }

    void addLineItem(LineItem item) {
        if (itemCount < 50) {
            items[itemCount] = item;
            itemCount++;
        }
    }
};

// Display an InventoryItem
void displayItem(InventoryItem item) {
    cout << "Item Name: " << item.getName() << endl;
    cout << "Quantity:  " << item.getQuantity() << endl;
    cout << "Price:     $" << item.getPrice() << endl;
}

// Display a LineItem
void displayItem(LineItem lItem) {
    InventoryItem item = lItem.getItem();
    cout << "Item Name: " << item.getName() << endl;
    cout << "Quantity:  " << lItem.getQuantity() << endl;
    cout << "Line Total:   $" << lItem.getLineTotal() << endl;
}

// Display an Order
void displayOrder(Order order) {
    cout << "Order:    " << order.getOrderNumber() << endl;
    cout << "Item Count:  " << order.getItemCount() << endl;

    for (int i = 0; i < order.getItemCount(); i++) {
        cout << "Line Item #" << (i + 1) << endl;
        LineItem lineItem = order.getLineItem(i);
        displayItem(lineItem);
    }

    cout << "Order Total:  $" << order.getOrderTotal() << endl;
}

int main() {
    // Create some items
    InventoryItem shirt("T-Shirt", 5, 14.99);
    InventoryItem pants("Jeans", 10, 25.99);
    InventoryItem socks("Socks", 6, 5.99);

    // Create an order
    LineItem lineItems[3];
    lineItems[0] = LineItem(shirt, 2);
    lineItems[1] = LineItem(pants, 1);
    lineItems[2] = LineItem(socks, 3);

    Order order(12345, lineItems, 3);

    // Display the Order
    displayOrder(order);

    return 0;
}