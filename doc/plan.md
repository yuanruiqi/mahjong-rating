## Rating System

### Plan 1

$$
\Delta R=\frac{x-25000}{a}+(c/d/-e/-f)+\frac{\overline{R}-R}{b}(1)
$$

### Plan 2 (now)

$$
st=2000\\
\Delta dan/kyu=200\\
poly(x)=\frac{x}{10\phi}
$$

$$
\Delta R=\frac{x-25000}{100\pi}+(poly(\overline{R})/\frac{poly(\overline{R})}{e}/-\frac{poly(\overline{R})}{e}/-poly(R))
$$

这里认为 $e=2.718281828459045$，$\pi=3.141592653589793$，$\phi =1.618033988749895$。

段位按照历史最值 rating 计算

### events.txt 格式
若干行，每组表示一局。
每个第一行表示局数 $n$ 和类型 $type$，$type = 3 ~ or ~ 4$。
接下来 $type$ 个数表示参加编号 $id$。
接下来 $n$ 行，每行 $2\times type +1$ 个整数，按照 struct game 的格式输入。

### username.txt 格式
每行一个数字和一个字符串，表示id和姓名

### rating附加
参加场次过少，显示rating有变化。
从 $0$ 开始分别为 $-2000$，$-1000$，$-500$，$-250$，$0$ 。 
