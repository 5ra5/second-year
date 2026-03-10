# Configuration management
## Background

For testing, configuration management may involve ensuring that:
-  All items of testware are identified, version controlled, tracked for changes, related to each other and related to development items (test objects) so that 
-  All identified documents and software items are referenced unambiguously in test documentation
The configuration management procedures and infrastructure (tools) should be chosen, documented and implemented.

Example documentation:
-  Requirement Specification
-  Design Specification
-  Code
-  Test Specification
-  Configuration Files
-  Build Environment
-  Releases (V1.0, V1.1, V2.0, V2.1)
-  User Documents

In a case of a new version V1.1.1:

-  Receive support & maintaining requirements
-  Reproduce build (if necessary)
-  Reproduce issue
-  Fix Issue (if necessary)
-  Ship patch / New build (if necessary) (**don't break functionality / quality**)
-  Update Supporting Artefacts (if necessary)

## Symptoms of poor configuration management

Can't find latest version of source code or match source to object
Can't replicate previously released version of code for a customer
Bugs that were fixed suddenly reappear
Wrong functionality shipped
Wrong code tested
Undocumented features suddenly appear
Tested features suddenly disappear
Can't trace which customer has which version of code
Simultaneous changes made to same source module by multiple developers and some changes lost.

## The answers Configuration Management (CM) provides

What is our current software configuration?
What is its status?
How do we control changes to our configuration?
What changes have been made to our software?
Does anyone else's changes affect our software?

# Risk and Testing

## Stakeholder Objectives and Risks

Definition: "A Stakeholder Objective is one of the fundamental objectives of the system to be built".
-  Benefits of undertaking the project
-  Payoff(s) that underpin and justify the project 
Software risks are potential events or things that threaten the Cardinal Objectives of a project.
Definition: "A risk is a threat to one or more of the cardinal objectives of a project that has an uncertain probability".

## Some general statements about risk

Let’s explore our definition of risk
Risks only exist where there is uncertainty
-  if the probability of a risk is zero or 100%, it is not a risk
-  unless there is the potential for loss, there is no risk
There are risks associated with every project - software development is inherently risky.
Risk pervades our language

## Risk examples

A safety critical risk
-  aircraft system fails => incorrect build was delivered
Political
-  Immigration system fails => early delivery, poor quality
Economic or financial
-  banking system failure => under/overpayments
Technical
-  COTS component => too big (memory) or slow to use
Security
-  security vulnerability => fraud by a hacker.

## Three types of software risk

Project Risk
-  resource constraints
-  external interfaces
-  supplier relationships
-  contract restrictions
Primarily a management responsibility

Process Risk
-  variances in planning and estimation
-  shortfalls in staffing
-  failure to track progress
-  lack of quality assurance and configuration management
Planning and the development process are the main issues here.

Product Risk
-  lack of requirements
-  stability
-  complexity
-  design quality
-  coding quality
-  non-functional issues
-  test specifications
Requirements risks are the most significant risks reported in risk assessments.
Testers are mainly concerned with Product Risk.

## Product Risks

Potential failure areas (adverse future events or hazards) in the software or system are known as product risks, as they are a risk to the quality of the product, such 
-  Error-prone software delivered.
-  The potential that the software/hardware could cause harm to an individual or company.
-  Poor software quality characteristics (e.g. functionality, security, reliability, usability and performance).
-  Software that does not perform its intended functions.

## Process risks

Poor planning
-  under (or over) estimation
-  assignment of the wrongly skilled or under-skilled resources
Poor monitoring
-  failure to monitor progress against plans
-  failure to monitor the results of testing
Poor control
-  failure to understand the impact of events occurring
-  failure to take any action or the wrong actions when confronted by problems.

## Risk-Based Testing

Risks are used to decide where to start testing and where to test more; testing is used to reduce the risk of an adverse effect occurring, or to reduce its impact. 
Product risks are a special type of risk to the success of a project.
Testing as a risk-control activity provides feedback about the residual risk by measuring the effectiveness of critical defect removal and of contingency plans.

In a risk-based approach the risks identified may be used to:
-  Determine the test techniques to be employed.
-  Determine the extent of testing to be carried out.* Prioritise testing in an attempt to find the critical defects as early as possible.
-  Determine whether any non-testing activities could be employed to reduce risk (e.g. providing training to inexperienced designers).
Risk-based testing draws on the collective knowledge and insight of the project stakeholders to determine the risks and the levels of testing required to address 

To ensure that the chance of a product failure is minimized, risk management activities provide a disciplined approach to: 
-  Assess (and reassess on a regular basis) what can go wrong (risks).
-  Determine what risks are important to deal with.
-  Implement actions to deal with those risks.
In addition, testing may support the identification of new risks, may help to determine what risks should be reduced, and may lower uncertainty about risks.

## Brainstorm: Identifying risks

For each of the key requirements, let’s make a list of the possible modes of failure
Main requirements of an ATM:
-  validation of a customers card and PIN - The machine should accept a valid card and validate your PIN number prior to you using the other features of the ATM.
-  cash withdrawal - The machine accepts a request for a cash withdrawal up to the limit on your card.
-  on-line balance request - The machine will display an up to date balance of your account.
-  request a statement to be sent to your address
...amongst others.

## Risk for 4 main categories

-  Validation of a customer card and PIN
-  Cash withdrawal
-  On-line Balance Request
-  Request a Statement

**Validation of a customer card and PIN**
-  Machine will not allow card to be inserted
-  Machine accepts an invalid card
-  Machine accepts card but locks up and wont return it
-  Machine accepts an invalid PIN and allows user to proceed
-  Machine rejects a valid PIN and retains card

# Incident Management

## Why track incidents?

The objectives of incident reporting:
-  To provide developers and other parties with feedback about the problem to enable identification, isolation and correction as necessary.
-  To provide test leaders a means of tracking the quality of the system under test and the progress of the testing.
-  To provide an input to test process improvement initiatives.

## When to log an incident

We log incidents when a test result appears to be different from the expected result
This could be because:
-  something wrong with the test
-  something wrong with the expected result
-  something wrong with the tester
-  a misinterpretation of the result
-  something wrong with the test environment
-  something wrong with the baseline
Or it COULD BE a software fault.

## Incident reporting

The tester should stop and complete an incident report
-  describe exactly what is "wrong"
-  document the test script and script step identifiers
-  attach any outputs (screen dumps or printouts) that may be useful
-  impact on your current tests


Bug tracking software:
-  **Reporting facility** – complete with fields that will let you provide information about the bug, environment, module, severity, screenshots etc.
-  **Assigning** – What good is a bug when all you can do is find it and keep it to yourself, right?
-  Progressing through the life cycle stages – **Workflow**
-  **History/work log/comments**
-  **Reports** – graphs or charts
-  **Storage and retrieval** – Every entity in a testing process needs to be uniquely identifiable, the same rule applies to bugs too. So, a bug tracking tool must provide a way to have an ID, which can be used to store, retrieve (search) and organize bug information.
## The Tooling Jungle - a very brief overview

**Automated UT**
-  pyunit
-  junit

**IDE**
-  IDLE
-  Eclipse

**Defect Tracking**
-  Jira
-  Bugzilla

**Automated Web/GUI/ST**
-  Selenium

**Note: Some tools do more than just one thing (e.g. defect tracking tools may also be used for project management)**

