# Usage models
- Use Case Overview Diagram (UML)
- Use Case Scenarios

SSADM = Structured Systems Analysis and Design Method
- Developed in the 80's by the British government

These people made very important contributions to software engineering:
Soft Systems Methodology - Peter Checkland
Stuctured Design - Larry Constantine
Yourdon Structures Method - Edward Yourdon
Jackson Structured Programming - Michael A. Jackson
Structured Analysis - Tom DeMarco

A usage model describes the system behaviour from the point of view of the user by modeling interaction sequences

Typically 3 parts:
1. Use Case Overview Diagram (Bubble diagram) - shows what the system is about, and what are its functions, there is not a lot of details
2. Use Case Templates - more detail about a specific bubble in the bubble diagram (a specific function in the system)
3. Scenario Diagrams - one per use template

- The stick figures outside of the diagram represent customers/clients and service providers

Use Case:
- A contract of interaction between the system and an actor
- An actor is an external objects that produce or consume data (the stick figure drawn outside the system boundary)
- I.e machines, sensors, external systems, humans, organisational units
- We will typically stick to humans and organisational units
- The child actor inherits all use cases associations
- A stakeholder is someone with an interest in the behaviour of the use case
- Every primary actor is a stakeholder, but there are some stakeholders that never interacts with the system, so we don't include them as stick figures in the diagram

- To determine actors, look for people involved in the system descriptions
- To determine use cases, look for verbs in the system descriptions

UML Tools - Star UML, Argo UML, LucidChart...
These tools allow us to draw pictures as well as link diagrams, check validation/error/consistency and generate code

Common mistakes in diagrams are that it is too complex, it doesn't have key components like system or actor, or the details don't describe the function properly.

Alternative Flows are used to describe exception functionalities (errors, failures, rare or unusual cases, starting points, end points...)

Linking (connecting) the use cases enables flexibility in requirements specifications
In Use Case Overview Diagram we connect bubbles by lines that could represent either:
```<include>``` - always must be carried out
```<extend>``` - optional 

Use Case Template
Name: Every bubble should have the name of the use case it is representing
Actors: People using the system
Trigger: The very first step of Success Scenario, it is what causes the use case to be activated (for example user enters product name, ID...)
Pre-conditions: What we have before 
Post-conditions: The outcome of the use case, the system has to have a minimal guarantee of performing a specific action
Success Scenario `<List Steps>`: The most important part that shows steps that the user and the system make when the system is being used by the user (the back and forth actions between them).
- It is important to use indentation in the template so we know who initiated a step during the use: actor or system.
- A use case is a set of scenarios

Scenario = a concrete interaction sequence
- we can make scenarios using UML Sequence Diagram