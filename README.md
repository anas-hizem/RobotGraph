# RobotGraph

This robot is capable of finding the end of a non-cyclic line maze, calculating the shortest path from the start point to the end point, and then driving that shortest path.

## Components

1. **Arduino Uno**  
   ![Arduino Uno](https://github.com/Anashizem/RobotGraph/assets/120311351/51f79232-c8c2-453e-a3ed-feaf29eaf206)

2. **H-Bridge**  
   ![H-Bridge](https://github.com/Anashizem/RobotGraph/assets/120311351/69032a0b-0231-4b54-acef-f8658e3c2a38)

3. **Motors**  
   ![Motors](https://github.com/Anashizem/RobotGraph/assets/120311351/efa84a83-2475-475d-acf1-e30108dfb749)

4. **LiPo Battery**  
   ![LiPo](https://github.com/Anashizem/RobotGraph/assets/120311351/01b5f078-9d81-409b-992d-b93c94ba8543)

5. **TCRT5000 Sensors**  
   ![TCRT5000](https://github.com/Anashizem/RobotGraph/assets/120311351/e360237c-6451-49fa-9854-f9fb064bb6bd)

6. **LCD Screen**  
   ![LCD Screen](https://github.com/Anashizem/RobotGraph/assets/120311351/406c8bda-d099-4cbe-9e53-3fe554caca26)

## Algorithm

To solve the maze, the robot may use two algorithms:

### Left Hand Rule
For this implementation, the robot always uses the left-hand rule, which means:
1. Always prefer a left turn over going straight ahead or taking a right turn.
2. Always prefer going straight over going right.

If the maze has no loops, this will always lead to the end of the maze.

### Right Hand Rule
The right-hand rule is just the opposite:
1. Always prefer a right turn over going straight ahead or taking a left turn.
2. Always prefer going straight over going left.

If the maze has no loops, this will also lead to the end of the maze.

## The 8 Possibilities

Given a maze, there are only 8 possible situations that the robot can encounter:  
![The 8 Possibilities](https://github.com/Anashizem/RobotGraph/assets/120311351/b68e7192-f155-49d7-81e0-539488577014)

## Main Algorithm
To solve the maze, the robot needs to traverse the maze twice.

### First Run
- The robot will save the path in a string.  
  For example: `PATH = "FLLFDFRLS"`
  - If the robot goes forward: `PATH += "F"`
  - If the robot goes left: `PATH += "L"`
  - If the robot goes right: `PATH += "R"`
  - If the robot finds a dead end: `PATH += "D"`
  - If the robot finishes: `PATH += "S"`

### Second Run
- The robot calculates the shortest way after applying a graph algorithm to `PATH`.

## Conclusion

This robot maze solver showcases the combination of hardware and algorithmic design to autonomously navigate through complex environments. With the left-hand and right-hand rules implemented, the robot demonstrates fundamental principles of maze solving and pathfinding.

Feel free to explore the repository for code, schematics, and further documentation!
