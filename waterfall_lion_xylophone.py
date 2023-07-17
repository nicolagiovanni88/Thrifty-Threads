# Thrifty Threads 

# imports
import os 
import sys
import json 

# Variables 
dir_path = os.getcwd()
new_dir_path = os.path.join(dir_path, "thrifty_threads")

# Create a directory 
if not os.path.exists(new_dir_path):
    os.mkdir(new_dir_path)

# Classes
class Item:
    def __init__(self, name, price, category, color):
        self.name = name
        self.price = price
        self.category = category
        self.color = color 

#Functions 
def get_user_input():
    item_name = input("Enter the item name: ")
    item_price = float(input("Enter the item price: "))
    item_category = input("Enter the item category: ")
    item_color = input("Enter the item color: ")
    return item_name, item_price, item_category, item_color

def create_item():
    item_name, item_price, item_category, item_color = get_user_input()
    new_item = Item(item_name, item_price, item_category, item_color)
    return new_item

def save_item(item):
    item_path = os.path.join(new_dir_path, item.name.lower()+".txt")
    item_file = open(item_path, "w+")
    item_file.write(str(item.__dict__))
    item_file.close()

def load_items():
    items_dict = {}
    for item_file in os.listdir(new_dir_path):
        item_path = os.path.join(new_dir_path, item_file)
        item = open(item_path, "r")
        item_dict = json.load(item)
        item_obj = Item(item_dict["name"], item_dict["price"], item_dict["category"], item_dict["color"])
        items_dict[item_file] = item_obj
        item.close()
    return items_dict

# Main
if __name__ == "__main__":
    items = load_items()

    # Main program loop
    running = True
    while running:
        print("Welcome to Thrifty Threads!")
        print("Options:")
        print("1. Add item")
        print("2. View items")
        print("3. Quit")

        option = int(input("Please select an option: "))

        if option == 1:
            # Create item
            item = create_item()
            # Save item
            save_item(item)
            print("Item saved.")
            print(item.__dict__)
        
        elif option == 2:
            # Load items
            items = load_items()
            # Print items
            print("Items:")
            for item in items.values():
                print(item.__dict__)

        elif option == 3:
            running = False
            print("Thank you for using Thrifty Threads!")
            sys.exit()