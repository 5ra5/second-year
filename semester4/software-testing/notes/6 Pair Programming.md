
-  two people performing one programming task concurrently, while seated together at one computer

official definition from the Agile Alliance:
Pair programming consists of two programmers sharing a single workstation (one screen, keyboard and mouse among the pair). The programmer at the keyboard is usually called the "driver", the other, also actively involved in the programming task but focusing more on overall direction is the "navigator"; it is expected that the programmers swap roles every few minutes or so.

driver = has the main role in terms of coding, focused on programming
navigator = trying to think of the problem more holistically (how to get from point A to point B - thinking about the bigger picture)

## benefits

-  Two people working on problem solving and two minds can be better than one single mind.
-  Instant testing and reviewing as a second person is overseeing the work, asking questions and making suggestions for improvements.
-  Defect removal (a study suggests 15% quality improvement, but that pair programming is 15% more costly!)
-  Shown to be effective in programming educational environments.
-  Shown to be faster because 2 people solve problems quicker.
-  Seniors and junior developers swap roles in companies in order for the project to work.

Less obvious benefits:
-  When implemented correctly, potentially increased peer pressure to perform (e.g. surfing the net and checking email is not so easy when someone is sitting alongside you and checking your work)
-  Increased socialising among the team can increase overall team performance
-  Knowledge sharing and training
-  Reduced overall coordination effort (1/2 as many programming tasks at any time)

navigators = act as immediate testers (asking questions)
drivers = coding out loud, explaining to the navigator what are you currently doing

## issues

-  both programmers must be actively engaging with the task throughout a paired session, otherwise no benefit can be expected
-  at least the driver, and possibly both programmers, are expected to keep up a running commentary; i.e. "programming out loud" - if the driver is silent, the navigator should intervene
-  pair programming cannot be fruitfully forced upon people, especially if relationship issues, including the most mundane (such as personal hygiene), are getting in the way; solve these first!

Grades of noise:
-  Some programmers have a propensity for chitchat, focus must be on the programming task otherwise it is not pair programming, it is pair chitchatting. 
-  Some programmers talk too loud and distract other pair programmers, it is important to moderate the volume. 
-  One of the pair do not engage, freeloading.
-  No noise at all is just as concerning. 

## ping-pong testing

more frequent switching of roles: one driver programmer writes a failing unit test, then passes the keyboard to the other who writes the corresponding code, then goes on to a new test
-  pair programming using a test driven development

This variant can be used purely for educational purposes.