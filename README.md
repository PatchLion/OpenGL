学习OpenGL过程中敲的代码

2015-4-20</br>
分为了带Qt的工程和没有Qt的工程，目前暂时还没有写Qt版的例子代码

为了方便写调试或例子程序，简单封装了一个基类CLearnOpenGLBase，子类只需要完成业务上的绘制就可以了<br/>
    1、封装并初始化了OpenGL的一些基本环境<br/>
    2、初始化了简单的坐标线（透视、正视、2D），可隐藏坐标线 <br/>
    3、初始化了相机位置<br/>
    4、增加了一些方便使用的快捷键<br/>
    &nbsp;&nbsp;&nbsp;"1"-透视<br/>
    &nbsp;&nbsp;&nbsp;"2"-正视<br/>
    &nbsp;&nbsp;&nbsp;"3"-2D<br/>
    &nbsp;&nbsp;&nbsp;"["-绕Y轴左旋<br/>
    &nbsp;&nbsp;&nbsp;"]"-绕Y轴右旋<br/>
    &nbsp;&nbsp;&nbsp;"c"-显示隐藏坐标线<br/>
    &nbsp;&nbsp;&nbsp;"r"-重置旋转角度<br/>
  
  
如何增加新的子类：<br/>
&nbsp;&nbsp;&nbsp;继承CLearnOpenGLBase后实现一个新的子类，如果要切换子类，修改TestHeads.h中的宏定义#define CURRENT_CLASS CDrawIcosahedron为新子类的类名就OK
