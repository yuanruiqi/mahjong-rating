## Rating System

### Plan 1

$$
\Delta R=\frac{x-25000}{a}+(c/d/-e/-f)+\frac{\overline{R}-R}{b}(1)
$$

### Plan 2

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

### Plan 3
- 1位头名赏：$S=15$
- 4(末)位扣分：$D=\max(0,\frac{(r_4-1400)}{60})$。
- 顺位马：$+15 +5 -5 -15/+20 0 -20$
- 点数：$f_i=\frac{s_i-\bar{s}}{800}$
- 基本rating delta $rd_i=f_i$+顺位马 -（4(末)位扣分）
- 期望顺位 $p_i=\sum \frac 1 {1+2^{(r_i-r_j)/300}}+1$
- 顺位差 $g_i$= 期望顺位-实际顺位 $\in [-3,3]$
-  若 $rd_i>0$，rating delta  =  $rd_i \times {1+\frac 5 3 g_i}$+（1位头名赏）
- 若 $rd_i<0$，rating delta  =  $rd_i \times {1-\frac 5 3 g_i}$+（1位头名赏）
- 考虑到一些实际情况，最终变化量会 *1.5

## Plan 4
这个方案来自deepseek

ΔR_i = 顺位基础分 + 点数修正项 + 均值补偿项 + 末位惩罚项

---

- 1位：+35
- 2位：+5
- 3位：-10
- 4位：-30

对于3麻：
- 1位：+30
- 2位：0
- 3位：-30

点数修正项 = (终局点数 - 初始点数) × 0.0005  

均值补偿项 = 0.04 (期望平均Rating - 当前平均Rating)  
（注：期望平均Rating为2100，当前平均Rating为四人Rating的平均值）

- 如果玩家Rating ≤ 1900，末位惩罚项 = 0  
- 如果玩家Rating > 1900，末位惩罚项 = (Rating - 1900) × 8%  
（注：仅对末位玩家生效）



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
