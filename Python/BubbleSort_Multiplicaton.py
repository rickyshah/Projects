
# *****************************************************
# # ---------- SORT A LIST : BUBBLE SORT ----------
# # The Bubble sort is a way to sort a list
# # It works this way
# # 1. An outer loop decreases in size each time
# # 2. The goal is to have the largest number at the end of
# #    the list when the outer loop completes 1 cycle
# # 3. The inner loop starts comparing indexes at the beginning
# #    of the loop
# # 4. Check if list[Index] > list[Index + 1]
# # 5. If so swap the index values
# # 6. When the inner loop completes the largest number is at
# #    the end of the list
# # 7. Decrement the outer loop by 1
#
# *****************************************************
#
import math
import random

# # a list with numbers in random orders
# numList = [1, 5, 9, 7, 3]
#
# # length of a list, 1 is deducted to match the index size
# # as index starts at 0
# i = len(numList) - 1
# print(i)
#
# while i > 1:
#
#     j = 0
#
#     while j < i:
#
#         # Tracks the comparison of index values
#         print("\nIs {} > {}".format(numList[j], numList[j + 1]))
#         print()
#
#         # If the value on the left is bigger switch values
#         if numList[j] > numList[j + 1]:
#
#             print("Switch \n")
#
#             # create a temp variable to store left value
#             temp = numList[j]
#
#             # assign right value to original left variable 'numList[j]
#             numList[j] = numList[j + 1]
#
#             # assign right value to 'temp', which is the new
#             # temporary variable to store left value
#             numList[j + 1] = temp
#
#         else:
#             print("Don't Switch \n")
#
#         j += 1
#
#         print(numList)
#
#     print("\nEND OF ROUND\n")
#
#     i -= 1
#
#
# print(numList)



# ---------- PROBLEM : CREATE MULTIPLICATION TABLE ----------
# With 2 for loops fill the cells in a multidimensional
# list with a multiplication table using values 1 - 9
'''
1, 2, 3, 4, 5, 6, 7, 8, 9,
2, 4, 6, 8, 10, 12, 14, 16, 18,
3, 6, 9, 12, 15, 18, 21, 24, 27,
4, 8, 12, 16, 20, 24, 28, 32, 36,
5, 10, 15, 20, 25, 30, 35, 40, 45,
6, 12, 18, 24, 30, 36, 42, 48, 54,
7, 14, 21, 28, 35, 42, 49, 56, 63,
8, 16, 24, 32, 40, 48, 56, 64, 72,
9, 18, 27, 36, 45, 54, 63, 72, 81
'''

# create a multi dimension list that contains 10 items ([0]*10), 10 times using range (range)
multipleTable = [[0] * 10 for i in range(10)]

# iterate 10 times starting at 1 using range
for i in range(1, 10):

    # use another loop to target particular matrix index of multi dimension list
    # this is similar to multi dimension array, two coordinates is used to get particular index value
    for j in range(1, 10):

        # whatever value is at index [i][j] at given time of list 'multipleTable',
        # multiply i and j
        multipleTable[i][j] = i * j

        # print list, and remove next line
        print(multipleTable[i][j], end=", ")

    # print new line when j loop ends to print
    # each number multiplication in a new line
    print()



