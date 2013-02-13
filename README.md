code-collection
===============

A Collection of Code Fragments and Code Frameworks for Language C Lisp and Shell

从过去的经验看来，每次写代码都要参照之前写过的代码，例如结构体怎么设计、变量取什么名、那个变量什么类型好。更多情况是为了追寻统一的风格比如C要写成K&R型的，并且遵循硬件资源最省，比如sunner曾提及过：

for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
        num[i][j] = 0;

与

for (j = 0; j < n; ++j)
    for (i = 0; i < n; ++i)
        num[i][j] = 0;

的复杂度虽然一样，但耗费的时间和资源仍然相差非常大，这是因为CPU的内存分页管理的缘故。类似的考虑还有很多，比如方便快速回忆起一个算法的第一行怎么写等等。所以为了每次都写出最好质量的代码，每次代码质量都提升，需要对核心代码片段或者框架进行入库管理。公开库Github、私人库Bitbucket、本地库同时管理，形成代码仓库冗余阵列。

分别针对三种语言：

* C语言：严格结构化编程，代码习惯与编程思想以《The C Programming Language》为准。
* Lisp语言：严格函数性编程，代码习惯与编程思想以《ANSI Common Lisp》为准，除非标准代码上面使用，自己不以任何方式使用LOOP、DO、DOLIST等循环结构。尽量形成宏模板。
* Shell语言：脚本语言变成方式，代码风格灵活。

针对每一个基本算法，形成一个代码。基本算法选取规则：

* 针对C语言：
  首先来自《The C Programming Language》
  补充来自《The Practice of Programming》（标准代码详见：http://cm.bell-labs.com/cm/cs/tpop/code.html）
  最后实现《Introduction to Algorithms》中所有算法

* 针对Lisp语言：
  首先来自《ANSI Common Lisp》
  补充来自《Structure and Interpretation of Computer Programs》（原版详见：http://mitpress.mit.edu/sicp/full-text/book/book.html，标准代码详见：http://mitpress.mit.edu/sicp/code/index.html） 及John McCarthy的相关论文
  最后实现《Introduction to Algorithms》中所有算法

* 针对Shell语言：
  首先来自《Advanced Bash-Scripting Guide》
  补充来自其他应用场合