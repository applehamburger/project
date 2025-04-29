
#打电话(1)
#数媒一班 杜雨洋 202211580560


class PhoneDevice:
    def __init__(self):
        self.pd_type=str()
        self.pd_model=str()
        self.pd_number=str()
        self.pd_operator=None
        self.pd_person=None
        
    def set_operator(self,operator):
        self.pd_operator=operator
        
    def set_person(self,person_name):   #手机拥有主人
        self.pd_person=person_name
        

    def call(self,person1,person2,content):
        if self.pd_operator==None:
            print('网络运营商未连接，call失败')
        elif person2.phone==None:
            print('对方未持有手机，call失败')
        elif person2.phone!=None and person2.phone.pd_operator==None:
                print('对方手机网络运营商未连接，call失败')
        else:
            print(person1.name,'call',person2.name,'成功，说:',content)

    def set_phone(self,t,m,n):  #手动设置手机参数
        self.pd_type=t
        self.pd_model=m
        self.pd_number=n

class MobilePhone(PhoneDevice):
    def __init__(self):
        super().__init__()
        self.state ='off'
        self.address_list=dict()
                               
    def  add_address_list(self,name,number):         #名字及对应的电话号码
        self.address_list[name]=number
        
    def change_state(self):
        if self.state =='off':
            self.state ='on'
            print(self.pd_type,'手机已开机')
        elif self.state == 'on':
            self.state ='off'
            print(self.pd_type,'手机已关机')
            
    def show_address_list(self):
        print('通讯录如下：',self.address_list)

    def call(self,person1,person2,content):
        if self.state=='off':
            print('手机未开机，call失败')
        elif self.state=='on':
            if self.pd_operator==None:
                print('网络运营商未连接，call失败')
            elif person2.phone==None:
                print('对方未持有手机，call失败')
            elif person2.phone!=None and person2.phone.pd_operator==None:
                print('对方手机网络运营商未连接，call失败')
            else:
                print(person1.name,'使用ta的MobilePhone call',person2.name,'成功，说:',content)
                if person2.name not in self.address_list:   #如果打电话成功了就查通讯库，没有就加上
                    self.address_list[person2.name]=person2.number

class FreePhone(PhoneDevice):
    def __init__(self):
        super().__init__()
        self.pd_address='home'              #设置freephone 默认位置
        self.pd_operator='DX'               #设置默认网络运营商
        self.pd_list=['home','dorm','office'] #freephone 位置列表
    
    def call(self,person1,person2,content):
        if person1.address in self.pd_list:
            if self.pd_operator==None:
                print('网络运营商未连接，call失败')
            elif person2.phone==None:
                print('对方未持有手机，call失败')
            elif person2.phone!=None and person2.phone.pd_operator==None:
                    print('对方手机网络运营商未连接，call失败')
            else:
                print(person1.name,'在',self.pd_address,'使用FreePhone call',person2.name,'成功，说:',content)
        else:
            print('您所在的位置没有FreePhone喔~')

class PublicPhone(PhoneDevice):
    def __init__(self,address):
        super().__init__()
        self.pd_operator='YD'
        self.address=address     #设置publicphone位置
        self.pd_list=['home','dorm','office'] # 设置一个不能出现的 位置列表 （其实也就是上面freephone的位置）
        
    def call(self,person1,person2,content):
        if person1.address not in self.pd_list:
            if self.pd_operator==None:
                print('网络运营商未连接，call失败')
            elif person2.phone==None:
                print('对方未持有手机，call失败')
            elif person2.phone!=None and person2.phone.pd_operator==None:
                    print('对方手机网络运营商未连接，call失败')
            else:
                print(person1.name,'在',person1.address,'使用PublicPhone call',person2.name,'成功，说:',content)
                print('每分钟收费一元钱,请根据您的通话时长支付费用')
        else:
            print('您所在的位置没有PublicPhone喔~')

class Person:
    def __init__(self,name,age,gender):
        self.name=name
        self.age=age
        self.gender=gender
        self.bag=[]
        self.address='home'
        self.phone=None
    def pick_up(self,thing):
        self.bag.append(thing)
        return self.bag
    def move_to(self,address):
        self.address=address
        
    def own_phone(self,phone):   #人获得手机
        self.phone=phone
        phone.set_person(self.name)
    
    def use_phone(self,phone,person1,person2,content):
        phone.call(person1,person2,content)
        
        
        
#主函数部分：

lpy=Person('刘鹏远',41,'男')
msk=Person('马斯克',36,'男')       #实例化person
wtr=Person('五条人',25,'男')
me=Person('陈冠希',18,'男')

mp1=MobilePhone()
mp2=MobilePhone()                  #实例化 mobilephone 
mp3=MobilePhone()

mp1.set_operator('DX')                     #mobilephone p1 连接网络运营商 DX                     
mp1.add_address_list('马斯克','911')     
mp1.add_address_list('陈冠希','1919810')     #mp1通讯录添加
mp1.set_phone('RedMi','K50 pro','111111')  #mp1设置手机参数
lpy.own_phone(mp1)                         #lpy拥有mp1
mp1.change_state()                         #mp1开机

mp2.set_operator('LT')
mp2.add_address_list('五条人','55555')
mp2.add_address_list('刘鹏远','111111')
mp2.set_phone('Iphone','X pro','1919810')
me.own_phone(mp2)                          #同上mp1，me拥有mp2
mp2.change_state()


mp3.set_operator('YD')
mp3.add_address_list('特朗普','777777')
mp3.set_phone('小灵通','2代豪华版','114514') 
msk.own_phone(mp3)                          #注意mp3未开机,msk拥有mp3




#开始执行题目要求操作：

lpy.move_to('school')
lpy.use_phone(mp1,lpy,msk,'快来学Python')

lpy.move_to('车展馆')
bp1=PublicPhone('车展馆')  #实例化车展馆的publicphone
lpy.use_phone(bp1,lpy,msk,'快送我台车')

lpy.move_to('home')
fp1=FreePhone()
lpy.use_phone(fp1,lpy,msk,'快送我去火星')

lpy.use_phone(mp1,lpy,wtr,'我想阿珍爱上了阿强')

lpy.use_phone(mp1,lpy,me,'好好学习Python,要期末考试了')



        



        
    
    
