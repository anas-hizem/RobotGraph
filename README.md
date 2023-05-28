# RobotGraph
This robot is capable of finding the end of a non-cyclic line maze, calculating the shortest path from the start point to the end point, and then driving that shortest path.
 ## Components
 1.Arduino Uno
 https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Arduino_Uno_-_R3.jpg/220px-Arduino_Uno_-_R3.jpg
 2.H-bridge
 3.Motors
 4.Lipo
 5.TCRT5000
 6.LCD SCREEN
 ## Algorithm
 to solve the maze, the robot may use two algorithms :
 ### Left Hand Rule 
 For this presentation, the robot will always use the left hand rule, which means:
 1- Always prefer a left turn over going straight ahead or taking a right turn.
 2- Always prefer going straight over going right.
 If the maze has no loops, this will always get you to the end of the maze.
 ### Right Hand Rule 
 The right hand rule is just the opposite:
 1- Always prefer a right turn over going straight ahead or taking a left turn
 2- Always prefer going straight over going left.
 If the maze has no loops, this will always get you to the end of the maze
 
 ## The 8 possibilities
 Given a maze , there are only 8 possible situations that the robot can encounter :
 
 ## Main algorithm 
 • In order to solve the maze, the robot needs to traverse the maze twice.
 • In the first run, it goes down some number of dead-ends, but records these as “bad” paths so that they can be avoided on the second run.
 ### FIRST RUN 
  The robot will save the path in a string .
  for example: PATH="FLLFDFRLS"
  • If the robot go forward : PATH +="F"
  • If the robot go left : PATH +="L"
  • If the robot go right : PATH +="R"
  • If the robot find a dead end : PATH +="D"
  • If the robot finish : PATH +="S"
 ### SECOND RUN 
  • The robot calculates the shortest way after applying a graph algorithm to PATH.
