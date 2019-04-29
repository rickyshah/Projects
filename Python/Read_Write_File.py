
# ***********************************************************************
# ---------- PROBLEM : READ AND WRITE FILE(ANALYZE THE FILE) ----------
# As we cycle through each line output the number of
# words and average word length

# ***********************************************************************

# The os module provides methods for file processing
import os


'''
Line 1
Number of Words : 3
Avg Word Length : 4.7
Line 2
Number of Words : 3
Avg Word Length : 4.7

'''
# --------------------- OPTION 1-------------------------

# Open the file
with open("mydata2.txt", encoding="utf-8") as myFile:

    # create variable to track each line number read
    lineNum2 = 1


    # while loop that loops until the data
    # read is empty
    while True:

        # assign read line of a file function to variable 'line'
        line = myFile.readline()

        # if 'line' is empty meaning no line to read, then exit
        if not line:
            break

        print("Line", lineNum2)


        wordsplit = line.split()

        NumOfWords = len(wordsplit)

        print("Number of words: ", NumOfWords)


        countLengthofEachWord = 0
        
        for i in wordsplit:
            countLengthofEachWord += len(i)

        # ---- OR CAN ALSO DO -----
        #
        # for i in wordsplit:
        #     for j in i:
        #         counterForAvg += 1
        # ---------------------------

        # calculate average word length
        avgWordLength = countLengthofEachWord/NumOfWords

        # print average word length only upt to 2 decimal {:.2}
        print("Average word length: {:.2}".format(avgWordLength))
        print()

        # increment line number counter after end of each loop
        # this can tell us of many lines are there in a file
        lineNum2 += 1



