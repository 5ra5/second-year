# part 1 - importance

why do we test requirements?
-  to see what the end user wants
-  if a feature is truly needed in the program
-  to see if it's even testable

poor quality requirements occur:
-  partly because requirements elicitation and clarification is challenging;
-  partly because some developers choose to not invest sufficient time and effort into requirements

there is a broad spectrum of techniques for defining requirements
range from very formal (mathematical notation) to very informal (verbal)

level of detail documented for software requirements:
-  non-verbalised idea
-  verbalised idea

**agile software development**
-  whiteboard only
-  brief user stories - post-it only
-  detailed user stories

**traditional software development**
-  detailed software requirements specification
-  formal definition

**user stories** = **features** = **requirements**

# part 2 - problem

- there are many gaps in the natural language / human understanding / communication sphere
- for example: a person on the software development team and the person on the business team will not have the same technical knowledge of the other person, so we need to find the language to express the idea so that the other person understands as well as they can

- humans are more inclined towards action rather than careful planning
- we are optimised for operational type activities, rather than problem avoidance
this is not a good approach when it comes to software development

-  inadequately defined requirements may be the primary source of software defects
-  from a business perspective, you need to have good and simple requirements for stakeholders to understand and agree to them (this helps us understand what they want too)

# part 3 - requirements

2 types of software development: agile and non-agile

**agile** = breaks development down into much smaller development cycles and increases release frequency, designed to avoid lengthy phases of requirements documentation
-  it is important to find a balance though, because we might end up with too much unnecessary code if we rely on agile development too much

requirements should be **critically evaluated**

# part 4 - more problems...

1.  quality of individual requirements / users stories
2.  the quality of a group of software requirements / user stories when considered as a whole

## 1. quality of individual requirements

is each quality requirement:
-  mandatory
-  feasible
-  scalable
-  unambiguous
-  verifiable
-  correct
-  prioritised
-  traced to its source?

***THIS MIGHT COME UP IN THE LAB EXAM***
CHARACTERISTICS OF QUALITY REQUIREMENT STATEMENTS:

-  CORRECT
-  FEASIBLE
-  NECESSARY
-   PRIORITISED
-  UNAMBIGUOUS - the person that is reading the requirement for the first time should only conclude one thing out of that description
-  VERIFIABLE - you need to be able to run a test against it
-  implementing Test Driven Development (TDD) - this is writing the test case before programming
-  SCALABLE - implementing a large number of procedures and isolation as it might be required operationally
-  TRACEABLE -  we need to be able to trace where is the requirement coming from, and determine whether the stakeholder is authorised to make that requirement

## 2. quality of collective requirements

-  OVERALL
-  COMPLETE
-  CONSISTENT - do not conflict with other software requirements or system and business requirements
-  MODIFIABLE
-  TRACEABLE

if we change requirements, or introduce new ones, we need to be aware of how this will impact the rest of requirements
every requirement should have a number associated with it - we can have parent and child requirements
traceable requirements are uniquely labelled and are written in a structured, fine-grained way

