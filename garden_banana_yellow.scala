object ThriftyThreads {  

    // Main method  
    def main(args: Array[String]) {  
    
        // Declare variables
        var storeIncome = 0.0
        var weeklySalesRevenue = 0.0
        var totalEmployees = 0
        var storeLocation = ""
        var storeHours = 0
        var storeDepartment = ""
        var storeCustomers = 0
        
        // Welcome customers
        println("Welcome to Thrifty Threads, your one-stop shop for all your clothing needs!")
        
        // Ask user for store characteristics
        println("What is the store's income?:")
        storeIncome = scala.io.StdIn.readLine.toDouble
        
        println("What are the store's weekly sales revenue?:")
        weeklySalesRevenue = scala.io.StdIn.readLine.toDouble
        
        println("How many employees does Thrifty Threads have?:")
        totalEmployees = scala.io.StdIn.readLine.toInt
        
        println("Where is the store located?:")
        storeLocation = scala.io.StdIn.readLine
        
        println("How many store hours does Thrifty Threads operate?:")
        storeHours = scala.io.StdIn.readLine.toInt
        
        println("What is the store's department?:")
        storeDepartment = scala.io.StdIn.readLine
        
        println("How many customers visit Thrifty Threads daily?:")
        storeCustomers = scala.io.StdIn.readLine.toInt
        
        // Output information about Thrifty Threads
        println("Thrifty Threads has an income of " + storeIncome + " and weekly sales revenue of " + weeklySalesRevenue + 
                " and a total of " + totalEmployees + " employees. The store is located in " + storeLocation + 
                " and is open for " + storeHours + " hours a day. The store's department is " + storeDepartment + 
                " and it has a total of " + storeCustomers + " customers daily.")
        
        // Ask user to shop
        println("Come shop at Thrifty Threads today for all your clothing needs!")
    } 
}