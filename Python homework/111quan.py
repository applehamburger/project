
# coding: utf-8

# In[ ]:


#新列表 倒序列表3.21
#定义一个reverse(s)函数，功能是返回列表s的倒序列表。如输入[1,2,3,4]则输出[4,3,2,1]
s=input()
def reverse(s):
    if len(s)<=1:
        return s
    else:
        return s[::-1]
print(reverse(s))

#写函数，可将两个相同长度的list，间隔插入，生成并返回一个新的list。
#例如：给两个list，a=[1,2,3,4], b=[5,6,7,8]。则可以生成：[1,5,2,6,3,7,4,8]
#间隔生成列表3.21
def merge_lists(a, b):
    """
    将两个相同长度的list，间隔插入，生成并返回一个新的list。
    :param a: 第一个list
    :param b: 第二个list
    :return: 生成的新list
    """
    result = []
    for i in range(len(a)):
        result.append(a[i])
        result.append(b[i])
    return result


#写一组函数，输入一组整形数，构成列表。返回列表的最大值，最小值，平均值。
#列表最大最小值及均值3.21
def my_max(lst):
    max_num = lst[0]
    for num in lst:
        if num > max_num:
            max_num = num
    return max_num

def my_min(lst):
    min_num = lst[0]
    for num in lst:
        if num < min_num:
            min_num = num
    return min_num

def my_mean(lst):
    sum_num = 0
    for num in lst:
        sum_num += num
    mean_num = sum_num / len(lst)
    return mean_num

lst = []
n = int(input("请输入整数个数："))
for i in range(n):
    num = int(input("请输入第{}个整数：".format(i+1)))
    lst.append(num)
max_num = my_max(lst)
min_num = my_min(lst)
mean_num = my_mean(lst)
print("列表的最大值为：", max_num)
print("列表的最小值为：", min_num)
print("列表的平均值为：", mean_num)



#写函数，求n个随机整数均值的平方根，整数范围在m与k之间（n,m,k由用户输入），要求用for循环。
#随机求平方根3.20
import random
def mean_sqrt(n, m, k):
    n = int(input("请输入随机整数个数："))
    m = int(input("请输入随机整数范围下限："))
    k = int(input("请输入随机整数范围上限："))
    lst = [random.randint(m, k) for i in range(n)]  # 生成n个随机整数的list
    mean = sum(lst) / n  # 计算均值
    sqrt_mean = mean ** 0.5  # 计算均值的平方根
    return sqrt_mean



#在课上猜数游戏的基础上增加功能：

#用户猜糊涂了，输入越界的guess（比如说应该猜20-30，结果用户说了15），对这种行为进行提示：guess_number()的分支语句里记录提示

#猜数游戏3.21
import random
def guess_number():
    guess_times = 0
    guess_range = (20, 30)
    target_number = random.randint(*guess_range)
    while True:
        guess = input("请输入{}到{}之间的整数：".format(*guess_range))
        if not guess.isdigit():
            print("输入错误，请输入整数！")
            continue
        guess = int(guess)
        if guess < guess_range[0] or guess > guess_range[1]:
            print("猜测越界，请输入{}到{}之间的整数！".format(*guess_range))
            continue
        guess_times += 1
        if guess < target_number:
            print("猜小了！")
        elif guess > target_number:
            print("猜大了！")
        else:
            print("恭喜你，猜对了！你猜了{}次。".format(guess_times))
            break
guess_number()


#猜数游戏1.0  3.14
import random
while 1:
    i = 0
    num = random.randint(1,100)
    while i < 5:
        i +=1
        guess = int (input ("请输入你猜的数字："))
        if guess == num:
            print("您猜对了！")
            break
        if i==5:
            print("game over")
        elif num > guess:
            print("猜小了！")
        elif num < guess:
            print("猜大了！")
    n=int(input("结束游戏请输入0,再来一局请输入1"))
    if n==0:
        break

        
#请用编写函数的方式，写“关于数字的一切”答复机：

#用户输入一个正整数N，和一个菜单命令（如字母），程序可以答复（显然每个功能是一个函数）：

#1）N是什么类型

#2）N是不是质数

#3）从1累加到N的和是多少（包括1和N）

#4）从1累乘到N的积是多少（包括1和N）

#5）N是奇数还是偶数

#6）输出帮助信息        
#关于整数的一切
N = int((input ("请输入一个数字：")))
def sm():
    print ("A功能：给出N的数据类型")
    print ("B功能：给出N是否为质数")
    print ("C功能：求1至N的累加")
    print ("D功能：求1至N的阶乘")
    print ("E功能：给出N的奇偶")
sm()
F = (input("请输入功能ABCDE中的一个："))
if F == "A":
    lx(N)
if F == "B":
    zs(N)
if F == "C":
    he(N)
if F == "D":
    jc(N)
if F == "E":
    jo(N)
def lx(n):
    print(n,"为",type(n))
def zs(n):
    i = 2
    if n ==1:
        print (n,"不是质数")
    else :
        while i <= n - 1:
            if n % i == 0:
                break
            i += 1
        if i >= n:
            print (n,"是质数")
        else:
            print (n,"不是质数")
def he(n):
    i = 0
    num = 0
    while i < n:
        i += 1
        num += i
    print ("1至N的累加结果为：",num)
def jc(n):
    i = 0
    num = 1
    while i < n:
        i += 1
        num *= i
    print ("1至N的阶乘结果为：",num)
def jo(n):
    if n % 2 != 0:
        print (n,"是奇数")
    else:
        print (n,"是偶数")



# 编写连乘函数lc，实现正整数n到m的连乘（用户输入m和n，且m>n），并计算lc(1,50)+lc(2,50)+lc(3,50)...lc(49,50)的结果。       
#连乘诀 3.13
n=int(input("请输入起始数n："))
m=int(input("请输入终止数m："))
def lc(n,m):
    j=1
    while n<m:
        j=j*n
        n=n+1
    return(j)
if n==1 and m==50:
    sum=0
    while n<m:
        sum=sum+lc(n,m)
        n=n+1
    print("lc(1,50)+lc(2,50)+lc(3,50)...lc(49,50)最终结果：",sum)

    
    
    
'''''' 编写一个为小学生家长自动出算数题的代码，题目数量用户指定，要求

a运算数均小于100

b加减乘的结果为0-100的整数，除法需要整除

c四种运算题目数量随机出现

d请也给出各题答案  '''''' 
  #给家长随机出题 3.12
import random
n=int(input("请指定题目数量："))
i=0
j=0
while i<n:
    a=random.randint(0,100)
    b=random.randint(0,100)
    c=random.choice('+-*/')
    if c=='+'and (a+b)>0 and (a+b)<100: 
        print(a,'+',b,'=',a+b)
        i+=1
    if c=='-' and (a-b)>0 and (a-b)<100: 
        print(a,'-',b,'=',a-b)
        i+=1
    if c=='*' and (a*b)>0 and (a*b)<100: 
        print(a,'*',b,'=',a*b)
        i+=1
    if c=='/'and a!=0 and (a%b)==0: 
        print(a,'/',b,'=',a/b)
        i+=1
  




  #下载《解放思想，实事求是，团结一致向前看》，利用jieba进行分词和词性标注。

#找出动词（v）后面有多于两个词的情况，并按照从高到低输出词性组合的频次表。如：

#v a n: 1000

#v a d: 959

#……
 #with open('D:\\360安全浏览器下载\\解放思想，实事求是，团结一致向前看（邓小平）.txt', 'r', encoding='utf-8') as f:
    content = f.read()
import jieba.posseg as pseg
words = pseg.cut(content)
freq = {}
for word, flag in words:
    if flag.startswith('v'):
        next_word = next(words, None)
        if next_word:
            next_flag = next_word.flag
            next_next_word = next(words, None)
            if next_next_word:
                next_next_flag = next_next_word.flag
                pos = '{} {} {}'.format(flag, next_flag, next_next_flag)
                freq[pos] = freq.get(pos, 0) + 1
# 按照频次从高到低输出词性组合的频次表
for pos, count in sorted(freq.items(), key=lambda x: x[1], reverse=True):
    print('{}: {}'.format(pos, count))

    
 


               
               
               
              #请使用dict结构统计199801.txt中分词单元的频率，

（1）输出频率最高的20个词（带着词性符号，标点等也算词）。

（2）输出频率最高的20个名词（词性符号为n，带着词性符号）。

（3）输出频率最高的20个成语（词性符号为i，带着词性符号）。
               
wl=open(r'199801.txt',encoding='utf-8').read().split(' ')
wf={}
for i in wl:
    if i in wf:
        wf[i]+=1
    else:
        wf[i]=1
        
wfs=sorted(wf.items(),key=lambda d:d[1],reverse=True)
print(wfs[:20])


s=[]
if i=='n':
    s.append(i)
wf={}
for i in s:
    if i in wf:
        wf[i]+=1
    else:
        wf[i]=1
        
wfs=sorted(wf.items(),key=lambda d:d[1],reverse=True)
print(wfs[:20])


a=[]
if i=='i':
    a.append(i)
wf={}
for i in a:
    if i in wf:
        wf[i]+=1
    else:
        wf[i]=1
        
wfs=sorted(wf.items(),key=lambda d:d[1],reverse=True)
print(wfs[:20])

               
               
               
#写函数，计算二十大报告英文版的词表，即不重复的词的列表。使用集合。并告知集合长度。               
file= "C:\Users\lenovo\Downloads\20ReportEng.txt"
f= open(file,encoding="utf-8")
T= f.read()
f.close()

def to(T):
    l1=[]
    l1=T.split(' ')
    l2=('\n'.join(l1))
    t=[]
    t=l2.split('\n')
    word=[]
    for i in t:
        if i not in word:
            word.append(i)
    j=0
    words = {c for c in word}
    for c in words:
        j+=1
    return j

print(to(T))

               
               
               
               #写函数，分别生成十九大报告英文版和二十大报告英文版的非重复词表。计算：

（1）两个词表的交集和交集分别占两个词表的比例。

（2）两个词表的对称差集占两个词表并集的比例。

（3）两个词表的对称差集中最高频的五个词分别是？
file1= "C:\Users\lenovo\Downloads\20ReportEng.txt"
f1= open(file1,encoding="utf-8")
T1= f1.read()
f1.close()

file2="C:\Users\lenovo\Downloads\19ReportEng.txt"
f2= open(file2,encoding="utf-8")
T2= f2.read()
f2.close()

def list(T):
    l1=[]
    l1=T.split(' ')
    l2=('\n'.join(l1))
    t=[]
    t=l2.split('\n')
    word=[]
    for i in t:
        if i not in word:
            word.append(i)
    return word

w1={i for i in list(T1)}
w2={j for j in list(T2)}

wj= w1 & w2
print(len(wj)/len(T1))
print(len(wj)/len(T2))

wd=w1^ w2

wb=w1|w2
print(len(wd)/len(wb))


f1=[]
f2=[]
for i in wd:
    if i in T1:
        f1.append(i)
    if i in T2:
        f2.append(i)
#产生词频表
def freq(l,T):
    words=[]
    for c in l:
        for k in words:
            if c==k[0]:
                k[1]+=1
                break
        else:
            words.append([c,1])
    for i in list(T1):
        for j in words:
            if i==j[0]:
                j[1]+=1
                break
    return words

c1=freq(f1,T1)
c2=freq(f2,T2)
#排序
def bubble_sort(lst):
    n = len(lst)
    for i in range(n-1):    
        flag = False
        for j in range(n - 1 - i):
            if lst[j][1] > lst[j + 1][1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
                flag = True
        if not flag: 
            break
    return lst[:5,-1]

print(bubble_sort(c1))
print(bubble_sort(c2))

