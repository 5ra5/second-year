**test** = a controlled exercise involving:
-  an object under test
-  a definition of the environment
-  a definition of the inputs
-  a definition of expected outputs or result (need to be defined before testing in requirements)

after a test is performed you get
-  an actual output or result
-  a determination whether the result is correct

expected output can be based from requirements document, technical specification document etc.
when we run a test, we must have an expected result derived from the baseline

## test process

-  test planning
-  test control
-  test analysis
-  test design
-  test implementation (preparation)
-  test execution and recording
-  evaluation exit criteria and reporting
-  test closure activities

in real life, these phases will overlap as the test process can get messy
there are things we can do concurrently 

## test planning

planning determines how the test strategy will be implemented:
-  what will not be done according to the strategy
-  what will be done according to the strategy
-  what will be adapted
test planning identifies, at a high level, the scope, approach and dependencies
test planning has major tasks:
-  determining scope and risks, identifying objectives of testing
-  determining test approach (techniques, test items, coverage etc.)
-  determining required test resources
-  implementing the test policy and/or the test strategy
-  scheduling test analysis and design tasks
-  scheduling test implementation, execution and evaluation
-  **important**: determining the exit criteria

## test control

you need to determine whether you are hitting your exit criteria
if you are behind the schedule, maybe you need more testers, or you need to leave out some tests, but this is all determined during test control

Test control has the following major tasks:
-  measuring and analysing results
-  monitoring and documenting progress, test coverage and exit criteria
-  initiation of corrective actions
-  deciding what to do next.

## test analysis

-  we need to figure out what our test conditions are going to look like
-  if we find a requirements document or a requirement within that is untestable, we know that the requirement is not good enough and you can send it back to the owner (the requirement needs to be traceable to find the owner)

## test design

-  designing the test environment set-up and identifying any required infrastructure and tools
-  preparing test inventory ( features to be tested, logical test cases, test case prioritisation)
-  we can start writing test cases

## test implementation (preparation)

-  actually writing test cases and sometimes fake data to test with
-  we are looking at the requirement catalogue, and writing that information to test against the software
-  considering making automated tests
-  we group tests into suites for efficient test execution (tends to be automated and useful for regression testing)
-  a regression test suite grows over time as it should be constantly updated and maintained

## test execution and recording

-  executing tests
-  perform "pre-flight checks" = make sure that the testing environment is appropriate and working
-  you run everything you designed in previous steps
-  you just look for expected and actual results not matching with every step
-  you log progress as you go along

## raising incidents, re-testing and regression testing

-  helping developers understand what is going on with the defect - you need to explain the environment you were in, the input and output, include screenshots etc.
-  we report test failures or discrepancies as incidents and analyse them in order to establish their cause
-  we repeat test activities as result of action taken for each failure which could be re-tests (confirmation tests) and regression tests

## exit criteria

-  evaluating exit criteria = activity where test execution is assessed against the defined objectives
-  this should be done for every test, regardless of phase
-  under time pressure some faults may be acceptable (for this release) and some test may not be run at all
-  very unlikely: if there are not tests left, but there is still time we run additional tests
-  sometimes there may be instances in which the software is released but testing is continued

## test closure activities

-  tends to be neglected - tying the whole project up
-  test summary report is written for stakeholders at the end of a test phase
-  the summary provides stakeholders the evidence they need to make a decision (to release, postpone, or in extreme circumstances, to cancel)
-  the test team usually have a contribution to make to post implementation reviews, where lessons are learned for future releases and projects
-  this saves time for next projects or testing phases