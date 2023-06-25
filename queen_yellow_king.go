package main

import "fmt"

//Person struct, containing name, email address and shopping cart
type Person struct {
	name string
	email string
	cart []CartItem
}

//CartItem Struct containing item name and quantity 
type CartItem struct {
	name string
	quantity int
}

//Tshirt struct detailing description, price and size 
type Tshirt struct {
	description string
	price float64
	size int
}

//Discount struct containing discount amount 
type Discount struct {
	amount float64
}

//Customer struct for customers, contains info relating to account, discount and cart 
type Customer struct {
	account Account
	discount Discount
	cart []CartItem
}

//Account Struct containing customer ID, name and address 
type Account struct {
	customerID string
	name string
	address string
}

//Checkout function for processing payments 
func Checkout(customer *Customer) float64 {
	//Calculate total price of all items in the cart
	totalPrice := 0.0
	for _, cartItem := range customer.cart {
		if cartItem.name == "Tshirt" {
			tshirt := Tshirt{
				description: "Thrifty Threads Tshirt",
				price: 24.99,
				size: 10,
			}

			//Calculate item price 
			itemPrice := tshirt.price * float64(cartItem.quantity)

			//Discounted amount is applied if it is more than 0 
			if customer.discount.amount > 0 {
				itemPrice = itemPrice - (itemPrice * customer.discount.amount)
			}

			//Add item price to total price 
			totalPrice += itemPrice
		}
	}

	return totalPrice
}

//PrintCart function for printing user shopping cart 
func PrintCart(person *Person) {
	//Check that cart is not empty 
	if len(person.cart) == 0 {
		fmt.Println("Cart is empty")
		return
	}

	//Loop over cart and print each item 
	fmt.Printf("%s's Shopping Cart\n", person.name)
	for _, item := range person.cart {
		fmt.Printf("Item: %s, Quantity: %d\n", item.name, item.quantity)
	}
	fmt.Println()
}

//AddToCart function for adding item to cart 
func AddToCart(person *Person, item CartItem) {
	person.cart = append(person.cart, item)
}

//RemoveFromCart function for removing item from cart 
func RemoveFromCart(person *Person, name string) bool {
	//Loop over cart items 
	for i := 0; i < len(person.cart); i++ {
		//Check for item name 
		if person.cart[i].name == name {
			//Delete item from cart 
			copy(person.cart[i:], person.cart[i+1:])
			person.cart[len(person.cart)-1] = CartItem{}
			person.cart = person.cart[:len(person.cart)-1]
			return true
		}
	}

	return false
}

//SetDiscount function for setting a discount for the customer
func SetDiscount(customer *Customer, amount float64) {
	// Set customer discount amount
	customer.discount.amount = amount
}

//CreateAccount function for creating a customer account 
func CreateAccount(customer *Customer, id string, name string, address string) {
	//Set account info 
	customer.account.customerID = id
	customer.account.name = name
	customer.account.address = address
}

func main() { 
	//Create new person 
	person := Person{
		name:   "John Doe",
		email:  "john.doe@example.com",
		cart:   []CartItem{},
	}

	//Create new customer 
	customer := Customer{
		account: Account{
			customerID: "123",
			name:       "John Doe",
			address:    "123 Main Street, Anywhere USA",
		},
		discount: Discount{
			amount: 0,
		},
		cart: []CartItem{},
	}

	//Add items to person's cart 
	AddToCart(&person, CartItem{name: "Tshirt", quantity: 1})
	AddToCart(&person, CartItem{name: "Shoes", quantity: 2})

	//Print cart 
	PrintCart(&person)

	//Remove item from cart 
	RemoveFromCart(&person, "Shoes")
	fmt.Println("Item removed from cart")

	//Print cart 
	PrintCart(&person)

	//Add the same items to customer cart 
	AddToCart(&customer, CartItem{name: "Tshirt", quantity: 1})
	AddToCart(&customer, CartItem{name: "Shoes", quantity: 2})

	//Set 10% discount for customer 
	SetDiscount(&customer, 0.1)

	//Calculate total price for customer 
	totalPrice := Checkout(&customer)
	fmt.Printf("Total Price (with discount): %.2f\n", totalPrice)
}