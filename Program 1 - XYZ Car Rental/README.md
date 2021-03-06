# XYZ Car Rental 

You have been hired by XYZ Car Rental to develop a software system for their business.

Your program will have two unordered lists, one of Cars and one of Reservations
    
Car
---
The Car class will have the following data: 
string plateNumber (this is the key)
string make 
string model 
enum vehicleType (VehicleType Enumeration of options: sedan, suv, exotic) 
double pricePerDay 
bool isAvailable isAvailable should be set to true on initialization,
and a public setter method should be exposed SetAvailable(bool available); 

Reservation
-----------
Reservation will have the following:
string name (key) 
string vehicleRented (plate of the car which is our key for the list)

Program
-------
The Program class will be composed of the two lists. There will also be a method to display a menu
that will have the following options, Create a method to process the user's input and call appropriate methods to
perform the operation requested. (Use a switch statement and call the appropriate methods based on the number
the user puts in) 

XYZ Car Rental 
------------------------------------------------------------------------------------------------------
1. List all cars 
2. Add car to inventory 
3. Remove car from inventory 
4. List all reservations 
5. Add a reservations 
6. Cancel reservation 
7. Exit 
	
Option 1: List all the cars in the unordered list of cars (Overload the << operator like my example to print each car's info)

Option 2: Prompt for all the information for a vehicle. Create the vehicle and add it to the list of available vehicles 
	
Option 3: Remove a vehicle from the list of available cars. If the car is not available (a user has rented it) return an error message and don't remove the vehicle 
	
Option 4: List all the reservations. Use the key in the reservation to retrieve the vehicle details from the list of vehicles 
	
Option 5: Prompt the user for a name. 
List all the cars that are available (isAvailable=true):
1. Nissan Sentra (sedan) $24/day 
2. ... n+1. 
Cancel 
Prompt the user to enter an option. 
Your list will need to implement a GetItemAtIndex method which will let you select a vehicle based on
the menu option. For example if the user selects 1, you would call GetItemAtIndex(choice - 1).
Make sure this returns a car reference: Car& GetItemAtIndex(int index) 
Create a reservation object with this car's plate and the user's name, 
and call the car's SetAvailable method with false passed as the argument; 
If cancel is pressed, show all the original options again
	
Option 6: Propt the user for a name. Remove the reservation object from the list if that user's name is a key.
Use the plate number to find the car in the list and set available to true (Make sure the GetItem method returns a
reference) 

At the end of each option's method (except Exit) make sure to list the menu options again.
For Exit, quit the program.
