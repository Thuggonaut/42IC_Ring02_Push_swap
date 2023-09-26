//See notes below, why we had to create a "mutable" ft_split, rather than using our libft version

#include "../../inc/push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0; //To keep track of the position within the string `s` across multiple function calls, needed to continue processing the string from where we left off in previous calls, essential for tokenizing a string
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char **split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
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