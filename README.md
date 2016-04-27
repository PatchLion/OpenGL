学习OpenGL过程中敲的代码

分为了带Qt的工程和没有Qt的工程，目前暂时还没有写Qt版的例子代码

为了方便写调试或例子程序，简单封装了一个基类CLearnOpenGLBase，子类只需要完成业务上的绘制就可以了<br/>
    1、封装并初始化了OpenGL的一些基本环境<br/>
    2、初始化了简单的坐标线（透视、正视、2D），可隐藏坐标线 <br/>
    3、初始化了相机位置<br/>
    4、增加了一些方便使用的快捷键<br/>
  	&nbsp;&nbsp;&nbsp;[ : 绕-y轴旋转坐标系<br/>
	&nbsp;&nbsp;&nbsp;] : 绕y轴旋转坐标系<br/>
	&nbsp;&nbsp;&nbsp;r : 重置坐标系角度<br/>
	&nbsp;&nbsp;&nbsp;s : 显示/隐藏坐标系<br/>
	&nbsp;&nbsp;&nbsp;q : 透视模式<br/>
	&nbsp;&nbsp;&nbsp;w : 正视模式<br/>
	&nbsp;&nbsp;&nbsp;e : 二维视图<br/>
	&nbsp;&nbsp;&nbsp;0~9 : 增加相应序号快捷值<br/>
	&nbsp;&nbsp;&nbsp;Shift+0~9 : 减少相应序号快捷值<br/>
  
如何增加新的子类：<br/>
&nbsp;&nbsp;&nbsp;继承CLearnOpenGLBase后实现一个新的子类，如果要切换子类，修改TestHeads.h中的宏定义#define CURRENT_CLASS CDrawIcosahedron为新子类的类名就OK
