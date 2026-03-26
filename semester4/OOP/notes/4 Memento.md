
# memento - behavioural design pattern

-  captures and restores an object's state
-  without exposing internal details
-  undo/rollback/savepoint/snapshots

# why is this a problem?

-  objects have complex internal state
-  external code shouldn't touch internals

**bad options**:
-  expose all fields(break encapsulation)
-  rebuild object manually (error-prone)

-  You either expose all internal details of classes, making them too fragile, or restrict access to their previous state

# solution

(3 classes: originator, memento, caretaker)
originator = original class
memento = keeps snapshot of current state
caretaker = keeps all snapshots

1.  the **originator** class can produce snapshots of its own state, as well as restore its state from snapshots when needed
2.  the **memento** is a value object that acts as a snapshot
3.  the **caretaker** knows not only "when" and "why" to capture the originator's state, but also when the state should be restored (like github)

in this implementation, the memento class is nested inside the originator. this lets the originator access the fields and methods of the memento.

## implementation

```java
public class Editor{
	private String text;
	private int curX;
	private int curY;
	private selectionWidth;
	
	public Snapshot createSnapshot() {
		return new Snapshot(
			this,
			text,
			curX,
			curY,
			selectionWidth,
		)
	}
}
```

```java
// memento separate file
public class Snapshot {
	private final Editor editor;
	private final String text;
	private final int curX;
	private final int curY;
	private final int selectionWidth;
	
	public Snapshot(Editor editor
					String text,
					int curX;
					int curY;
					int selectionWidth) {
					
		this.editor = editor;
		this.text = text;
		this.curX = curX;
		this.curY = curY;
		this.selectionWidth = selectionWidth;
					}
	)
}
```