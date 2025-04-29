
#打电话(2)
#数媒一班 杜雨洋 202211580560


class PhoneDevice:
    Type='PD'
    def __init__(self):
        self.pd_type=str()
        self.pd_model=str()
        self.pd_number=str()
        self.pd_operator=None
        self.pd_person=None
        self.HY=dict()                   #FP 和 PP 的黄页是一样的，索性直接在PD构造函数里面定义就好
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
    def add_HY(self,a,b):    #add黄页函数，用来给黄页加数据
        self.HY[a]=b

class MobilePhone(PhoneDevice):
    Type='MP'
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
            if person2.name in self.address_list:
                if self.pd_operator==None:
                    print('网络运营商未连接，call失败')
                elif person2.phone==None:
                    print('对方未持有手机，call失败')
                elif person2.phone!=None and person2.phone.pd_operator==None:
                    print('对方手机网络运营商未连接，call失败')
                else:
                    print(person1.name,'使用ta的MobilePhone call',person2.name,'成功，说:',content)
                    
            else:
                print('未在通讯录中找到该联系人，无法call')

class FreePhone(PhoneDevice):
    Type='FP'
    fp_list=['home','dorm','office'] #freephone 位置列表
    def __init__(self):
        super().__init__()
        self.pd_address='home'              #设置freephone 默认位置
        self.pd_operator='DX'               #设置默认网络运营商
        
    def call(self,person1,person2,content):
        if person1.address in self.fp_list:
            if person2.name in self.HY:
                if self.pd_operator==None:
                    print('网络运营商未连接，call失败')
                elif person2.phone==None:
                    print('对方未持有手机，call失败')
                elif person2.phone!=None and person2.phone.pd_operator==None:
                        print('对方手机网络运营商未连接，call失败')
                else:
                    print(person1.name,'在',self.pd_address,'使用FreePhone call',person2.name,'成功，说:',content)
            else:
                print('查无此人，call不了')
                
        else:
            print('您所在的位置没有FreePhone喔~')

class PublicPhone(PhoneDevice):
    Type='PP'
    fp_list=['home','dorm','office'] # 设置一个不能出现的 位置列表 （其实也就是上面freephone的位置）
    pb_list=dict()                       # 设置一个publicphone 出现的位置 （类属性）
    
    def __init__(self,address):
        super().__init__()
        self.pd_operator='YD'
        self.address=address     #设置publicphone位置
        PublicPhone.pb_list[address]=0
        
    def call(self,person1,person2,content):
        if person1.address in PublicPhone.pb_list:
            if person2.name in self.HY:
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
                print('电话簿查无此人，call失败')

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
        self.publicphone=None
        self.freephone=None
    def pick_up(self,thing):
        self.bag.append(thing)
        return self.bag
    def move_to(self,address):
        self.address=address
        
    def own_mobilephone(self,phone):   #人获得mobilephone
        self.phone=phone
        phone.set_person(self.name)
    def meet_freephone(self,phone):
        self.freephone=phone
    def meet_publicphone(self,phone):
        self.publicphone=phone
    
    def use_phone(self,person1,person2,content):
        if self.address in FreePhone.fp_list:
           self.freephone.call(person1,person2,content)
        else:
            if self.address in PublicPhone.pb_list:
                self.publicphone.call(person1,person2,content)
            else:
                if self.phone!=None:
                    self.phone.call(person1,person2,content)
                else:
                    print("此地竟为绝境哉，无公共电话，亦无手机")
        
        
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
lpy.own_mobilephone(mp1)                         #lpy拥有mp1
mp1.change_state()                         #mp1开机

mp2.set_operator('LT')
mp2.add_address_list('五条人','55555')
mp2.add_address_list('刘鹏远','111111')
mp2.set_phone('Iphone','X pro','1919810')
me.own_mobilephone(mp2)                          #同上mp1，me拥有mp2
mp2.change_state()

mp3.set_operator('YD')
mp3.add_address_list('特朗普','777777')
mp3.set_phone('小灵通','2代豪华版','114514') 
msk.own_mobilephone(mp3)                          #注意mp3未开机,msk拥有mp3


bp1=PublicPhone('车展馆')  #实例化车展馆的publicphone
bp1.add_HY(msk.name,'114514')
fp1=FreePhone()            #实例化 freephone(默认在home)
fp1.add_HY(msk.name,'114514')
fp1.add_HY(wtr.name,'55555')
fp1.add_HY(me.name,'1919810')
#开始执行题目要求操作：



lpy.move_to(input())
lpy.use_phone(lpy,msk,'快来学Python')

lpy.move_to(input())
lpy.meet_publicphone(bp1)
lpy.use_phone(lpy,msk,'快送我台车')

lpy.move_to(input())
lpy.meet_freephone(fp1)
lpy.use_phone(lpy,msk,'快送我去火星')

lpy.use_phone(lpy,wtr,'我想阿珍爱上了阿强')

lpy.use_phone(lpy,me,'好好学习Python,要期末考试了')




        



        
    
    
