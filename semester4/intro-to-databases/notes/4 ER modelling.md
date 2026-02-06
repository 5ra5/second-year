**quiz next week**
relational models and relational algebra
15 questions, 20 minutes
starts 11:05

**essential for CA2** - you will mostly use binary relationships, sometimes ternary (there is a way to simplify from ternary to binary)

# introduction

case study: company modelling
4 entities, 4 basic building blocks of a company: employee, department, project, dependent

# entities

## entities and attributes

- The basic object that the ER model represents is an entity, which is a thing in the real world with an independent existence.
-  An entity may be an object with a physical existence (for example, a particular person, car, house, or employee),
-  or it may be an object with a conceptual existence (for instance, a company, a job, or a university course).

## attributes

-  Each entity has attributes: the particular properties that describe it.
-  For example, an EMPLOYEE entity may be described by the employee’s name, age, address, salary, and job.
-  A particular entity will have a value for each of its attributes.
-  The attribute values that describe each entity become a major part of the data stored in the database.

## composite vs simple (atomic) attributes

-  Composite attributes can be divided into smaller subparts, comprising attributes with independent meanings.
-  For example, the Name attribute of the EMPLOYEE entity is subdivided into `Fname`, `City`, `Minit`, and `Lastname`.
-  Attributes that are not divisible are called simple or atomic attributes.
-  Composite attributes can form a hierarchy: `Street_address` can be further subdivided into three simple component attributes: `Number`, `Street`, and `Apartment_number`.

## single-valued vs multivalued attributes

-  Most attributes have a single value for a particular entity; such attributes are called single-valued.
-  A multivalued attribute may have lower and upper bounds to constrain the number of values allowed for each individual entity

## stored vs derived attributes

-  for example, if we have a birth date attribute, it's a stored attribute, but from that we can conclude the age attribute, so that would be a derived attribute

## NULL values

-  In some cases, a particular entity may not have an applicable value for an attribute
-  For example, a College_degrees attribute applies only to people with college degrees
-  For such situations, a special value called NULL is created.
-  NULL can also be used if we do not know the value of an attribute for a particular entity 

## entity types and entity sets

-  A database contains groups of entities that are similar
-  if we have a student table, and we have multiple student, and combining all students together form an entity type
-  For example, employee entities share the same attributes, but each entity has its own value(s) for each attribute.
-  An entity type defines a collection (or set) of entities that have the same attributes.
-  Each entity type in the database is described by its name and attributes

## entity sets

-  The collection of all entities of a particular entity type in the database at any point in time is called an entity set
-  EMPLOYEE refers to both a type of entity and the entire set of employee entities in the database.

## entity types

-  An entity type is represented as a rectangular box enclosing the entity type name.
-  Attribute names are enclosed in ovals and attached to their entity type by straight lines.
-  Composite attributes are attached to their component attributes by straight lines.
-  Multivalued attributes are displayed in double ovals

## Data (extension) and Data Structure (intension)

-  An entity type describes the schema or intension for a set of entities that share the same structure
-  The collection of entities of a particular entity type is grouped into an entity set, which is also called the extension of the entity type.

## Key Attributes of an Entity Type

-  An important constraint on entities is the key or uniqueness constraint on attributes.
-  An entity type usually has one or more attributes whose values are distinct for each individual entity.
-  Such an attribute is called a key attribute, and its values can be used to identify each entity uniquely.
-  The Name attribute is a key of the COMPANY entity type because no 2 companies can have the same name.

-  Sometimes several attributes form the key: the combination of attribute values must be distinct.
-  composite key must be minimal: all component attributes must be included in the composite attribute to have the uniqueness property
-  Superfluous attributes must not be included in a key.

## key constraints

-  Some entity types have more than one key attribute
-  here is no concept of primary key in the ER model: it’s a relational model concept!

# relationships

-  There are several implicit relationships among the various entity types.
-  whenever an attribute of one entity type refers to another entity type, some relationship exists
-  in the ER model, these references should not be represented as attributes but as relationships. 

## Relationship Types, Sets, and Instances

-  A relationship type R among n entity types E1, E2, ..., En defines a set of associations (a relationship set) among entities from these entity types.
-  As with entity sets, a relationship type and its corresponding relationship set are referred to by the same name, R.
-  Each relationship instance ri in R is an association of entities, where the association includes exactly one entity from each participating entity type

## Relationship Types in the ER Model

-  Relationship types are displayed as diamond-shaped boxes, which are connected by straight lines to the rectangular boxes representing the entity types.
-  The relationship name is displayed in the diamond-shaped box.

## degree of a relationship type

-  The degree of a relationship type is the number of participating entity types.
-  A relationship type of degree two is called binary, and one of degree three is called ternary
-  Relationships can generally be of any degree, but the ones most common are binary relationships.

## Constraints on Binary Relationship Types

-  Relationship types have constraints that limit the possible combinations of entities that may participate in the relationship.
-  There are 2 main types of binary relationship constraints: cardinality ratio and participation.
-  The cardinality ratio for a binary relationship specifies the maximum number of relationship instances that an entity can participate in
-  For relationship type DEPARTMENT: EMPLOYEE is of cardinality ratio 1:N, meaning that each department employs any number of employees, and any employee can work for only one department.
-  Here, N indicates there is no maximum number.
-  On the other hand, an employee can be related to a maximum of 1 department.
-  **different cardinalities**: possible cardinality ratios for binary relationship types are 1:1, 1:N, N:1, and M:N.

## Participation Constraints and Existence Dependencies

-  The participation constraint specifies whether the existence of an entity depends on its being related to another entity via the relationship type.
-  This constraint specifies the minimum number of relationship instances that each entity can participate in, called the minimum cardinality constraint.
-  There are two types of participation constraints: total and partial.

## total participation

-  also called existence dependency
-  If every employee must work for a department, then an employee entity can exist only if it participates in at least one WORKS_FOR relationship instance.
-  Thus, the participation of EMPLOYEE in WORKS_FOR is called total participation, meaning that every employee entity must be related to a department entity through WORKS_FOR.
-  We refer to cardinality ratio and participation constraints as structural constraints of a relationship type.

