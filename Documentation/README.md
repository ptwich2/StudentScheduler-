StudentScheduler-
=================

Student Scheduler


README.html to explain how to compile and launch it.

To compile the program and launch the program, open TabApp, and press R while holding down CTRL.



Instructions.html to explain how to actually operate the program once running.


The schedule is broken down into the following:
Create semester/quarter
add the start and end dates the user is attending institution
Default format is: month/day/year (e.g. 08/29/2013)
add and edit the name of term (e.g. “Fall 2013”)
Add classes
add a university name or the abbreviation(e.g. UIC)
after the first time of adding this, the field will be filled with the previous university by default
add a class name or the class id(e.g. CS340)
add the start and end date
after the first time of adding this, this field will be filled with the previous start and end date by default
Customize classes
Details about the class
Lecture/Lab/Discussion
User will be able to specify the newly created class; create folders for lectures, labs and discussions; and perhaps save files (such as hw, etc.)
Time the classes meet
Building in which the classes meet
Room number
Days in which the class is in session
Days can be checkmarked for flexibility
Add Holidays / Vacation / Time Off?
List of scheduled/expired holidays
add a holiday
pull holiday name from local database/collection or create a new holiday
notification options
notification type preferred
when would you like to be notified (i.e. night before holiday, a week before holiday)
on notification, indicate if assignments are due the day after 
edit an existing holiday
delete / edit 




Design.html that describes at a high level the software design of your program. E.g. how have you partitioned the program across files, and how have you designed the C++ classes and why.



event.cpp to track events
home.cpp 
main.cpp 
mainwindow.cpp  controls the whole UI
mynetwork.cpp handles the back end
welcomepage.cpp allows users to login. this is the first screen the user sees
