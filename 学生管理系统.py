import sys#导入操作系统模块
import time
Stu_info=[]#学生的信息列表

def Load_data():#读取txt文件
   f=open('Student.txt','r',encoding='utf-8')
   Stu_line = f.read().splitlines()  # 可以去掉换行符
   for line in Stu_line:  # 每一行，即每一个函数
            temp = line.strip(' ')  # 移除头尾空格（括号里面什么都不写默认是去掉头尾空格和换行）（指定字符）
            temp2 = line.split(',')  # 通过逗号进行切片（指定字符）
            Stu_info.append(temp2)  # 将弄好的列表属性添加到Stu_info列表中
            f.close()

def Write_data():#存入文件
    f = open('Student.txt', 'w', encoding='utf-8')
    for line in range(0,len(Stu_info)):#遍历Stu_info
        num=Stu_info[line][0]#将学生的学号赋值给num
        name = Stu_info[line][1]#将学生的姓名赋值给name
        age = Stu_info[line][2]#将学生的年龄赋值给age
        address = Stu_info[line][3]#将学生的地址赋值给address
        f.writelines('%s,%s,%s,%s\n'%(num, name, age, address))#将学生的信息存入文件
    f.close()

def print_Stu(Student):
    print('学号\t姓名\t年龄\t地址\t')
    for arr in Student:#输出学生信息
        print('%s\t%s\t%s\t%s'%( arr[0],arr[1],arr[2],arr[3]))#分别输出学号，姓名，年龄，地址

def  print_Stu_2(index):
    print('学号\t姓名\t年龄\t地址\t')
    '''#输出查询到的学生的学号，姓名，年龄，地址 '''
    print('%s\t%s\t%s\t%s' % (Stu_info[index][0], Stu_info[index][1], Stu_info[index][2], Stu_info[index][3]))

def Stu_seek():#查找所有学生信息

   if len(Stu_info)==0:#判断学生数组的数据是否存在
       print("暂无学生....\n")
   else:
       print_Stu(Stu_info)#调用输出所有学生的函数 print_Stu

def Search_Stu(num):#通过学号查找学生信息
    if len(Stu_info) == 0:#列表为空
        print("暂无学生....\n")
    else:
        for index in range(0, len(Stu_info)):
            if num in Stu_info[index]:#查找符合该学号的学生信息
                print_Stu_2(index)  # 输出该生信息
                return index#返回该学生的下标

    print('该生不存在....')
    return -1

def Del_stu():
    num=input('请输入删除学生学号: ')
    index=Search_Stu(num)#先查询该生是否存在，存在则输出该生信息然后提示已删除
    if(index!=-1):
        print('已删除')
        del  Stu_info[index]

def  Up_date():
    print('欢迎进入修改学生信息.....')
    num = input('请修改的学生学号: ')
    index = Search_Stu(num)#先查询该生是否存在，存在则修改该生信息
    if (index != -1):
        print('可以修改....')
        Stu_info[index][1] = input('请输入姓名:')
        Stu_info[index][2] = input('请输入年龄:')
        Stu_info[index][3] = input('请输入地址：')
        print('修改成功....')
        Write_data()
    else:
        print('不可以修改')


def Add_stu():
    print('欢迎进入添加学生信息.....')
    num = input('请增加的学生学号: ')
    index = Search_Stu(num)#先查询该生是否存在，不存在则增加学生信息
    if (index == -1):
        print('可以添加....')
        name = input('请输入姓名:')
        age = input('请输入年龄:')
        address = input('请输入地址：')
        Stu_info.append([num,name,age,address])
        print('添加成功....')
        Write_data()
    else:
        print('不可以添加')


def Clear_stu():
    for i in range(0,len(Stu_info)):
        Stu_info.pop()
        print("清空完成.....")
def print_menu():
    print('======青岛农业大学宿舍管理系统V2.0======')
    print('1.查询所有学生信息')
    print('2.通过学号查询学生信息')
    print('3.通过学号删除学生信息')
    print('4.通过学号修改学生信息')
    print('5.添加学生信息')
    print('6.清空学生信息')
    print('7.退出系统')
    Load_data()

print_menu()
flag=True
while flag==True:
    i=int(input('请输入1-6选择相应的功能：'))
    if i==1:
        Stu_seek()#查询所有学生信息功能
    elif i==2:
        Num=input('请输入查找学生的学号: ')
        Search_Stu(Num)#按学号查找学生信息
    elif i==3:
        Del_stu()#删除学生的信息
    elif i==4:
        Up_date()#修改学生信息
    elif i==5:
        Add_stu()#增加学生信息
    elif i==6:
        Clear_stu()#清空学生信息
    else:
        time.sleep(5)
        print("程序已退出，欢迎下次使用....")
        sys.exit(0)
