

# RECURSIVE FUNCTION
# A function that refers to itself is a recursive function

# *********************************************************************
# ---------- PROBLEM : CALCULATE FACTORIAL ----------
# Calculating factorials is commonly done with a recursive
# Example: To work out factorial of 3, we multiply 3
# by all the numbers below it
# function 3! = 3 * 2 * 1
# *********************************************************************
# def calFactorial(num):
#
#     if num <= 1:
#         return 1
#     else:
#
#         // the calFactorial function will be keep on calling (executing) itself until
#         // it satisfies the above condition and then it will end
#         result = num * calFactorial(num - 1)
#         return result
#
# print(calFactorial(3))




# *******************************************************************
# ---------- PROBLEM : CALCULATE FIBONACCI NUMBERS ----------
# To calculate Fibonacci numbers we sum the 2 previous values to
# calculate the next item in the list. We then only display the last
# number in the list rather than the entire sequence like below.

# Sample
# fibonnaci of number 6 will be: 1, 1, 2, 3, 5, 8 ...
# but we will only print (8), the last number in the sequence

# The Fibonacci sequence is defined by:
# Fn = Fn-1 + Fn-2
# Where F0 = 0 and F1 = 1
# *******************************************************************
'''
Detailed explanation of how the formula works
print(fib(3))

Fibonacci Formula:
fn = fn-1 + fn-2, and value of f0 and f1 are: f0 = 0 and f1 = 1

Above formula evaluates to : fn = f(n-1) + f(n-2), where fn = function, n = number

In the function fib(3), n = 3

Let result =  variable to hold result value

// we implement condition (f0 = 0, f1 =1)

if n <=0
then result = 0 (f0 = 0)

else if n == 1
then result = 1 (f1 =1)

else
// we implement the main formula, at start n = 3, so
result = fib(n-1) + fib(n-2) is equal to
result = fib(3-1) + fib(3-2)
result = fib(2) + fib(1) - one condition met f1 =1 so we can write fib(1) = 1
result = fib(2) +  1  - but fib(2) is still not complete, so the function continues, fib(2) =  fib(n-1) + fib(2-1)
result =[ fib(n-1) + fib(n-2) ] + 1
result = [ fib(2-1) + fib(2-2) ] + 1
result = [ fib(1) + fib(0) ] + 1 - again condition met, f1 =1 and f0 = 0, so
result = [1 + 0] + 1
result = 1 + 1
result = 2

'''


def calFibonacci(usrInput):

    if usrInput <= 0:
        return 0
    elif usrInput == 1:
        return 1
    else:
        result = calFibonacci(usrInput - 1) + calFibonacci(usrInput - 2)
        return result

print(calFibonacci(3))




# *****************************************************
# ---------- PROBLEM : Fibonacci sequence ----------
# Previously we only displayed 1 number in the Fibonacci sequence.
# This time we will display all of the numbers present in the
# fibonnaci sequence using previous created function,

# Sample Output
'''
How many Fibonacci values should be found : 30
1
1
2
3
All Done
'''
# *****************************************************
def calFibonacciSequence(usrInput):


# we loop until i is less than user input
    for i in range(usrInput):

# we pass (i's) value from range on every loop as the
# parameter to the above created calFibonacci function
# then we print the num
        print(calFibonacci(i))

    print("All done")

# ---------------- OR WE CAN ALSO DO -------------
# we loop until i is less than user input
    # i = 1
    # while i < usrInput:
    #

    #     fibNum = calFibonacci(i)
    #     print(fibNum)
    #     i += 1
    # print("All done!")
# ------------------------------------------------
calFibonacciSequence(5)
