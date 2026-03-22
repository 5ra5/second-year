## Assignment Instructions

You are required to design a **UML class diagram** for the system described in your task.

Your goal is to produce a **clear, well-structured object-oriented design** that demonstrates your understanding of:

- class design and responsibilities
- inheritance and hierarchy
- interfaces and abstraction
- relationships between classes (association, aggregation, composition)
- designing systems that are easy to extend in the future
- **design patterns**

You are **not required to write any code**. Focus on the **design**.

### What to include

Your UML diagram must:
- include **at least 10 classes**
- include **at least one abstract class**
- include **at least one interface**
- include a **clear inheritance hierarchy**
- include **has-a relationships** where appropriate
- show **attributes and key methods**
- clearly represent how the system operates

The diagram should be **readable and logically organised**.

### Deliverable

- One UML class diagram
- Drawn on **A4 or A3 paper**
- Clearly labelled and structured

It is advised to include short notes where needed, but keep them concise.

### Deadline

The deadline for submission is **10th of April**.

You are strongly encouraged to complete the task **earlier** to allow time for feedback and questions.

### Consultation

If you need help or clarification:

- Speak to me **after lectures**, or
- Come to **Thursday at 4pm in L125**
Please note: if nobody is present at that time, I will not remain in the room.

### UML Class Design Task: School Timetable Scheduling, Room Assignment and Change Notification Control

## Task Description

A secondary school is introducing a timetable and room allocation system to organise weekly lessons, assign suitable rooms, and manage day-to-day timetable disruptions. The school needs to create scheduled lesson sessions for different teaching groups, place them into appropriate rooms, and handle operational changes such as delays, room moves, cancellations, and confirmed completion of lessons.

Each scheduled lesson belongs to a subject, is taught by a member of staff, and is attended by a teaching group. Rooms have capacities and characteristics such as whether they are standard classrooms, science laboratories, or computer suites. Some lessons require special room features, so the allocation mechanism must consider suitability as well as basic availability.

The school also wants staff and student groups to be informed when a lesson changes status. At present, the school may use email or internal app messages, but further notification channels are expected in future. The design should therefore allow timetable notifications to be extended without restructuring the whole model.

Operationally, a scheduled lesson does not remain in the same condition throughout the day. A lesson may be planned in advance, then confirmed for delivery, delayed because a teacher is temporarily unavailable, moved to a different room, cancelled, or marked as completed after it has taken place. The system should keep the responsibilities for these condition changes organised rather than placing all decision logic into one large class.

The school administration wants a UML class diagram for the core design only. The diagram should be suitable for discussion during a module exercise and should focus on class structure, responsibilities, relationships, and key operations.

Produce a UML class diagram for the core object-oriented design of this school timetable and room allocation system. Your diagram should show the main classes, interfaces, abstract classes, attributes or responsibilities where appropriate, and the key operations needed to support scheduling, room allocation, lesson condition changes, and notifications. Use clear multiplicities and relationship types where relevant. You are designing the model only; do not write code or sequence diagrams.

## System Elements

Your diagram must include the following concrete modelling elements and responsibilities. You may add small supporting attributes or operations if needed, but keep the design focused and coherent for a paper-based UML exercise.

- `LessonSession` (class) — Represents one scheduled lesson for a subject, teaching group, teacher, time slot, room allocation, and current operational condition.
	- assignRoom()
    - changeRoom()
    - delayLesson()
    - cancelLesson()
    - confirmLesson()
    - markCompleted()
    - notifyParticipants()
    
- `Subject` (class) — Represents an academic subject attached to scheduled lessons.
    - getTitle()
    - getRequiredRoomFeature()
    
- `Teacher` (class) — Represents a member of staff who delivers lessons and receives timetable updates.
    
    - viewAssignedLessons()
    - receiveNotification()

- `TeachingGroup` (class) — Represents a class or year group attending lessons and receiving timetable updates.
    - viewTimetable()
    - receiveNotification()


- `TimeSlot` (class) — Represents the day and period information for a scheduled lesson.
    - overlapsWith()
    - getDisplayLabel()
    
- `Room` (abstract class) — Represents a school room with an identifier, capacity, and availability information used in allocation decisions.
    - isAvailable()
    - isSuitableFor()
    
- `Classroom` (class) — Represents a standard teaching room.
    
    - isSuitableFor()
        
    
- `ScienceLab` (class) — Represents a laboratory room with specialist suitability for science lessons.
    
    - isSuitableFor()
        
    
- `ComputerSuite` (class) — Represents a computer-equipped room for lessons requiring computing facilities.
    
    - isSuitableFor()
        
    
- `RoomAllocator` (class) — Selects and assigns an appropriate room for a lesson session based on availability, capacity, and suitability.
    
    - allocateRoom()
        
    - findAvailableRooms()
        
    - reallocateRoom()
        
    
- `LessonState` (interface) — Defines the behaviour associated with the current operational condition of a lesson session.
    
    - confirm()
        
    - delay()
        
    - cancel()
        
    - complete()
        
    - changeRoom()
        
    
- `PlannedState` (class) — Represents a lesson that has been scheduled but not yet confirmed for delivery.
    
    - confirm()
        
    - delay()
        
    - cancel()
        
    - changeRoom()
        
    
- `InProgressState` (class) — Represents a lesson that is currently active or confirmed and may proceed to completion or disruption.
    
    - delay()
        
    - cancel()
        
    - complete()
        
    - changeRoom()
        
    
- `CancelledState` (class) — Represents a lesson that will no longer take place and should restrict further operational changes.
    
    - cancel()
        
    
- `NotificationChannel` (interface) — Defines how timetable change messages are sent to teachers and teaching groups through different communication channels.
    
    - sendNotification()
        
    

## Expected Behaviour

The school expects the design to support the following system behaviour through appropriate class responsibilities and relationships.

- Create a lesson session for a particular subject, teacher, teaching group, and time slot.
    
- Allocate a suitable room to a lesson session using room type, capacity, and availability.
    
- Allow a lesson session to be moved to another room when circumstances change.
    
- Represent different operational conditions of a lesson session, including planned, active/confirmed, and cancelled, with behaviour varying according to the current condition.
    
- Allow lesson condition changes such as confirmation, delay, cancellation, room move, and completion to be handled in an organised way.
    
- Notify both the teacher and the teaching group when a significant lesson change occurs.
    
- Support the addition of further notification methods in future without redesigning the rest of the timetable model.
    
- Make it clear which classes own or use other objects, including at least the lesson session’s links to subject, teacher, teaching group, time slot, room, current condition, and notification mechanism(s).
    

## Deliverable

Submit one UML class diagram on A4 or A3 paper showing the classes, interfaces, abstract class, inheritance relationships, associations, compositions or aggregations where appropriate, multiplicities, and principal public operations. Keep the model focused on the scenario described