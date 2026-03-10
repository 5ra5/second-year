**Explain the difference between a product risk and a process risk. Give one example of each.**
A product risk refers to a functional aspect of a system, while a process risk refers to a risk we encounter during the production of the said system. A product risk example includes a functional defect - something is not working the way it was intended to according to requirement documentation, while a process risk example includes over or under estimating and planning testing so we do not cover all of the functionality we wanted to test, or we do not have correct test cases, which give us unsatisfactory results, and do not discover defects in time.

**What is the 'pesticide paradox' and what should a test team do to address it?**
The pesticide paradox states that if the same tests are repeated many times, they will eventually stop finding defects. A test team should do test control if they are getting too many similar outputs or are testing one area of the system too much. That is how they determine whether tests need to be improved upon. Exploratory testing could also be an option here since it promotes finding new tests, or error guessing which is when testers look for errors based on previous experience and intuition.

**Why is it important that expected results are defined before test execution, and where should they be derived from?**
Results have to be defined before the test execution so that the tester does not have confirmation bias and accepting an output that does not match the user requirements. Results should always be derived from baseline documents - user requirements, functional and non-functional, system design etc.

**Describe two benefits and one drawback of using an independent test team.**
Benefits of using an independent test team include more test independence, which ensures a more objective testing being done, therefore a lesser risk of tester bias, and potentially a different set of skills that other test team might posses to find defects that an internal team would not have.
A drawback of an independent test team is that they do not know the system as well as the internal test team, and they might not know about riskier units and components within the system which might contain more defects.

**Describe the roles of the 'driver' and 'navigator' in pair programming and explain what 'ping-pong programming' adds to this.**

The driver sits at the computer and programs out loud explaining what they are doing. They work on current function/component, while the navigator sits beside them and watches them. Navigator sees the bigger picture, asks questions and makes suggestions to the driver. Ping-pong programming keeps a dynamic atmosphere in which both parties are engaged in the development process as it requires both programmers to write code and respond to each other.

**What are stubs and drivers? Which integration strategy does each support?**
Stubs and drivers are placeholders for components that do not yet exist. They are used in testing, and they mimic the behaviour of the component and how it interacts with the component that we are testing. They can be in a form of a script, a program or a third-party product. Stubs are used in top-down integration strategy, where they act as a lower-level component that is being called by the component that is being tested, while drivers are used in bottom-up integration strategy and it is mimicking a component that is higher-level than the component being tested and the component we are testing is typically being called by the driver.

**Explain why a CSE approach and a V-Model approach lead to different testing strategies, using an example for each.**
In the V-Model, requirements are exhaustively elaborated upfront and tested before coding, with strong focus on integration and system testing. This suits safety-critical software like a pacemaker,where thorough requirements
verification is essential. In CSE, requirements aren't fully elaborated
before coding, so the focus shifts to unit, integration and regression testing to
ensure continuous quality. This suits a website being continuously evolved and extended