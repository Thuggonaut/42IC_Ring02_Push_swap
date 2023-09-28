

![unknown](https://github.com/Thuggonaut/42IC_Ring02_Push_swap/assets/115153368/e5840f2f-2d46-4281-88fd-c6f30b1804f5)

What is an algorithm?
	- A set of intructions to solve a problem.

What is the concept of complexity?
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

# Video: Push_swap

Purpose of this video is to help me practice defend and explain the problem solving process, like talking to a rubber ducky.

The Mandatory part.

# The project objective:
1. We have at our disposal, two stacks named `a` and `b` (that we need to code). [Illustrate] [the stacks] 
2. Create a program that takes as parameters, a random set of numbers (negative or positive), without duplicates. Our program has to handle both types of inputs: as a variable number of command line arguments; a string, i.e. "numbers between quotation marks, seperated by a space". [Illustrate] [the command line]
3. Implement an algorithm, that sorts in ascending order, the input of random numbers. [Illustrate] [acending order] 
4. Our algorithm will consist of swap, rotate, reverse rotate and push operations. 
5. After taking in an input of numbers, and passing them through our sorting algorithms, our program will output the list of operations (instructions). [Illustrate] [the command line]
6. For our program to pass the evaluation, it'll have to return `n` size of instructions for sorting `x` number of values:
	- If x = 3 then n <= 3
	- If x = 5 then n <= 12
	- If x = 100 then n < 1500
	- If x = 500 then n < 11500
	- Note: the lesser instructions our algorithm returns, the more evaluation points we will get.

# To tackle this project, we will:
1. Learn what stacks are, and how we create them.
2. Learn, and write code that can execute: the swap, rotate, reverse rotate and push operations.
3. Choose a sort algorithm.
4. Write pseudo code that meets the project objectives.
5. Implement our algorithm in code.
6. Use a push_swap visualizer during code implementation for debugging.
7. Test our algorithm against the evaluation check list and checker provided by 42.

# What is a stack?
1. A stack of objects piled on top of each other. [Illustrate] [the stacks]
2. A stack has a bottom object, and a top object. [Illustrate]
3. Credit to Oceano https://www.youtube.com/watch?v=OaG81sDEpVk video on push_swap where I learnt more about stacks and linked lists that helped me a great deal on starting this project. You'll find much of my work in this video were made possible from learning from him. 
4. Back to our stacks. We create our stacks with linked lists. If you completed the libft bonus you'd be familiar with linked lists. 

# What is a linked list?
1. An organised data structure that contains nodes. [Illustrate] [the nodes]
2. The nodes are data elements. Consider each node like a box, that stores data inside of it, for example, a number. [Illustrate] [the number data]
3. What makes this data structure a "linked list" is that they are connected in sequence, like a chain. [Illustrate] [chain like lines between the nodes]
4. "In sequence means", the head node, is connected to the next node, which is connected to the next, and the next, and which is connected to the tail node. We will interchangebly use top with head, and bottom with tail. [Illustrate] [head node, and the "next" arrows. The next arrows over the top of the "chain" lines]. 
5. What we're looking at, is a singly linked lists. The chain from top to bottom, is unidirectional. 
6. For this project, we will use a doubly linked list, which means the nodes are linked bidirectionally. Each node has a "reference" to a "next" node, as we've seen so far, and a "reference" to a "previous" node. [Illustrate] [the arrows to previous]
7. A circular linked list can be unidirectional or bidirectional, but that the tail node, is linked to the head node (we will not be using this). [Illustrate] [arrows pointing to head, then remove before next point]

# What is a node?
1. Recall, a node is like a box containing data, and it can contain many different types of data you want. 
2. For our project, our nodes will contain 2 main things:
	- The data: a number and its position or index in the stack. There are a few more data types, but we will get back to this later. [Illustrate] [the different data so far]
	- Reference pointers: a pointer to the next node, a pointer to the previous node. There is a third pointer, but we will get back to this, when it will make sense. [Illustrate] [the pointers, relating to the "next" and "previous" references] 

# Now, we have our stack
[Illustrate] [the complete stack picture]

# The swap, rotate, reverse rotate and push operations
1. sa, sb , ss operations. [Illustrate]
2. ra, rb, rr operations. [Illustrate]
3. rra, rrb, rrr operations. [Illustrate]
4. pa, pb operations. [Illustrate]

# Choosing our sort algorithm
1. I looked at several different algorithms and in the end chose what felt the simplest and most intuitive - The Turk Algorithm, coined by A. Yigit Ogun. You can look at why he called it that, in his article here https://medium.com/@ayogun/push-swap-c1f5d2d41e97 
2. This Turk algorithim returns me the least amount of instructions on average, and passed my project with 100%. 

# The Turk Algorithm
1. Push the nodes from stack `a` to stack `b` until there are three left in stack `a`. 
2. However, each time an `a` node is pushed to stack `b`, it sorts the nodes in stack `b` at the same time, and in descending order. [Illustrate] [the sort, without details]
3. Let's look at what happened. We have a stack `a` with more than 3 nodes. 
	- We push the first 2 `a` nodes without checking anything. [Illustrate]
	- We now have in stack `b`, a MAX number so far, and a MIN number so far. This is important to push the rest of our `a` nodes [Illustrate] [which is MAX, which is MIN]
	- Note: Say, if we had a stack of 4 nodes, we would only push the first `a` node to stack `b`, because after this, our "3 left in `a`" condition is met. 
	# Target nodes
	- Every `a` node, needs a `target node` in stack `b`. A target node has a value smaller than `a`, but the "closest smaller" value to `a`. [explain the concept of target nodes, and the concept of "closest smaller" via example nodes shown] [Illustrate] [arrows pointing to target nodes]
	- Recall, each time we push `a` nodes to the stack `b`, we are sorting stack `b` at the same time, in descending order. Hence, each time we push `a` node on top of `b` node, we need to make sure that `a` has a larger value than `b`.
	- Note: if `a` node can't find a target node that contains a "closest smaller" value, its target node will then be, the node with the MAX value - the largest number. You will soon see why this logic makes sense, if you haven't pictured it already. 
	# Cost analysis
	- Every `a` node is now assigned, its target node. [Illustrate] [ensure all arrows to targets are present]
	- The next step, and after each push from here on, until we have only 3 nodes left in stack `a`, we need to calculate, which `a` node we should push to stack `b`.
	- In other words, we need to find which `a` node is the cheapest to push to `b`. 
	- To find the cheapeast `a` node to push, we sum: 
		the amount of instructions for bringing `a` node to the top
	+	the amount of instructions for bringing `a`'s target node to the top
		--------------------------------------------------------------------
	=	the `a` node's push cost [Illustrate] [the formula]
	- We calculate the push cost for every `a` node, do the instructions needed, then finally, push the cheapest node. [Illustrate]
	- After each push, we calculate again for each `a` node: its target node; then, the cheapest `a` node to push. 
	- As long as our stack `a` has more than 3 nodes, we push the `a` nodes to stack `b` until there are 3 nodes left in stack `a`. [Illustrate] [the calculations and push until 3 nodes left in `a`]
	# Sort Three
	- We now have 3 nodes left in stack `a`
	- We will implement an algorithm that sorts a stack of 3 nodes, in ascending order. 
	- Sorting three nodes will be simple. 
	- The biggest is always at the bottom, and then we swap the first two nodes if needed. [Illustrate]
	# Push everything back to stack `a` 
	- Now, we push every `b` node, one by one, from the top of stack `b`, until `b` is empty.
	- The only requirement for this step, is that before we push `b` node to stack `a`, we need to make sure it'll be pushed on top of the correct `a` node.
	- Recall, our push_swap needs to sort stack `a` in ascending order. This means, for every `b` node, this time it needs a target node in stack `a`.
	- `b`'s target node will be the node that has the "closest bigger" value in stack `a`. 
	- If a `b` node cannot find its "closest bigger" value, say, because it already holds the largest number, then, you guessed it, its target node will be the smallest number in stack `a`. 
	- Let's have a look at the first `b` node and set its target nodes. [Illustrate] [with arrow]
	- Now we either rotate, or reverse rotate `a` node to make sure it's on top, ready for `b`. 
	- Imagine, a median line in stack `a`. Whether we rotate, or reverse rotate `a` node, it depends whether `a` node is above, or below the median line. If above, it takes less instructions if we do rotate, and if below, it takes less instructions to do reverse rotate, to bring our target node to the top. [Illustrate] [median line]
	- [Complete the moves for `a` node to be on top, then push] [Illustrate]
	- [Complete the rest until `b` is empty] [Illustrate]
	# Min on top
	- Finally, we move the nodes in stack `a` to ensure the smallest number is on top, and the biggest on the bottom of the stack.
	- We look at where the smallest number is in the stack, either above, or below the median line, and then rotate or reverse rotate accordingly. [Illustrate] [the median, and complete sorting]
4. There we have it, the Turk algorithm. 
	- Summary:
	- If a stack has more than three nodes
	- Push `a` node to stack `b` twice
	- Until 3 left in stack `a`, push the rest of `a` nodes to `b`, stimultaenously sorting stack `b` in descending order
	- Sort three in stack `a`
	- Push all `b` nodes back into stack `a` and ensure `a` is in the right position before each push. 
	- Finally, move the smallest node on top. [Illustrate] [the who sort again from beginning]

# Write pseudo code

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


# Coding push_swap [Illustrate] [line by line]
At this point, we have a basic understanding of:
1. What stacks are, and that they can be created with linked lists
2. What the commands are: swap, rotate, reverse rotarte, and push
3. How the Turk Algorithm works
4. What functions we roughly need, thanks to our pseudo code

Let's write our codes: [Illustrate] [each writing]

# The push_swap.h header file
- [explain the headers needed: stdbool to use boolean flags, for the purpose of printing the list of commands]
- [explain the limits header, where the integer MIN and MAX macros are defined]
- [explain I used own libft and printf here, otherwise make sure you include your neccessary headers here]
- [explain in the header file is where we will define our data structure, then walk through]
- We will define our typedef data structure, and call it `s_stack_node`. This will be our "box" for each node.
- Recall, earlier, we said, each box, which is a node, contains the data: a value (number); and it's index. 
	- We also said there would be a few more, which you will recall, they are things we already talked about: push_cost, above_median, and cheapest.
- Recall also earlier, we said each node contains reference pointers: to the next node; and to the previous node, as we are using a doubly linked list.
	- We also said, that there will be a third reference pointer. This will be the target_node, a term we've also already talked about. 
- That is our struct defined.
- Finally, we will name this new struct we created, `t_stack_node` which we can call in our functions from here on out. 
	- The way this works is:
		- Earlier, we called our struct `s_stack_node` - this is like, the official name of our struct
		- Now that we have it defined, we give it a new name, `t_stack_node` - this is like, the shortened name for our type, so we don't have to call `struct s_stack_node` each time we want to use this newly created struct type.

# Feel free to look at my codes on github for the following functions, though I reccomend you have a go at writing it own your own first:
- Functions to handle input errors and free stacks when needed
- Functions that do swap, rotate, reverse rotate, and push (which uses the linked lists)
- Utils functions that finds the length of a stack, finds the last node, finds the min(smallest) and max(biggest) nodes in a stack 
- [Illustrate] [summary of functions]

# main.c [write]

# split.c [show]

# stack_init.c 
- init_stack_a() [write]
- ft_atol() [show]
- append_node() [write]

# stack_sorted() [write]

# sort_three() [write]

# sort_stacks() [write]
- init_nodes_a() [write]
	- current_index() [show]
	- set_target_a() [write]
	- cost_analysis_a() [write]
	- set_cheapest() [show]
- move_a_to_b() [write]
	- get_cheapest() [show]
	- rotate_both() [write]
	- prep_for_push() [show]
- init_nodes_b() [write]
	- set_target_b() [show] [explain, the same as set_target_a, but instead of finding the closest smallest, we're finding the closest biggest]
- move_b_to_a() [show]
- min_on_top() [write]


# Using a push_swap visualizer
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
	- Like myself, you might run into some build errors in your terminal. For example, you're missing a OpenGL package. I just chat gpt'd all the error messages and followed the installation commands :smiley
7. After a sucessfull build of `cmake ..` and `make`:
	- run `./bin/visualizer` and a window of the program should apear. 
	- change the "push_swap file path" to ``../../push_swap`

# Using the checker provided by 42
1. Download the correct file from the subject page, e.g. for Mac, or Linux, inside the same directory as your executable.
2. Running the checker likely won't work, as it won't have the executable permission. Check by typing in the terminal `ls -l`
3. To give it permission, do `chmod +x <filename>`
4. Test your executable against everything we need our push_swap to do:
	- e.g. the correct outputs for all error types
	- e.g. run `ARG='4 10 1 3 2'; ./push_swap $ARG | ./checker_Mac $ARG `
	- To see how many instructions, run `ARG='4 10 1 3 2'; ./push_swap $ARG | wc -l`
	- Recall, for our program to pass the evaluation, it'll have to return `n` size of instructions for sorting `x` number of values:
		- If x = 3 then n <= 3
		- If x = 5 then n <= 12
		- If x = 100 then n < 1500
		- If x = 500 then n < 11500
		- Note: the lesser instructions our algorithm returns, the more evaluation points we will get.
