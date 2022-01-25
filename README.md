## Scene Graph Robot
### Building Involves
Scene Graph <br/>
OpenGL <br/>
GLSL <br/>
GLM
### Implementation
This project is composed of a small scene graph robot and a control panel that contains every node of scene graph. While for this robot, each of the body component corresponds to a node of scene grah. And since the control panel records every part of the robot, it also controls the transformation of nodes, including translation, rotation and scale.
1) For robot display, the nodes are inherient from QTreeWidgetItem and in order for later transformation. These nodes contains shapes, positions and color parameters.
2) For control panel, since nodes are QTreeWidgetItems, it's pretty easy to display them in a tree like structure in widgets. And each items inside widgets can be clicked and perform transmation. And all the changes in transformation would finally be updated and shaded with glsl script.
### Output Display
1) Initial robot and control panel
<p align="center">
  <img src="https://github.com/HarrietKira/Demos-for-Computer-Graphics/blob/main/Scene%20Graph%20Robot/Images/1.png">
</p>

2) Perform Transformation
Click on the widget item and modify the parameters on above, the robot would be updated repectively. <br/>
e.g.1: Rotate Robot Head by 10 Degree <br/>
<p align="center">
  <img src="https://github.com/HarrietKira/Demos-for-Computer-Graphics/blob/main/Scene%20Graph%20Robot/Images/2.png">
</p>

Note that each node are assigned to only one transformation type, and it is only activated by this one particular transformation.