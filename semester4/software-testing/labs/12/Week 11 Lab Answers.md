Task 1.
Data Flow Analysis is useful because it shows us how data is used on the different paths through the code. This helps us spot inconsistencies which would not always cause an error during technical testing, but are important to take care of if we want the best solution for the library software. Data Flow analysis can identify three anomalies: ur-anomaly, du-anomaly and dd-anomaly. The names of these anomalies are based on three states we can have our variables in
u = undefined
r = referenced
d = defined
ur-anomaly appears when the variable is undefined, meaning it was given no value, but it is then read, meaning we tried to use it - this would definitely give us an error in the technical testing part of the project because we are not working with any value.
du-anomaly appears when we give the variable a value, we define it, but we never use it. This might cause some compilation errors in the future, depending on the compiler, but it is a type of anomaly that makes the variable redundant to our code.
dd-anomaly appears when we assign a value to a variable, and then overwrite that value with another one before ever using the first one. This could also cause errors, and it makes the first value assignment redundant as well.

Task 2.
The diagram would involve a decision if node (if the person is 15) that diverges into two nodes, the left one represents then statement (if the person is 15, then do something), and the other one represents the else statement (else do something else), after that they merge at a junction node to continue the code.
In the context of path testing, this diagram is useful to confirm we have tested all feasible paths at least once. So in this case, the decision is "Is the user 15 years old" - we would go through the true path - "Yes, this user is 15 years old" and then the false path - "No, this user is not 15 years old". These paths will be tested on whether they execute the action that was supposed to happen after a decision is made based on the input data. After that we can confirm we covered all paths related to this piece of code.
Manager explanation: This approach is very useful in complex code situations in which we have to make sure we cover all paths at least once, but it is difficult to keep track, or spot paths we have not covered yet.
Code example:
```python
if age >= 8 and age <= 18:
	if age > 8 and age < 10
		print("Small student")
	elif age > 10 and age < 12
		print("Preteen")
	elif age > 12 and age < 16
		print("Early teens")
	else:
		if age 18:
			print("Adult")
		else:
			print("Late teens")
else:
	print("Too old or too young to be a student")
```
In this code example there are a lot of if, else if and else statements, some of them nested as well, which could make it difficult for us to cover all of the paths without any planning or tracking that we would get otherwise by drawing out the logic with the help of a control flow graph. This way we can draw all of the nodes and how they connect, and then choose the path we want to test. We design test cases that follow that path to confirm that everything works well on this path before moving on to the next one. After some time we will have a definite confirmation that we have checked all of the cases of where the program could diverge, and we covered any type of student that might use the library application.

Task 3.
Test Driven Development approach is a type of programming approach in which the program is based on the pre-written tests we test it against. The tests are derived from baseline documents which include requirements we were given from stakeholders, and programming starts only after the tests are written. Programmers are not allowed to write any production code unless it is to make a failing unit test pass. This makes testing the heart of the program development process, and tests are usually made using PyUnit. The benefits of this approach are that requirements are discussed and refined early in the production process, so there are less risks of our program not passing user acceptance tests, which also reduces the project cost substantially, as big changes cost a lot of money to fix the later we are in the project. Since tests are written and tested before program is developed, everyone has the same understanding of what the program should do and how it should behave, and the developers just need to find solutions to pass unit tests.

Task 5.
To write unit tests, first I would inspect a requirement or a feature that is to be implemented as one or more units, and then based on this, I would write the unit test source code. I would compile this source code into an executable software. I would execute this software to check if it works before I can use it on the project unit code. I would write an example of a positive and a negative unit test to test both true and false path. An example of a positive unit test in a case where we want to check whether the user is 15 and we want to test the true path, I would use something like `asssertEqual(output_message, "The user is under 15")` - This would check whether the program behaves accordingly and prints out an output message that is the same as the expected message in the second argument. An example of a negative test in the same case would be `assertEqual(output_message, "The user is over 15")`.
The location of unit tests are debatable as people are split between advocating for unit tests to be close to source code in a subdirectory, to be higher in the hierarchy of directories away from the code, or to be passed to a production system. I would keep the unit tests higher in the hierarchy just for cleaner organisation purposes.
If the project was done in Python, I think that PyUnit would be a suitable option to use for writing these tests, and it would still be suitable in regression testing as automated tests confirm we did not break any features by adding new ones, as well as integration and system testing as a whole, where we can confirm that units still pass all of the tests even when they are working with other units.
It would be impossible to write test cases for ALL of the code that will be written for the system because full path coverage is too long and exhaustive for us to test everything, but I would write tests for most functionally important parts of the code, covering most of the main functionality.

Task 6.
Assert statements we have covered are `assertEqual(a, b)`, `assertNotEqual(a, b)`, `assertTrue(x)`, `assertFalse(x)`, `assertAlmostEqual(a, b)`, `assertAlmostNotEqual(a, b)`

`assertEqual(a, b)` - used to compare the actual output a with the expected output b to determine whether they are the same. If they are the same, the case passes the unit test.
Example: A test case that checks if a program adding two numbers 2 and 3 together outputs 5 (the expected output)
```python
assertEqual(add(2, 3), 5)
```

`assertNotEqual(a, b)` - also used to compare the actual output a with the expected output b, but this time we determine whether they are different from each other. This statement is usually used for negative unit test where we expect our program to give us the right result, even when we expect a wrong result
Example: Checking if adding two numbers 2 and 3 together outputs 7 (the test passes if these output are different)
```python
assertNotEqual(add(2, 3), 7)
```

`assertTrue(x)` - the test passes if the output returned is true in the case where we test the code that is returning a boolean value
Example: The program returns true if the integer is a prime
```python
assertTrue(is_prime(3))
```

`assertFalse(x)` - the test passes if the output returned is false in the case where we test the code that is returning a boolean value
Example: The program returns true if the integer is a prime, false if it is not
```python
assertFalse(is_prime(4))
```

`assertAlmostEqual(a, b)` - used to check whether two given values are almost equal or not in the context of desired precision. It computes the difference between two values and then rounds to the given number to decimal places (default 7). Lastly it compares the rounded value to zero. This statement allows us to give some leniency to data when we are testing it as we know the program would work regardless if the data does not fully equal the desired test output. It is useful when calculating volumes of items, or any other numerical data.
Example: 
```python
assertAlmostEqual(0.1+0.1+0.1, 0.3)
```

`assertAlmostNotEqual(a, b)` - used to check whether two given values are almost not equal in the context of desired precision. It works based on the same principle as the previous assert statement.
Example:
```python
assertAlmostNotEqual(0.1+0.1+0.1, 0.4)
```

Task 7.
The difference between debugging and testing is that debugging is done by developers during the development stage, and testing is done by testers during the testing stage of the project. It is important to make this distinction because referring to debugging can often times get misconstrued as testing, but debugging uses different tools and is done in a different environment, so we need to have clarity of the two definitions when we refer to both.

5 IDLE debugger options are Go, Step, Out, Over and Quit

Go is used to execute the entire program or the rest of the program until the end or a specified breakpoint we set ourselves. It can be useful for us to observe the behaviour of the code up to a certain point that we have determined is a critical section which might contain the bug we are looking for, and that is where we would set the breakpoint. This would be easier than clicking the Step button over and over again until we reach a certain point in the code within the debugger. For example, while developing the library app, there is a bug that does not count the appropriate number of books available. We open the appropriate file in the debugger and set a breakpoint by the section of the code we expect would cause problems. We press go from the first line and watch the logic progress up until that point. Now we know the state of our program before we enter the critical section.

Step allows us to step through our code one line at a time, and once it encounters functions, the debugger steps into the function as well. We can watch what happens in the debugger window - how the variables change and update. The output is displayed in the interactive window one piece at a time. For my example, we would be able to enter a critical section after a breakpoint, and carefully inspect whether the total books counter is going up when the program encounters an available book. This way we would be able to determine if the function is working correctly, and if the problem lies within it. If not, we just set a new breakpoint and repeat the process with Go and Step.

Out allows us to step over lines of code of the function or a loop we are currently residing in when the button is clicked, after that it pauses. We can click Out in the case we do not spot any bugs in the current function and want to move on.

Over allows us to step one line at a time again, only this time we do not go into the function when we come across it's call in the function. This is useful when we want to see the functionality of the function, but we do not want to go over the function code itself. For example, we know that the counter function of books is now correct and we want to check other logic which calls upon that function at some point, we can click Over to skip having to go through that whole function knowing it is correct.

Quit immediately terminates the program. After we find the bug and now we are ready to fix it, we can quit the execution of the program in the debugger by clicking Quit and fix the bug.