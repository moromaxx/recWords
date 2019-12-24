# recWords
Checking all possible variations of "words" in given matrix recursively. I've solving the following task:

You’re given the "matrix" (array of arrays) of chars:

    T	R	A	C
    K	A	T	E
    E	M	S	E
    N	P	L	L

You can build a words from this table in the following way:
You’re allowed to start at any cell, and then you may “walk” right, left, up or down. For example, there are words “CAT” and “CATS” and they’re different. 
The only rule is that you allowed to “walk” without limit but don’t to “cross the line”.
You’re also given a function:
bool isWord(char s[])
The function gets pointer on symbols sequence and returns if the current sequence is word or not. 


My function should walk over all the matrix and all the possible sequences of words and prints all the words in the matrix (by checking if the sequence is word using procedure isWord) and returns the number of words that were found.
In addition, the recursive calls may produce a lot of calls on the stack. So I've improved my procedure by defining the variables 'i' and 'j' that help me to "walk" over the matrix in the code segment (global memory) so they don't hold the memory in the stack.
