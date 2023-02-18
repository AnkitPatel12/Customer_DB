# Customer_DB

When main.cpp is run, it reads input commands from a text file with
a specified format, i.e., a series of one-word commands and arguments for each command.
The required read function is provided to you. As each command is read from the input file, it
is parsed (code provided), and then each command is executed (your code). The command
processing functions (and helper functions) that you write must interact with a database
(which is represented as an array of structs) that is provided to you BUT must be modified
and read by you in your code.

Input: Your system will read input from a file. The file contains a sequence of commands.
Each command begins with one of four keywords. The remainder of the command depends
upon the keyword.

• Inventory <type> # – This command is used to record a new shipment from the
factory into the store’s inventory. To read this command you must read from the file
the type of item received (Bottles, Diapers, or Rattles) and the number of items in this
shipment. You should then increase the store’s inventory by that amount. For example:
“Inventory Bottles 50” means that 50 bottles should be added to the store’s inventory.
• Purchase <name> <type> # – This command is used to record a purchase by a
customer. Each customer is known by their first name (it’s a very friendly company),
so <name> will be a one-word string for the customer’s name. The
<type> is once again Bottles, Diapers, or Rattles and is used to indicate what type of
item this customer purchased. Finally, the last part of the command is the number of
items purchased. For example, “Purchase Frank Diapers 100” means that the customer
“Frank” has purchased 100 Diapers.
• Summarize – This command requests that a summary be printed of the store’s
activity.
• Quit – This command terminates the input.

processInventory() – This function should read the item type and quantity
from the input file and update the store’s inventory of the indicated item type.

• processPurchase() – This function should read the customer’s name, the item
type and the quantity. The function should look up the customer in the customer
database (creating a new customer record if this is a 1st
-time customer) and increment the number of items purchased by this customer in their customer record. For example,
if the customer record indicates that “Frank” had previously purchased 10 diapers and
the current command indicates that “Frank” is purchasing 20 diapers, then the customer
record should be set to indicate that 30 diapers have been purchased by Frank. Note
that each customer should have their own customer record (so that Ellie can keep track
of who her best customers are and offer incentives like coupons and things).
  
• processSummarize() – This command should print out a summary. The
summary should first display the number of Bottles, Rattles, and Diapers remaining in
inventory at the time of the Summarize command. Next, the summary should display
how many different customers have come to the store for purchases. Finally, the
summary should report which customer purchased the most diapers (and how many
diapers), who purchased the most bottles (and how many) and who purchased the most
rattles (and how many). If a certain item has not been purchased by anybody, then the
summary should indicate that.

