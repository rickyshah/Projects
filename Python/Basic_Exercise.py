# **********************************************************************************************************************
# ---------- Exercise 1 ----------
# If a number is division by 3, print out string 'Fizz'
# If a number is division by 5, print out string 'Buzz'
# If a number is divisible by both '3' and '5', print 'FrizzBuzz'
# if the number is not divisible by '3' or '5', print the same number
# **********************************************************************************************************************

# # OPTION 1
#------------
# userInput = eval(input("Enter a number: "))

# if userInput % 3 == 0 and userInput % 5 == 0:
#     print("FizzBuzz")
# elif userInput % 5 == 0:
#     print("Buzz")
# elif userInput % 3 == 0:
#     print("Fizz")
# else:
#     print(userInput)

# # OPTION 2
#-------------
# def fizz_buzz(input):
#     if (input % 3 == 0) and (input % 5 == 0):
#         return "FizzBuzz"
#     elif input % 5 == 0:
#         return "Buzz"
#     elif input % 3 == 0:
#         return "Fizz"
#     return input


# print(fizz_buzz(7))

# **********************************************************************************************************************
# ---------- Exercise 2 ----------
# Have the user enter their investment amount and expected interest
# Each year their investment will increase by their investment +
# their investment * the interest rate
# Print out their earnings after a 10 year period
# **********************************************************************************************************************


# # OPTION 1
# #------------
#
# client_Investment, interest = input("Enter investment amount and expected interest: ").split()
#
# client_Investment = int(client_Investment)
# interest = int(interest)
#
# for x in range(10):
#     yearly_Return = client_Investment + (client_Investment * interest / 100)
#     client_Investment = yearly_Return
# print(f"The total return after 10 years is: {client_Investment}")
#
#
# # OPTION 2
# #----------
#
# # Ask for money invested + the interest rate
# money = input("How much to invest: ")
# interest_rate = input("Interest Rate: ")
#
# # Convert value to a float
# money = float(money)
#
# # Convert value to a float and round the percentage rate by 2 digits
# interest_rate = float(interest_rate) * .01
#
# # Cycle through 10 years using for and range from 0 to 9
# for i in range(10):
#     # Add the current money in the account + interest earned that year
#     money = money + (money * interest_rate)
#
# # Output the results
# print("Investment after 10 years: {:.2f}".format(money))
