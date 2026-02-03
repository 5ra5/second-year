**1 Testing shows the presence of defects**
-  the more defects we can find, the more we can fix, and the better the software will be
-  testing can show that defects are present, but cannot prove that there are no defects
-  it is impossible to test everything and find all defects, no matter how rigorous the testing approach is
-  we can't say that there is no defects in the software

**2 Exhaustive testing is impossible**
-  we have to make sure that we are using test cases that are efficient in finding defects in the most important part of software

**3 Early testing**
-  testing activities should start as early as possible in the software or system development life cycle, and should be focused on defined objectives
-  as time goes by, if a defect is found it costs more and more to fix
-  the earlier you find the defect, the cheaper it will be to fix it (e.g. in requirements stage you just need to rewrite the requirement on a piece of paper)

**4 Defect clustering**
-  we've already seen an illustration of this
-  a small number of modules contain most of the defects discovered during pre-release testing, or show the most operational failures

**5 Pesticide paradox**
-  If the same tests are repeated again and again, eventually, these test cases will no longer find new defects
-  This is the "pesticide paradox". When all the defects are removed, our tests will find no more
-  If we want to find more defects, we need new and different tests to be written to exercise different parts of the software or execute different program paths.

**6 Testing is context dependent**
-  The testing we do must take account of the context
-  For example, safety-critical software is tested differently from an e-commerce site because the risk of failure is so much higher
-  The testing approach for embedded, mainframe or web based software will also vary
-  Obvious really, but we need to accommodate these changes in context

**7 Absence-of-errors fallacy**
-  A system may have a good specification, and be tested thoroughly but it is still possible for the system to not meet the needs of its users
-  This could be because the specification does not represent the needs of the users
-  Finding and fixing defects does not help if the system has been based on faulty requirements that do not represent the real users’ needs and expectations.
-  Indicates that tests weren't made according to user requirements

**Additional testing Principles**

1. The goal of testing is to find defects before customers find them.
2. Understand the reason behind the test.
3. Test the tests first. (swapping test cases with other testers to determine whether they are valid when compared to requirements - if you wrote the test case someone else will run it)
4.  Corrections can have side-effects. (regression testing)
5. Defects occur in convoys or clusters, and testing should focus on these convoys.
6. Testing encompasses defect prevention. (connected to 3rd principle - taxonomy based testing is testing based of predicted defects)
7. Testing is a fine balance of defect prevention and defect detection.
8. Intelligent and well-planned automation is key to realising the benefits of testing. (People that test a lot tend to miss some defects through too much manual testing)
9. Testing requires talented, committed people who believe in themselves and work in teams.