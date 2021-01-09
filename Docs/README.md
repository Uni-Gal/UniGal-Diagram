# 渲染器渲染过程总结

## 综述

渲染一套文件，暂定需要以下几个步骤

1.文件树的构建

2.通过深度广度确定图幅规格

3.绘图

接下来将逐个环节进行分析

## 文件树的构建

首先，所有文件应全部放在同一个文件夹内，并且这个文件夹内不存在与此无关的节点

每个节点对应一个unigal文件（XML文件）

构建树需要遍历整个目录找到文件列表，并以遍历的形式在这些文件中找到开始节点所在的文件。

伪代码如下

```python
def this_file_is_start(i):
    if xpath("node/type/start")>=0:
        return this_node_is_start_i_times
    else:
        return this_node_is_not_start

for i in filelist:
    if this_file_is_start(i)==1:
        search_other_nodes_at(i)
    else:
        do nothing just wait i++
```

因为可能有很多个周目的入口，所以构建一个```vector<node>  start_node_list```来分别操作

在内存中构建一个树，树的每个节点是一个结构体，这个结构体和node中的内容完全一致。每读取一个node，就在内存中的树中创建它。

在第一个周目涉及的节点全部读取完后读取第二周目涉及的节点。

若节点的ID表示这个节点已经读取了，就什么也不做，否则就读取。

这样可以把整个网络全都读取一遍。

之后我们得到了一个头节点的指针。

## 通过深度广度确定图幅规格

图像可以是横向的展示方式（如隐形守护者、墨心），可以是纵向的展示方式（如千恋万花、V’s M）

我们把这个不可滚动的成为广度轴，可以随着时间线滚动的称为深度轴。

纵向展示方式中纵向为深度轴，横向展示方式中横向为深度轴。

深度轴的长度由树的层数来确定，一般数量较大但容易构建。

广度轴的长度需要确定每层最多存在的节点个数，作为总的广度。同时为方便渲染，需要构建```vector<node>  guangdu_list```分别记录每层的广度

通过这两个来计算每个节点绘制的中心位置

## 绘图

根据中心位置和css中设置的节点样式参数，绘制每个节点（画圆画方绘文字，长宽高间和字号）

之后保存输出。这一步可以本地位图buffer去逐像素操作，也可以前端用canvas实现。

## 总结

总之需要一个具有XML解析的功能作为后端（无论是C还是py还是js），一个图像处理作为前端（无论是浏览器化还是native），保存为位图或矢量图。

满足这三点，就可以构建一个UniGal-Diagram的渲染器。

我们正试图使用pugixml和C++开发后端，~~并前后不分离（不来回传数据了好不容易读取了）的用SDL或EasyX或其他直接面向位图操作的库绘制。并最终保存为位图~~现在打算存成SVG了。

## 展望

因为是SVG，所以是支持和[wenyan-lang](https://github.com/wenyan-lang/wenyan)那样直接通过SVG作为输入数据还原成节点格式的可能性的。

可以参考[本文件](https://raw.githubusercontent.com/wenyan-lang/wenyan/827feb62f40c156cb2dc6881544eba1a81ef3551/renders/mandelbrot.svg)作为实例。若要该图像的查看代码需要点击[这里](https://github.com/wenyan-lang/wenyan/blob/master/renders/mandelbrot.svg)

![](https://raw.githubusercontent.com/wenyan-lang/wenyan/827feb62f40c156cb2dc6881544eba1a81ef3551/renders/mandelbrot.svg)

wenyan-lang实现的效果如上所述

不过,就我们的项目而言，如果需要反向转换为Node节点，需要使用[svgpp](https://github.com/svgpp/svgpp)作为支持，【解析】SVG。

当然后端推荐还是使用pugixml，您可以替换成其他xml后端库

不过，就本项目的由数据生成SVG的过程而言，我们没有打算使用其他更复杂的手段，直接用类似cgi的方式硬输出就是可以的。虽然是重复造轮子，但是这个轮子非常小，并且直接使用svgpp这样的svg解析库是写不出这么json风格的XML来的（笑）