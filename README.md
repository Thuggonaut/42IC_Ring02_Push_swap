# 🔃↔️ Push_swap

Check out my [tutorial here](https://youtu.be/wRvipSG4Mmk)

### Contributors:
- Leaks fix by [elpah](https://github.com/elpah)
  
## 🔷 The Mandatory part:
1. We have at our disposal, two stacks named `a` and `b`.
2. Create a program that takes as parameters, a random set of numbers (negative or positive), without duplicates. Our program has to handle both types of inputs: as a variable number of command line arguments; a string, i.e. "numbers between quotation marks, seperated by a space".
3. Implement an algorithm, that sorts in ascending order, the input of random numbers.
4. Our algorithm will consist of swap, rotate, reverse rotate and push operations. 
5. After taking in an input of numbers, and passing them through our sorting algorithms, our program will output the list of operations (instructions). 


## 🔷 Write pseudo code
```
//Declare pointers to two data structures/linked lists, one for stack `a` and another for `b`
	//Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks

//Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
	//If input errors, return error

//Handle both cases of input, whether a variable number of command line arguments, or as a string
	//If the input of numbers is as a string, call split() to split the substrings

//Initialize stack `a` by appending each input number as a node to stack `a`
	//Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or `-` `+` signs
		//If errors found, free stack `a` and return error
	//Check for each input, if it is a long integer
		//If the input is a string, convert it to a long integer 
	//Append the nodes to stack `a`

//Check if stack `a` is sorted
	//If not sorted, implement our sorting algorithm 
		//Check for 2 numbers
			//If so, simply swap the numbers
		//Check for 3 numbers
			//If so, implement our simple `sort three` algorithim
		//Check if the stack has more than 3 numbers
			//If so, implent our Turk Algorithm

//Clean up the stack
```

## 🔷 Using a push_swap visualizer
1. I can't recommend this enough. 
2. It was very useful for me to see what my code was doing during its implementation, and help with a lot of my debugging. 
3. The one I used can be found here https://github.com/o-reo/push_swap_visualizer

Make sure you follow this sequence:
1. git clone the repository inside your main push_swap directory, where your push_swap executable will be. 
2. Install the required packages as stated on the README.md (do `sudo apt update` first to make sure you have the latest information about available packages)
3. Then, to install a package, do e.g. `sudo apt install cmake`
4. cd inside `/push_swap_visualizer` 
5. `mkdir build`
6. cd into `build` then:
	- `cmake ..`
	- `make`
	- Like myself, you might run into some build errors in your terminal. For example, you're missing a OpenGL package. I just chat gpt'd all the error messages and followed the installation commands 😅
7. After a sucessfull build of `cmake ..` and `make`:
	- run `./bin/visualizer` and a window of the program should apear. 
	- change the "push_swap file path" to `../../push_swap`


## 🔷 Using the checker provided by 42
1. Download the correct file from the subject page, e.g. for Mac, or Linux, inside the same directory as your executable.
2. Running the checker likely won't work, as it won't have the executable permission. Check by typing in the terminal `ls -l`
3. To give it permission, do `chmod +x <filename>`
4. Test your executable against everything we need our push_swap to do:
	- e.g. the correct outputs for all error types
	- e.g. run `ARG="4 10 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG `
	- To see how many instructions, run `ARG="4 10 1 3 2"; ./push_swap $ARG | wc -l`
	- For our program to pass the evaluation, it'll have to return `n` size of instructions for sorting `x` number of values:
		- If x = 3 then n <= 3
		- If x = 5 then n <= 12
		- If x = 100 then n < 1500
		- If x = 500 then n < 11500
		- Note: the lesser instructions our algorithm returns, the more evaluation points we will get.


### What is an algorithm?
- A set of intructions to solve a problem.


### What is the concept of complexity?
- Algorithm analysis: 
	Analyzing the algorithm's step by step instructions to understand their performance.
- Algorithm efficiency:
	Looking at how quickly an algorithm solves a problem, and the resources it uses up, like time and memory.
- Asymptotic Notation: 
	Using mathematical notations like Big O, Omega and Theta to look at the algorithm's running time, as the problem becomes larger.
- Time complexity:
	Using Big O, looking at the best, worst, and average case for an algorithm to complete.
- Space complexity:
	Using Big 0, looking at the amount of memory space an algorithm uses.
