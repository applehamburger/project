# 作业讲解

# 生成器
'''
在循环迭代列表等对象时，列表所有数据都需要在内存中加载，如果有数据很大则占了很大内存。
一般访问前/后，所访问的数据可能就没什么用了。
如果迭代元素能仅在每次迭代的时候提供（生成），不必创建完整的列表
就可以节省大量的空间。
python提供了一个解决方案：生成器！
生成器是一个按需生成数据的可迭代对象
'''
# 创建生成器-1
# 生成器推导（注意得到的不是元组）
nums = (i for i in range(15))  
# 如果用nums = [i for i in range(15)] 则nums占用15个内存空间
print(nums)

print(next(nums))
print(next(nums))
print(nums.__next__())
print(list(nums))
for i in nums:
    print(i)

print(next(nums))   # 生成完毕再调用next会报错
# 生成器使用
# 1：for循环，形式上与普通的list等类似
# 2：next()函数，每次从生成器中生成一个对象
# 3：__next__()方法，同next()函数
# 注意：一个生成器只能完整使用一次，如需多次，则需多次建立生成器对象
# 顺便讲下可迭代对象实质：可迭代对象就是提供了next方法的对象，for循环实际上就是调用next

# 创建生成器-2
# 利用yield关键字和普通函数，建立生成器对象
# yield返回一个结果给函数，同时记住这个返回的位置挂起函数的状态，相当于暂停
# 调用next再次进入函数时，从这个地址后一条语句开始继续执行

def gen(n):
    for i in range(n):
        yield i

nums = gen(1000)
print(nums)

# 创建一个生成器，可以依次生成0,1,2,3....
# 例：建立一个可输出无限个整数的生成器
def infinte_num():
    i = 0
    while True:
        yield i
        i += 1
nums = infinte_num()
print(next(nums))
print(next(nums))

# 斐波那契数列生成器
def fibo(n):
    for i in range(1, n+1):
        if i in (1, 2):
            a, b = 1, 1
        else:
            a, b = b, a+b
        yield b

nums = fibo(8)
for i in nums:
    print(i)

# 5. 变量作用域
# 变量作用域
'''
通常情况，自定义函数内的变量作用在该函数体内部，即局部变量
函数内某变量与主程序中的某变量名重名时，主要有两种情况
'''
# 情况1：函数内某变量的引用没有改变，则该变量做为全局变量使用
# 情况1.1
#函数定义
def inner():
    print('inner', n)

#主程序
n=100       # n=100 与 inner()不能互换，否则出错
inner()
print('main', n)

# 情况1.2
#函数定义
def inner():
    nums.append(4)
    print('inner', nums)  # 虽然值变了，但引用没变

#主程序
nums = [1,2,3]
inner()
print('main', nums)
'''
由以上示例代码可知，函数内可直接改变函数外的同名可变数据类型的值（不是改变其引用）
'''

# 情况2：函数内某变量的引用改变了（如赋值），则分别为局部变量与全局变量
#函数定义
def inner():
    n = 10
    print('inner', n)   # 注意此句不能与n = 10交换，否则会出现ERROR（因局部变量未赋值就使用）

#主程序
n=100
inner()
print('main', n)

'''
可不可以在函数内更改全局变量的引用呢？
'''

# global关键字
'''
可在自定义函数中通过global关键字声明某变量为全局变量
则该变量就是与函数外的同名变量是同一个变量了
'''
def inner():
    global n    # 要使用全局变量n了，告诉解释器一下
    print('inner', n)
    n = 10

#主程序
n=100
inner()
print('main', n)


# 函数嵌套定义
'''
嵌套函数即在函数内部定义函数并使用，可以实现用函数去封装函数。
用途之一是：可将仅A函数使用的一些函数封装在A函数内部。
'''
# 简单例子
# funcA将使用BCD函数，而BCD函数并无funcA之外的函数使用
def funcA():
    def funcB():
        print("funcB")
    def funcC():
        print("funcC")
    def funcD():
        print("funcD")
    funcB()
    funcC()
    funcD()

funcA()

# 变量/函数作用域例子-1
'''
1. 外部函数的变量可以被内部函数所使用，但不能被内部函数直接修改
2. 嵌套在内部的函数被外部函数所封装，无法在外部函数外直接调用
以上非常合理，符合之前变量作用域的规律
'''
def funcA():
    num = 10
    print(num)

    def funcB():
        num = 20    #改成num += 20 会报错，与之前类似
        print(num)
    
    funcB()
    print(num)

funcA()
funcB() #错误，其他函数无法调用

# 变量/函数作用域例子-2
'''
内部函数可以改变外部函数的可变对象---这很合理
'''
def funcA():
    nums = []
    print(nums)

    def funcB():
        nums.append(10)
        print(nums)
    
    funcB()
    print(nums)

funcA()
# 变量/函数作用域例子-3
'''
如果想在嵌套函数内部改变外部函数不可变的对象，可用nonlocal关键字
'''
def funcA():
    num = 10
    print(num)

    def funcB():
        nonlocal num   # 要使用外部函数的num了，所以告诉解释器一下
        num += 20    #改成num += 20 会报错，与之前类似
        print(num)
    
    funcB()
    print(num)

funcA()

#  python变量名解析机制（LEGB法则）
'''
对于函数中使用的变量名，python 依次搜索以下4个作用域：
1、本地作用域（L，即当前函数对应的作用域）
2、上层结构中def或lambda的本地作用域（E，即嵌套函数中上层函数对应的作用域）
3、全局作用域（G，即当前模块的作用域）
4、内置作用域（B，python预定义的__builtin__模块对应的，可以用 dir(__built__) 查看）

如果变量名在上面这4个地方都没找到，就会报错。
如果找到了，则根据解析变量规则，来确定变量的值。
'''
# global允许我们在函数内部修改全局变量
# nonlocal允许我们在嵌套函数内部修改外层函数内部的变量
'''
nonlocal和global很类似
前者只能用在嵌套函数内部，所声明的变量被视为外部函数的局部变量而非内部函数的局部变量
后者用在任何函数内部，所声明的变量为全局变量而非局部变量
nonlocal在多重嵌套函数的规则可自行实验（正如你直觉一样的设计---这很合理）
'''

# 如何能实现在外部函数之外，“调用”内部的嵌套函数呢？
# 外部函数返回嵌套函数
'''
方式1：外部函数的返回时直接调用嵌套函数
调用外部函数相当于执行了外部函数后，又执行了函数funcB，返回funcB的运行后的值
但这样意义并不大，本质上是funcA中执行了funcB，又返回了funcB函数的返回值
''' 
def funcA():  
    print("执行了funcA")
    def funcB():        
        print("执行了funcB")
    
    return funcB()

funcA()
print(funcA())

'''
方式2：外部函数返回嵌套函数-1
由于返回的是嵌套函数，因此更“直接”
''' 
def funcA():  
    print("执行了funcA")
    def funcB():        
        print("执行了funcB")
    
    return funcB

print("调用A")
funcA()
print("调用B")
funcA()()


'''
方式2：外部函数返回嵌套函数-2
还可以带参数
''' 
def funcA():  
    print("执行了funcA")
    def funcB(x, y):        
        print("执行了funcB",x ,y)
    
    return funcB

print("调用A")
funcA()
print("调用B")
funcA()(5,10)       # 实参穿透外部函数，直接传给嵌套函数的形参

# 高阶函数：函数的返回是一个函数（是函数，而非执行该函数）
def funcA():  
    print("执行了funcA")
    def funcB(x, y):        
        print("执行了funcB",x ,y)
    
    return funcB

#可以将返回的函数赋给某个对象
f = funcA()
# 后续在执行f时，实际上是执行返回的函数
# 原函数funcA内部其他已经执行过的，不再执行
f(5, 10)
f(10, 20)

'''
虽然很炫酷，但上面的函数实质只是funcB，实际意义不大
如果返回的funcB还携带其外部函数中的一些对象，就能够实现在调用外部函数以后，
保留外部函数的一些运行结果，后续在合适时机在funcB中进行使用。这就是闭包。
闭包使内部函数与外部函数的一些对象绑定，这些对象不会在外部函数执行完毕后被自动销毁/回收。
（这里闭包的概念与数学上的概念关系不大。可以简单理解为定义了一个封闭了/包裹了外部函数一些对象的高阶函数。）
'''
'''
在函数中可以（嵌套）定义另一个函数时，如果内部的函数引用了外部的函数的变量，
则可能产生闭包。闭包可以用来在一个函数与一组“私有”变量之间创建关联关系。
在给定函数被多次调用的过程中，这些私有变量能够保持其持久性。
'''
# 闭包最简实例
def tag(tag_name):
    def add_tag(content):
        return "<{0}>{1}</{0}>".format(tag_name, content)
    return add_tag
    
content = 'Hello'

add_tag = tag('a')
print(add_tag(content))

add_tag = tag('b')
print(add_tag(content))

#* 闭包实例-2
'''
棋盘左上角为坐标系原点(0,0)，设计一个函数控制棋子的运动
函数接收2个参数分别为方向(direction)，步长(step)，
每次运动的起点都是上次运动结束的终点
'''
def play(pos=None):
    if pos is None:
        pos = [0,0]

    def _go(direction, step):
        if direction == 1:
            pos[1] += step
        elif direction == 2:
            pos[0] += step
        elif direction == 3:
            pos[1] -= step
        elif direction == 4:
            pos[0] -= step        
        else:
            raise ValueError("direction必须是1-4")
        
        return pos
        
    return _go

go = play()
print(go(1,10))
print(go(2,20))
print(go(4,10))
# pos 封闭包裹在go函数内部，可以变化，但避免了外部更改调用
# 实际上，上述两个代码的这个功能可通过一个简单的类和对象实现
# 1
class Tag:
    def __init__(self, tag_name):
        self.tag_name = tag_name
    def add_tag(self, content):
        return f"<{self.tag_name}>{content}</{self.tag_name}>"

content = 'Hello'
tag = Tag("a")
print(tag.add_tag(content))
tag = Tag("b")
print(tag.add_tag(content))  

# 2
class Map:
    def __init__(self, x = 0, y = 0):
        self.pos = [x, y]

    def go(self, direction, step):
        if direction == 1:
            self.pos[1] += step
        elif direction == 2:
            self.pos[0] += step
        elif direction == 3:
            self.pos[1] -= step
        elif direction == 4:
            self.pos[0] -= step        
        else:
            raise ValueError("direction必须是1-4")
        return self.pos

map = Map()
print(map.go(1,10))
print(map.go(2,20))
print(map.go(4,10))

# 闭包的一些定义
'''
1、闭包是一个有状态（不消失的私有数据）的函数。
2、闭包是一个有记忆的函数。
3、闭包相当于一个只有一个方法的紧凑对象（a compact object）。
'''
#* 对python来说，闭包最大的用途是实现*装饰器和*设计模式中的工厂函数。
'''
装饰器一般用来在不修改某函数A代码的情况下，为其添加额外的新功能。
这种功能可能很通用/常见，虽然可以在各个函数内部独立实现，但冗余/重复劳动。
把额外的功能独立出来形成一个函数func，该函数以函数A为参数，返回一个函数B，形成一个闭包
函数B带有函数A对象，调用时能实现A的额外功能（修饰）
'''
import time

def timer(func):
    def wrapper():
        start = time.time()
        retf = func()
        end = time.time()
        print(f"{func.__name__}函数执行了{start-end}秒.")
        return retf     
    return wrapper      

@timer       
def foo():
    print("Do some job.")

foo()      