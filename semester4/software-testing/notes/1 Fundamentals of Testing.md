-  Software testing - making sure the code is robust, checking its boundaries
-  Testing vs debugging?
-  Why do we need to test the code?
-  Testing during each phase of the software development lifecycle: Requirements, Design, Coding, Testing, Fixing, Shipping, Maintaining
-  It is important to test edge cases
-  It is cheaper to do requirement testing because you haven't actually coded anything yet
-  Testing is very expensive, but inadequate testing causes an even bigger cost (potentially even harm to people)
-  It is important not to test too much though

## Defects

-  Some issues are the result of defects - triage is required
-  Causes of software defects - human, requirements or coding errors
-  Defects can also be found in documents, not only code
-  some defects cause systems to fail - catastrophic
-  There is a variety of defects that have different impacts on the code, not all defects will completely break the systems
-  also called bug or a fault

## Failure

-  A failure happens when there is no catastrophic defect and the system fails, but the system doesn't do what user expects it to do
-  too hard to use or too slow - example of failures
-  system does a wrong thing - also a failure
-  also called problem, incident, issue

**Errors** - a human action producing an incorrect result
 -  Errors are bound to happen in solution of complex problems, they are not unavoidable
 -  Software will never be perfect

## Software requirements

-  laws, industry regulations and standards, customer expectations
-  we need to provide evidence that we are complying to these, even after we change the software

## Fundamentals continued

- **Testing measures quality** of a product and indirectly improve it.
- **How much testing is enough?** - This is one of the most complicated things to figure out when we are planning the testing phases.
- Too much testing is expensive, too little testing impacts the quality of the product.
- We can use **objective coverage measures**: standards may impose a level of testing and test design techniques give an objective target
- Time is an important limiting factor, we need to do all these tests before the deadline, so we need to focus on the most important test - we cannot test everything

## Bugs

**How to find bugs?**

-  Defects tend to cluster, once you find one, there is a likely possibility that there are similar ones
-  We know that some parts of the software are reliable
-  We need to **fish**
-  Size of the net - size of the test
-  Density of the mesh - test depth or thoroughness
-  Large nets and mesh give overall confidence
-  Small nets, fine mesh to find bugs in a particular area we can expect bugs to appear
-  Use rigorous tests in the riskiest bits of code
-  Fine mesh for the business critical parts of the system as well
-  If we don't find bugs in business critical parts of the system that are not exposed to users and they are low impact, we don't have to worry about them as much - sensible approach to testing

## Testing vs Debugging

**Important**

**Testing**
-  done by testers
-  systematic exploration of a system with the main aim to find and report defects
-  rigorous examination of a system
-  shows failures caused by defects

**Debugging**
-  done by developers
-  done before testing
-  process of identifying the cause of defects in code and correcting them
-  making sure that the system gets to the testing stage

## More on testing

**Possible question in the exam: What is a test case?**
-  a test is a controlled exercise
-  a controlled exercise contains the object under test (software), the environment of the software in the production, inputs and expected outputs we get from requirements or previous tests
-  objectives: finding defects, gaining confidence about the quality and providing information and improving the quality
-  **STATIC TESTING** - testing without executing the program, we can do software inspections like reading documentation and/or code to see if we can spot defects
-  **DYNAMIC TESTING** - testing with real input and expecting a certain output, includes execution of the code
-  System testing is part of dynamic testing but it branches into non-function and functional requirements
-  User acceptance testing is also included into the dynamic testing

-  Early test case preparation is required before the official testing in the waterfall model which is the most used models
## Types of testing

 -  Regression/Maintenance testing - testing that no new errors occurred during development phase or after changing a piece of the code (sometimes you break something after fixing something)
 -  Operational testing - assessing system characteristics such as reliability or availability
 -  Unit testing - assessing quality of individual units
 -  Integration testing - assessing if individual components work together
 -  System testing - assessing if the system delivers what it was supposed to
 -  Acceptance testing - assessing whether the system fulfils the user expectations/requirements


