# UniGal-Diagram
Offer a visuable way to switch and show the different possibility of a Galgame

## UniGal-Diagram Simple

Draw your diagram which in your mind!

![](https://raw.githubusercontent.com/Uni-Gal/UniGal-Render/bc571f5faf44f0305bd190c82af16535987473c1/Simple/Simple_HelloWorld/Diagram_simple_SVG.svg)

## UniGal-Diagram的定位

目前，很少有游戏有成熟的流程图，想起流程图，大部分人想起来的是柚子社的游戏，或者是最近刚刚出的Vampire's Melody这样的作品，或者是WILL美好世界/被封锁的涩谷这样的明确要求世界线的作品。

有不少玩家试图用思维导图的方式来描述游戏攻略，但是发现对于flag判定或好感度无法用单纯的跳转逻辑来解决，而流程图又存在许多根据具体游戏引发的变数。很多纯文本的游戏攻略动辄加入非常多的```SAVE01```这样的字眼，很难搞清楚具体的分歧点在何处，对值的判定如何。

国内试图引入流程图概念的Galgame引擎，目前笔者所见的只有AA社自有框架与Nova，并只有AA社真正做出来了，但依然存在诸多如较为繁琐和性能优化不佳的缺点

UniGal-Diagram的目标，正是构建一套能描述绝大多数Galgame的游戏进程的语言，从最简单的视觉小说，到多结局多世界线纵横交织的复杂游戏，我们试图抽象出一套最基本的数据结构，来方便大家描述和生成流程图，来方便玩家制作可视化而又易于理解的游戏攻略。

它将既面向开发者，也面向有一定计算机科学基础了解的评测型玩家。

此外，Diagram也因其功能性和基于普适性的数学原理引申，一定程度上也可以用于非Galgame的流程图。因此，我们鼓励并欢迎其他领域的开发者使用它辅助和减轻自己的作图问题。UniGal-Diagram也将在一定程度上对普适性做出调整及引入更多作图的style风格等。

## UniGal-Diagram技术细节

1.UniGal-Diagram并未完全遵循基本的流程图的形式，如它可以有多个开始点，分别对应不同的周目，它可以不必有IO节点等。

它对flag/好感变量的操作均理解为对全局变量的操作，它所有的块均为同样的节点，因此我们不进行形状上的划分，而仅在前端渲染的时候表示出他的不同来。

2.为了保证通用，他的数据结构定义是通用的，需要根据不同的环境来写不同的渲染器，比如DiagramForUnity或者DiagramForOthers

3.允许线与线的交叉

4.UUID用UUID5这样的基于hash的是最好，但是如果要现场生成我也不反对。不过在技术力不够的时候直接name判定也可以

5.即日起，UniGal的给电脑看的需要展示出来的注释用```<comment></comment>```封装，给人看的纯粹开发的时候方便了解是啥的，今后统一用```<!-- {{comment_content}} -->```写，就不要暴露出来给解析脚本的时候添麻烦了。已有的存量代码逐步实行更改。

6.Arrow并非官方维护的一份文档，只是用于给不使用官方render，而需要以diagram进行二次开发的第三方开发者使用。