-  usually unseen, implemented as a class
-  behavioural design pattern - defines the behaviour between classes
-  lets you define a subscription mechanism to notify multiple objects about any events that happen to the object they’re observing

create a special interface called Subscribers - they want to know a specific things
a Publisher is someone that manages all the Subscribers

publisher has a list of all subscribers

instead of inserting additional information into each object, we create something like an interface
-  when an event occurs, the publisher notifies all subscribers by calling their notification method

**challenge**: real applications may have many different subscriber types and the publisher shouldn't be tightly coupled to them

**solution**: all subscribes implement the same interface
-  declares a notification method with parameters, allowing the publisher to pass relevant data without knowing the subscriber's internal details
-  loose coupling = flexible & scalable design

## structure

Publishers contain a subscription infrastructure that lets new subscribers join and current subscribers leave the list.

When a new event happens, the publisher goes over the subscription list and calls the notification method declared in the subscriber interface on each subscriber object

The Subscriber interface declares the notification interface. In most cases, it consists of a single update method. The method may have several parameters that let the publisher pass some event details along with the update

Concrete Subscribers perform some actions in response to notifications issued by the publisher. All of these classes must implement the same interface so the publisher isn’t coupled to concrete classes.

The Client creates publisher and subscriber objects separately and then registers subscribers for publisher updates

Usually, subscribers need some contextual information to handle the update correctly. For this reason, publishers often pass some context data as arguments of the notification method. The publisher can pass itself as an argument, letting subscriber fetch any required data directly.

the Observer pattern lets the text editor object notify other service objects about changes in its state.

In this implementation, the editor class doesn’t maintain the subscription list by itself. It delegates this job to the special helper object devoted to just that.