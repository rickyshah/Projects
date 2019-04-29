# *****************************************************************
# # ---------- PROBLEM : CREATE A CUSTOMER LIST ----------
# # Create an array of customer dictionaries
# # Output should look like this
# '''
# Enter Customer (Yes/No) : y
# Enter Customer Name : Derek Banas
# Enter Customer (Yes/No) : y
# Enter Customer Name : Sally Smith
# Enter Customer (Yes/No) : n
# Derek Banas
# Sally Smith
# '''
# ******************************************************************

# # Create customer array outside the for so it isn't local
# # to the while loop
# customers = []
#
# while True:
#
#     # Cut off the 1st letter to cover if the user
#     # types either 'y' or 'n'
#     createEntry = input("Enter Customer (Yes/No) : ")
#     createEntry = createEntry[0].lower()
#
#     if createEntry == "n":
#
#         # Leave the while loop when n is entered
#         break
#     else:
#
#         # Get the customer name by splitting at the space
#         fName, lName = input("Enter Customer Name : ").split()
#
#         # Add the dictionary to the array
#         customers.append({'fstName': fName, 'lstName': lName})
#
# # Print out customer list
# for custName in customers:
#     print(custName['fstName'], custName['lstName'])


# # OPTION 2
# customerList = []
# usrInput = input("Enter customer (y/n): \n")
# confirstLetter = usrInput[0].lower()
#
# while True:
#     try:
#         if confirstLetter == "y":
#
#             usrFname, usrLname = input("Enter customer full name: \n").split()
#             customerList.append({"First Name": usrFname, "Last Name": usrLname});
#             usrInput = input("Enter customer (y/n): \n")
#             confirstLetter = usrInput[0].lower()
#
#         elif confirstLetter == "n":
#             print(customerList)
#             break
#
#         else:
#             print("******** Please enter y/n only *********")
#             usrInput = input("Enter customer (y/n): \n")
#             confirstLetter = usrInput[0].lower()
#
#     except ValueError:
#         print("**** Please enter 'first name' and 'last name only separted with a space! ******")
#
#     # We can target all other errors with a default
#     except:
#         print("An unknown error occurred")
#
# print("Thank you!")





