#include "push_swap.h"
#include <stddef.h>

/*
 * Args at the command line are
 * spaced separated strings
*/
static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

/*
 * I exploit static variables
 * which are basically 
 * "Global private variables"
 * i can access it only via the get_next_word function
*/
static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0; //Used to move the "cursor" inside the string. Once a substring is found and copied, the cursor will get picked up where it last left off to find the next substring
	char		*next_str;
	int			len; //Length of current substring
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++]; //Copy the substring
	next_str[i] = '\0'; //Null terminate the substring
	return (next_str);
}

/*
 * I recreate an argv in the HEAP
 *
 * +2 because i want to allocate space
 * for the "\0" Placeholder and the final NULL
 *
 * vector_strings-->[p0]-> "\0" Placeholder to mimic argv
 * 				 |->[p1]->"Hello"
 * 				 |->[p2]->"how"
 * 				 |->[p3]->"Are"
 * 				 |->[..]->"..""
 * 				 |->[NULL]
*/
char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings; //A pointer to an array of pointers
	int		i; //Used to iterate through the string array

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2)); //`+ 2` because we mimick the argv array. Argv[0] is the `./program name. We put a placeholder inside argv[0] so it is easier to "init" the stack. So, `2` because the first element is the placeholder and the last element is the '\0`
	if (NULL == vector_strings)
		return (NULL);
	while (words_number-- >= 0) 
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ; //Go back to beginning of the while loop
		}
		vector_strings[i++] = get_next_word(str, separator); //Fill the pointer array with the copied substrings
	}
	vector_strings[i] = NULL; //Null terminate the pointer array
	return (vector_strings);
}