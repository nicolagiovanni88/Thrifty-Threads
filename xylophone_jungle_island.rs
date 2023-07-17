//import modules
use std::io;

fn main() {
    println!("Welcome to Thrifty Threads!");

    loop {
        println!("What would you like to do?");

        println!("1. View Inventory");
        println!("2. Create an Account");
        println!("3. View Cart");
        println!("4. Checkout");
        println!("5. Quit");

        let mut choice = String::new();

        //get user choice
        io::stdin()
            .read_line(&mut choice)
            .expect("Failed to read line");

        let choice: u32 = match choice.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Please enter a valid number");
                continue;
            }
        };

        match choice {
            1 => view_inventory(),
            2 => create_account(),
            3 => view_cart(),
            4 => checkout(),
            5 => break,
            _ => println!("Invalid option"),
        }
    }
}

fn view_inventory() {
    println!("Here are our inventory items:");
}

fn create_account() {
    println!("Please enter your name:");
    let mut name = String::new();
    io::stdin()
        .read_line(&mut name)
        .expect("Failed to read line");
    println!("Your account has been created!");
}

fn view_cart() {
    println!("Your current cart contents:");
}

fn checkout() {
    println!("Continue to checkout? (Y/N)");
    let mut choice = String::new();
    io::stdin()
        .read_line(&mut choice)
        .expect("Failed to read line");

    match choice.trim() {
        "Y" | "y" => {
            println!("Please enter your payment information:");
            println!("Checkout complete!");
        }
        "N" | "n" => println!("Checkout cancelled."),
        _ => println!("Invalid option"),
    }
}