# Expected Results

-  we are referring to some kind of baseline document (requirements, specs etc.)
-  specifications, requirements etc. define what the software is required to do
-  testers need them to identify the things that need testing and compare test results with requirements

## baseline as an oracle for required behaviour

a baseline document describes how we require the system to behave
oracle = a source to determine expected results to compare with the actual result of the software under test. An oracle may be the existing system (for a benchmark), a user manual, or an individual’s specialised knowledge, but should not be the code.

**you can't use code as baseline document** = we can't say if the software is doing what is expected to do

## expected results

we need to define results before testing
if we don't do this:
-  a plausible, but erroneous, result may be interpreted as the correct result
-  there may be a subconscious desire or bias to see the software pass the test
expected results must be defined before test execution, derived from a baseline

# exit, completion, closure or acceptance criteria

## exit criteria

-  expected result is referring to a single test, exit criteria is referring to a testing phase
-  trigger to say "we've done enough"
-  objective, non-technical for managers that do not understand technical side of the project
-  measurable, achievable targets
-  coverage items are usually defined in terms of requirements, conditions, business transactions, code statements, branches