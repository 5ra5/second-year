# Fundamental Test Process

## What is a test?

A test is a controlled exercise involving:
-  an object under test
-  a definition of the environment
-  a definition of the inputs
-  a definition of expected outputs or result

When a test is performed you get
-  an actual output or result
-  a determination whether the result is correct.

## Expected results

When we run a test, we must have an expected result derived from the baseline

An actual result either matches or does not match the expected result

If there is a difference, there may be a fault in the software and we should investigate.

## The Test Process

The fundamental test process consists of the following main activities:
-  test planning
-  test control
-  test analysis
-  test design
-  test implementation (aka preparation)
-  test execution and recording
-  evaluating exit criteria and reporting
-  test closure activities

Although logically sequential, the activities in the process may overlap or take place concurrently.

By the way, the object under test need not be machine executable. That is, reviews and inspections have a similar process. This might seem like it is stretching.

The other key point to be made here is that testing, as defined in this course, covers all activities for static and dynamic testing. We include inspections, reviews

## Test planning

Planning determines how the test strategy will be implemented:
-  what will not be done according to the strategy
-  what will be done according to the strategy
-  what will be adapted

Test planning identifies, at a high level, the scope, approach and dependencies:
-  the software component(s) to be tested
-  additional infrastructure to test the component
-  the approach to test design
-  the test completion criteria

Test planning has the following major tasks:
-  Determining the scope and risks, and identifying the objectives of testing
-  Determining the test approach (techniques, test items, coverage, identifying and interfacing the teams involved in testing, testware)
-  Determining the required test resources (e.g. people, test environment, PCs)
-  Implementing the test policy and/or the test strategy
-  Scheduling test analysis and design tasks
-  Scheduling test implementation, execution and evaluation
-  Determining the exit criteria.

## Test control

Test control has the following major tasks:
-  measuring and analysing results
-  monitoring and documenting progress, test coverage and exit criteria
-  initiation or corrective actions
-  deciding what to do next.

## Test analysis

Test analysis is the activity where tangible test conditions and test design are derived from the baseline documents.

Firstly, the test basis (the baselines, such as requirements, architecture, design, interfaces) are reviewed.

If the baseline is testable, test conditions (or test requirements) are defined

## Test design

Designing the test environment set-up and identifying any required infrastructure and tools.

A test inventory is prepared
-  the features to be tested
-  logical test cases to be exercised
-  test case prioritisation, where necessary

When test design is complete, detailed scripts, test data and expected results can be prepared - this is called implementation.

## Test implementation (preparation)

Test implementation is where test conditions are transformed into test cases and testware, and the environment is set up

From the test cases, we can then identify and create test data, write test procedures, prepare expected results and, optionally, automate the tests

We group tests into suites for efficient test execution

## Test execution and recording

Perform your "Pre-flight checks"

Tests follows the scripts, as defined

Test cases are run either manually or by using test execution tools, according to the planned sequence

We verify that actual results meet expected results and raise incident reports if they don't

As we do progress through the tests, we log progress.

## Raising incidents, re-testing and regression testing

We report test failures of discrepancies as incidents and analyse them in order to establish their cause

We repeat test activities as result of action taken for each failure which could be:
-  re-tests (confirmation tests)
-  regression tests

## Evaluating exit criteria

Evaluating exit criteria is the activity where test execution is assessed against the defined objectives

This should be done for every test, regardless of phase
-  We check test logs against the exit criteria specified in test planning
-  We asses whether more tests are needed or if the exit criteria specified should be changed.

Under time pressure...
-  some faults may be acceptable (for this release)
-  some tests may not be run at all

If there are not tests left but there is still time
-  maybe some additional tests could be run

You may decide to release the software now, but testing could continue.

## Test closure activities

Usually, a test summary report must be written for stakeholders at the end of a test phase

The summary provides stakeholders the evidence they need to make a decision (to release, to postpone, or in extreme circumstances, to cancel)
-  status of deliverables and documentation
-  aligned with sign-off and handover

The test team usually have a contribution to make to post implementation reviews, where lessons are learned for future releases and projects.