**software process** = defines the way to produce software
it includes:
-  software life-cycle model (different flavours, testing depends on the flavour)
-  tools to use
-  individuals building software

**software life-cycle model** defines how different phases of the life cycle are managed

**software development life cycle** (SDLC) = differs on which model you use

phases of software development also differ based on the model you use, agile model would skip some of the steps, while more traditional ones would be even greater (some steps are consistent across all models and approaches)

all of these happen, but the order depends on the approach:
-  requirements gathering
-  specification
-  design
-  code
-  testing
-  implement

these steps can be done multiple times, or just once depending on our approach
phases overlap, they are usually not linear
-  we need to test along all steps

## life-cycle models

-  build-and-fix model
-  waterfall model
-  rapid prototyping model
-  spiral model
-  prototyping model
-  phased development model (incremental and iterative)
-  formal systems development
-  agile models (extreme programming, scrum, FDD)

## build and fix model

you code up something and see if it works, and add on something until you are satisfied (e.g. student projects)
no model associated with this
no specification and no design associated with this approach
not really a model at all, should not be used, it is unsatisfactory

## waterfall model

-  we do one phase, finish it, and move to the next one
-  problem: if we discover a problem in the later stage, we need to start from the beginning (very costly because we're assuming that we're on the right path)
-  we need to test requirements to prevent this problem
-  we need to check that we're doing what we were assigned to do

advantages: each phase is well documented and maintenance might be easier
-  good for formal, nuclear, medical fields: heavy documentation, everything is very traceable
-  we know what was done and why it was implemented in detail

## iterative development models

-  more of an agile approach
-  the process of establishing requirements, designing, building and testing a system, done **as a series of smaller developments**
-  doesn't require formal documentation, used in non-formal projects

examples: prototyping, rapid application development (RAD), rational unified process (RUP) and agile development models

**regression testing is increasingly important** on all iterations after the first one because we need to check if we broke something after each iterations

## incremental model

-  break system into small components
-  adding functionality gradually
-  prioritising requirements and adding them increment at a time
-  adding on the same chunk again and again

## iterative vs waterfall

-  waterfall attempts to solve big problems in one project
-  iterative/incremental/evolutionary attempts to solve big problems in a number of smaller steps (LESS AMBITIOUS => LOWER RISK)
-  with iterative approach, each increment provides feedback and direction for the next increment
-  waterfall doesn't give us a chance to reverse some decisions

note: the creator of the Waterfall model, Winston Royce (1970) actually permitted and encouraged iterative development but this is not generally recognised.


## testing within a life cycle model

-  we **'divide and conquer'** the task of testing
-  **testers should be involved in reviewing documents as soon as drafts are available** in the development cycle
-  testing builds up as we progress through the various stages

## typical test process?

-  ad hoc testing (process that happens just before debugging done by developers, if something goes wrong debugging begins)
-  component testing
-  integration test
-  system test
-  acceptance test (testing against user requirements)

## from theory to the V-model

Although variants of the V-model (verification and validation) exist four levels are common
The four commonly levels are:
1.  component (unit) testing
2.  integration testing
3.  system testing
4.  acceptance testing
V-model may have more, fewer or different levels of development and testing, depending on the project and the software product.

-  every phase has it's own testing phase

## continuous software engineering (CSE)

phases:
-  development
-  repository
-  build
-  test
-  infrastructure
-  deployment

all of the pieces of code are checked into a source control server
-  agile approach

server performs automated testing after each change
everyone gets notified of success or failure by continuous integration server
there is an incentive to check your work before checking it into the server because your mistakes are traceable

there are tools that are associated with all of the phases of this development model

-  Automation/Tooling does not replace existing lifecycles.
-  Sometimes it is integrated into a traditional lifecycle model – e.g. using Continuous Integration in a V model
-  Traditional models continue to have an impact but take advantage of tooling where beneficial
-  Some software engineering has speeded up considerably because of the speed of computer based testing (e.g. DevOps and CSE).
-  And the tooling is not just related to testing. There is tooling support for many (all?) lifecycle phases. 

## influences on the test process

 -  The nature and type of faults to test for
-  The object under test
-  Capabilities of developers, testers, users
-  Availability of: environment, tools, data
-  The different purpose(s) of testing
-  to detect faults
-  to demonstrate contractual requirements are met
-  to provide evidence that software works and build confidence.

## lifecycle model influences testing

-  The approach to testing can vary significantly between different lifecycle models.
For example, in a traditional V model of software development: requirements are extensively elaborated for entire systems up front, these requirements are exhaustively tested prior to coding. The testing emphasis thereafter may focus on robust integration and system level testing.

In contrast, in a continuous software engineering approach: software requirements are not exhaustively elaborated for entire systems prior to coding and therefore, the capacity to test the system requirements as a whole up front does not exist. System testing still occurs, but in this scenario a robust focus on unit testing, integration testing and regression testing is emphasised.

Consider the difference between embedded software for a pacemaker (V Model) and a web site that is continually being evolved and extended (CSE). These two scenarios lend themselves to two different software development approaches and consequently, to two different testing strategies. 

**not a "black and white picture**:
Aspects of testing that are common in CSE might be useful for traditional V model lifecycles.

## staged testing moves from small to large

-  We start by testing each component (in isolation)
-  As tested components become available, we test groups of programs - sub-systems
-  Then we combine sub-systems and test the system
-  Then we combine single systems with other systems and test.

## levels of testing have different objectives

The objectives at each level are different
-  Individual **components are tested for their conformance to their specification**
-  Groups of components are tested for conformance to the physical design
-  Sub-systems / **systems are tested for conformance to the functional specifications and requirements.**
