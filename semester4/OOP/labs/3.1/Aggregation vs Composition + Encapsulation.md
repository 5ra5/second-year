
-  **Association (uses-a)**: one object uses another temporarily (no ownership).
-  **Aggregation (weak has-a)**: one object **has** another object, but the contained object can exist independently
-  **Composition (strong has-a)**: one object **owns** another object; the owned object cannot exist independently (lifecycle is tied)

imagine we are developing software for a `printer`:
-  it has `ink`
-  it can print `documents`
-  it must decide whether printing is possible based on its current state

## 1. Understanding the Relationships (Printer + Ink)

### 1.1 Association (uses-a): Printer uses Document

A `Document` can exist independently of any printer. The printer does not "own" the document, it only **uses** it while printing.

-  `Printer.print(document_1)` is a typical usage example
-  If the printer disappears, the document still exists

**Key idea**: document lifecycle does **not** depend on printer

### 1.2 Aggregation (weak has-a): Printer has an InkCartridge

An `ink` cartridge can exist before it is installed, and it can exist after it is removed

-  You can buy a cartridge and keep it in a drawer
-  You can remove a cartridge from the printer and keep it

So in our model:
-  `Printer` **has** a reference to `InkCartidge`
-  but the `InkCartridge` is not “destroyed” when you remove it from the printer

**Key idea**: cartridge lifecycle does **not fully** depend on printer.

### 1.3 Composition (string has-a): Printer owns PrinterConfig (internal component)

To demonstrate **composition** clearly, we'll add a small internal object: `PrinterConfig`

A `PrinterConfig` only makes sense as part of a `Printer`. We will:
- create it **inside** the printer constructor,
- never pass it from outside,
- never allow it to exist on its own in the program.
If the `Printer` object is gone, the config is gone with it.

**Key idea**: config lifecycle depends on printer.

## 2. Why private/public matters here (Encapsulation)

## 2.1 What goes wrong with public fields?

If your fields are `public`, **any** code can break your object rules:

-  set ink to negative:
```java
cartridge.inkLevel = -100;
```

-  set pages to 0:
```java
doc.pages = 0;
```

-  remove a cartridge without using your safe method:
```java
printer.cartridge = null;
```

This creates impossible states and bugs that are hard to track.