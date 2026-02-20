***look at flyweight for grass (factory + container) for the exam***
# scenario: building a game

-  a dynamic background showing a field of grass
-  each piece is moving
-  too many objects (`GrassBlade`)
-  insufficient RAM

every blade of grass = separate object
millions of grass blades across the map

-  just because OOP makes it easy to model reality doesn't mean we should model every blade individually
-  design for scalability, not just correctness
-  RAM cost adds up quickly, especially if we have many objects

# problem

-  colour and sprite consume most of the memory
-  but all grass blades share the same texture and colour

**intrinsic** state (shared): sprite, colour
**extrinsic** state (unique): coordinates, wind vector, `growthRate`

-  we stored *both* inside every `GrassBlade` object
-  massive duplication

# solution - flyweight

-  somewhat of a design pattern
-  making an abstract class, and reusing it for different purposes

1.  keep only intrinsic (shared) state inside the object
2.  pass extrinsic (changing) state from outside (e.g., during draw)
3.  reuse the same shared object across many instances

this reduces RAM usage dramatically (from 21 GB to 32 MB for a million objects in a picture)

**a problem with this**: where do we move the extrinsic state?
-  it is usually moved to the container that holds many objects
-  the problem is that you need to synchronise all of the components, this is complicated if you have more than one type of grass
-  class context helps to solve the problem to an extent

**Option A: "Raw Arrays" in game**
-  separate arrays: `coords[]`, `windVectors[]`, `growthRates[]`, plus `typeRef[]`
-  all arrays must stay in sync (same index = same blade)
-  fast, but error-prone and ugly to maintain

**Option B: context objects (cleaner)**
create small `MovingGrassBlade` (context) that stores:
- extrinsic state + reference to shared `GrassType` (flyweight)
game keeps one array: `MovingGrassBlade[]`

# flyweight factory

using a factory to reuse existing flyweights instead of creating duplicates
input: intrinsic state (e.g. colour + sprite)

factory logic:
-  look up matching `GrassType` in  a pool (or an array)
-  return it if found
-  otherwise create + store + return

## flyweight needs immutability

-  one `GrassType` (flyweight) is reused by many grass instances
-  so its intrinsic state must not change
-  if you do a static class, you can have only one type of grass
-  you can do a final class as well
-  initialise once via constructor
-  no setters, no public mutable fields

otherwise changing one flyweight would unexpectedly affect all blades using it

# structure

**flyweight class** = contains the portion of the original object's state that can be shared between multiple objects

**context class** = contains the extrinsic state, unique across all original objects
-  when a context is paired with one of the flyweight objects, it represents the full state of the original object

**client** = calculates or stores the extrinsic state of flyweights
-  from the client's perspective, a flyweight is a template object which can be configured at runtime by passing some contextual data into parameters of its methods