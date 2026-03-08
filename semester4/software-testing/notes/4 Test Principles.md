# General Testing Principles

## Principle 1 - Testing shows the presence of defects

Testing can show that defects are present, but cannot prove that there are no defects.
Testing reduces the probability of undiscovered defects remaining in the software but, even if no defects are found, it is not a proof of correctness.

## Principle 2 - Exhaustive testing is impossible

Exhaustive testing of all program paths is usually impossible
Exhaustive testing of all inputs is also impossible
If we could do exhaustive testing, most tests would be duplicates that tell us nothing
We need to select tests that are effective at finding faults but are also efficient
Instead of exhaustive testing, we use risk and priorities to focus our testing efforts.

## Principle 3 - Early testing

Testing activities should start as early as possible in the software of system development life cycle, and should be focused on defined objectives.

## Principle 4 - Defect clustering

We've already seen an illustration of this
A small number of modules contain most of the defects discovered during pre-release testing, or show the most operational failures.

## Principle 5 - Pesticide paradox

If the dame tests are repeated again and again, eventually these test cases will no longer find new defects
This is the "**pesticide paradox**". When all the defects are removed, our tests will find no more
If we want to find more defects, we need new and different tests to be written to exercise different parts of the software or execute different program paths.

## Principle 6 - Testing is context dependent

The testing we do must take account of the context
For example, safety-critical software is tested differently from and e-commerce site because the risk of failure is so much higher
The testing approach for embedded, mainframe or web based software will also vary
Obvious really, but we need to accommodate these changes in context.

## Principle 7 - Absence-of-errors fallacy

A system may have a good specification, and be tested thoroughly but it is still possible for the system to not meet the needs of its users
This could be because the specification does not represent the needs of the users
Finding and fixing defects does not help if the system has been based on faulty requirements that do not represent the real users' need and expectations.

## Additional testing Principles worth keeping in mind...

1.  The goal of testing is to find defects before customers find them.
2.  Understand the reason behind the test.
3.  Test the tests first.
4.  Corrections can have side-effects.
5.  Defects occur in convoys and clusters, and testing should focus on these convoys.
6.  Testing encompasses defect prevention.
7.  Testing is a fine balance of defect prevention and defect detection.
8.  Intelligent and well-planned automation is key to realising the benefits of testing.
9.  Testing requires talented, committed people who believe in themselves and work in teams.