### Readme for large scale matrix multiplication


### Steps to run the code

Run ```./script.sh``` in the terminal from the project folder to complie and run the single and multiple thread program.

### File description
prog1.c --> This is the code to compute matrix multiplication using single thread.

prog2.c --> This is the code to compute matrix multiplication using 25 threads

generate_data.c --> This file will generate two matrices with random numbers between (1-2000) and will serve as the input for prog1.c and prog2.c codes

script.sh --> This file is used to compile and execute the two programs in prog1.c and prog2.c and will print the time taken by each.
`
### Result

Will print the start time and end time of the each program and write the program output to singleThreadResult and multipleThreadResult file respectively.

As per the result singleThread program is taking 20 secs for multiplying the matrix of size 500*500. Hence we can see that the performance is optimised by 20 times in case of multi threases matrix multiplication.

For multi Thread program is taking 1 sec for multiplying the matrix of size 500*500.