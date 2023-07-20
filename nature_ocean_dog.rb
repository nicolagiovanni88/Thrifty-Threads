class ThriftyThreads

  # Define constants
  YOUR_TOTAL = 0
  TAX_RATE = 0.08

  def initialize
    @inventory = {}
    @grand_total = 0
    @total_items = 0
  end

  # Add items to the inventory
  def add_item(item, price)
    @inventory[item] = price
  end

  # Get the total of the items in the inventory
  def calculate_total
    @inventory.each { |item, price| @grand_total += price }
    @total_items = @grand_total
    @grand_total += (@grand_total * TAX_RATE)
  end

  # Calculate the discount
  def calculate_discount(discount_code)
    discount_amount = 0
    case discount_code.downcase
    when 'summer20'
      discount_amount = 0.2
    when 'bulkbuy25'
      discount_amount = 0.25
    when 'thrift50'
      discount_amount = 0.5
    end
    @grand_total -= (@grand_total * discount_amount)
  end

  # Checkout the items in the inventory
  def checkout
    calculate_total
    puts "Your total is: #{@grand_total}"
    puts "You have bought #{@total_items} items."
  end

end

# Create a new instance of ThriftyThreads
threads = ThriftyThreads.new

threads.add_item("T-shirt", 15.00)
threads.add_item("Jeans", 30.00)
threads.add_item("Socks", 10.00)

# Calculate the total with no discount
threads.checkout

# Calculate the total with 15% discount
threads.calculate_discount("SUMMER20")
threads.checkout