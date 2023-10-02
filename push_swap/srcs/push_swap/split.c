//See notes below, why we had to create a "mutable" ft_split, rather than using our libft version

#include "../../inc/push_swap.h"

static int	count_words(char *s, char c) //Define a function that returns the substrings count in a string seperated by a delimiter
{
	int		count; //To store the substring count
	bool	inside_word; //A flag to indicate whether we are inside a substring or a delimeter

	count = 0;
	while (*s) //Loop until the end of the string is reached
	{
		inside_word = false; //Set the bool to false to start the loop
		while (*s == c) //While the current character is the delimeter
			++s; //Move to the next character
		while (*s != c && *s) //While the current character is not a deilimeter and the end of the string is not reached, 
		{
			if (!inside_word) //If we are not currently inside the substring
			{
				++count; //Increment the count as we are about to move inside a substring
				inside_word = true; //Set the bool to true, indicating we've found a substring
			}
			++s; //Move to the next character of the string
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c) //Define a function that returns the new substring found within a string
{
	static int	cursor = 0; //To keep track of the position within the string `s` across multiple function calls, needed to continue processing the string from where we left off in previous calls, essential for tokenizing a string
	char		*next_word; //To store a pointer of the new substring
	int			len; //To store the length of the substring being extracted
	int			i; //Used for indexing characters in the new substring

	len = 0;
	i = 0;
	while (s[cursor] == c) //Skip past any consecutive delimiter characters at the current position in the string
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len]) //Calculate the length of the substring by counting characters until either a delimiter or the end of the string is encountered
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1); //Allocate memory for new substring based on its length plus one byte for the null terminator
	if (!next_word) //Check for unsuccessful memory allocation
		return (NULL);
	while ((s[cursor] != c) && s[cursor]) //Loop until a delimeter is encountered and the end of the string is reached
		next_word[i++] = s[cursor++]; //Copy each character from the string to the new substring and increment `i` and `cursor` after each character
	next_word[i] = '\0'; //Properly null terminate the newly created substring
	return (next_word);
}

char **split(char *s, char c) //Define a function that returns the substrings in a string seperated by a delimiter
{
	int		words_count; //Used to keep track of the number of substrings in the string
	char	**result_array; //To store a pointer to pointers, the array of all the substrings
	int		i; //Used to iterate through the array

	i = 0;
	words_count = count_words(s, c);
	if (!words_count) //Check for `0` words
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2)); //Allocate memory for the result_array based on the number of words (words_count) plus two additional slots to account for the null terminator at the end of the last string, and to null terminate the entire array
	if (!result_array) //Check for unsuccessful memory allocation
		return (NULL);
	while (words_count-- >= 0) //Iterates through the words to be split all words have been processed
	{
		if (i == 0) //Check if the first character of the input string is the delimiter
		{
			result_array[i] = malloc(sizeof(char)); //Allocate memory for an empty string (a single null terminator)
			if (!result_array[i]) ////Check for unsuccessful memory allocation
				return (NULL);
			result_array[i++][0] = '\0'; //Include in the result array as distinct elements
			continue ;
		}
		result_array[i++] = get_next_word(s, c); //If the first character of the string is not a delimeter, extract the substring and copy it into the result array
	}
	result_array[i] = NULL; //Properly null terminate the array
	return (result_array);
}


/*
 Both functions, `ft_split()` `split()` split a string into an array of substrings using a specified delimiter character. 
 However, the differences are:

 #1	Function Signature:
	- `ft_split` takes a constant string (const char *s) as input.
	- `split` takes a mutable string (char *s) as input.

#2	Input Mutability:
	- `ft_split` takes a constant string (const char *s) as input, indicating that it does not modify the input string.
	- `split` takes a mutable string (char *s) as input, indicating it may modify the input string during tokenization.
	- Mutable strings can be modified in-place, meaning you can change the characters within the string without creating 
	  a new string object.
	- Immutable strings, on the other hand, cannot be modified once they are created. Any operation that appears to modify 
	  an immutable string actually creates a new string with the desired changes.

#TOKENIZATION:
	- Tokenization is the process of breaking down a text or a sequence of characters into smaller units called tokens. 
	- Tokens are typically words, phrases, symbols, or other meaningful elements within the text.
	- In the case of push_swap,  Word tokenization is the process of splitting text into words or word-like units. 
	  It involves identifying word boundaries and separating words from each other. For example, in the sentence "Tokenization 
	  is important," the words "Tokenization," "is," and "important" are individual tokens.
	- Purpose: 
	  Tokenization is a preprocessing step that simplifies text analysis tasks. 
	  It allows text to be represented in a form that can be easily processed by algorithms and models. 

#3	Memory Management:
	- `ft_split` allocates memory for the resulting string array and the individual substrings within the function, 
	  and frees memory
	- `split` also allocates memory for the resulting string array and substrings but relies on the caller to free the memory.

#4	Static Variable Usage:
	- `ft_split` does not use static variables in its implementation.
	- `split` uses a static variable cursor to keep track of the position in the input string for tokenization.

#5	Error Handling:
	- `ft_split` returns NULL if memory allocation fails during the tokenization process.
	- `split` exits the program with an error code if the number of words is zero.

In summary, both functions perform string tokenization, but they have differences in terms of input mutability, memory 
management, and error handling. 
*/