###Lecture Notes###

[Lecture 6: C++ Inheritance (PDF)](http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-s096-introduction-to-c-and-c-january-iap-2013/lectures-and-assignments/c-inheritance/MIT6_S096_IAP13_lec6.pdf)

#Assignment 6#

[rps (CPP)](http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-s096-introduction-to-c-and-c-january-iap-2013/lectures-and-assignments/c-inheritance/rps.cpp)

In the file rps.cpp, implement a class called Tool. It should have an int field called strength and a char field called type. You may make them either private or protected. The Tool class should also contain the function void setStrength(int), which sets the strength for the Tool.

Create 3 more classes called Rock, Paper, and Scissors, which inherit from Tool. Each of these classes will need a constructor which will take in an int that is used to initialize the strength field. The constructor should also initialize the type field using 'r' for Rock, 'p' for Paper, and 's' for Scissors.

These classes will also need a public function bool fight(Tool) that compares their strengths in the following way:

Rock's strength is doubled (temporarily) when fighting scissors, but halved (temporarily) when fighting paper.
In the same way, paper has the advantage against rock, and scissors against paper.
The strength field shouldn't change in the function, which returns true if the original class wins in strength and false otherwise.
You may also include any extra auxiliary functions and/or fields in any of these classes. Run the program without changing the main function, and verify that the results are correct.
```
$ g++ -Wall rps.cpp -o rps
$ ./rps
<your test output>
```

###Solutions###

Solutions are not available for this assignment.
