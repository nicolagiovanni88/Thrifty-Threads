-- Thrifty Threads

--Declaring Constants
local CUSTOMER_GREETING = "Welcome to Thrifty Threads!"
local MAX_ITEMS = 20

--Declaring Global Variables
local items = {}
local discountPercent = 0
local customerName
local customerId

-- Utility Functions
--Function to print a greeting message
function printGreeting()
  print(CUSTOMER_GREETING)
end

--Function to add items to cart
function addItem(itemName, quantity)
  if(#items >= MAX_ITEMS) then
    print("Cannot add more than 20 items")
  else
    table.insert(items, {itemName, quantity})
    print("Added " .. quantity .. " " .. itemName .. " to cart")
  end 
end

--Function to remove items from cart
function removeItem(itemName)
  local found = false
  for i,item in ipairs(items) do 
    if(item[1] == itemName) then
      table.remove(items, i)
      found = true
      break
    end
  end
  if(not found) then
    print("Item not found")
  end
end

--Function to list the items in cart
function listItems()
  print("Items in cart:")
  for i,item in ipairs(items) do
    print(i, item[1], item[2])
  end
end

--Function to apply a discount
function applyDiscount(discount)
  discountPercent = discount
end

--Function to calculate the total cost of items in cart
function calculateTotal()
  local total = 0
  for i,item in pairs(items) do
    total = total + (item[2] * item[3])
  end
  total = total * (1 - (discountPercent / 100))
  print("Total cost of items in the cart is: " .. total)
end

--Function to set the customer name
function setCustomerName(name)
  customerName = name
end

--Function to set the customer ID
function setCustomerId(id)
  customerId = id
end

--Function to get the customer name
function getCustomerName()
  return customerName
end 

--Function to get the customer ID
function getCustomerId()
  return customerId
end

-- Main Script
--Print greeting message
printGreeting()

--Set customer name
setCustomerName("John Doe")

--Set customer ID
setCustomerId(12345678)

--Add items to cart
addItem("T-Shirt", 3, 10.50)
addItem("Jeans", 2, 20.00)
addItem("Hat", 1, 5.00)

--List items in cart
listItems()

--Apply a discount
applyDiscount(10)

--Calculate total cost
calculateTotal()