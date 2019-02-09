## Project Description

This code is a simple file analyzer using C++.
The code uses linked-lists data structure.  
The code is able to do the following tasks efficitevly:

* Read the input file word by word. Separators such as **, ; : & [] ()** are discarded
* Each word is then inserted into the in-order list, along with the line number in which it exists in.
* The First line in the fille is line #1. Note: book, Book and BOOK are the same word (Case insensitive).
* The [following actions]( will then be performed by the program. The file containing the commands, will have a set of commands. Each command is written in a separate line. The programs reads the commands line-by-line and executes them.


> **wordCount:** Prints the number of words in the file.

> **distWords:** Prints the number of distinct words in the file.

> **countWord myword:** prints the number of myword ocurrence in the file.

> **searh mystr:** Prints all words that contain the string **mystr** along with the line numbers in which they exist.

> **starting mysub:** Prints all words that start with **mysub** followed by their number of ocurrences.

> **containing mystr:** Prints all words that contain the string **mystr** followed by their number of ocurrences.

> **frequentWord:** Prints the word(s) that had ocurred the most in the input file excluding common language constructors such as **a, and, or, etc**. If two or more words have the same number of repetitions, the code should print all of them sorting them in an alphabetial order.

## How to use 

Just navigate to the bin folder where you can see the compiled file, open you terminal and run the following command:
> **a2.exe Filename CommandsFile**
