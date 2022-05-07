# 이 파일은 파이썬에서 유용한 모듈을 정리해놓은 파일이다.

########################################################
#copy 모듈 - 깊은복사를 할 수 있게 하는 함수가 존재하는 모듈

def copyModule():
    import copy
    number = [1,2,3]
    clone = copy.deepcopy(number)

    clone[0] = 9
    print(number)
    print(clone)
#copyModule()

#keyword 모듈 - 예약어에 대한 정보를 주는 모듈
def keywordModule():
    import keyword
    print(keyword.kwlist)

#keywordModule()


#random 모듈 - 난수를 생성할때 사용하는 모듈
    #randint - 정수범위의 난수 생성
    #random - 0과 1 사이의 난수 반환
    #choice - 주어진 시퀀스의 항복을 랜덤하게 반환
    #shuffle - 리스트의 항목을 랜덤하게 섞는다
    #randrange(start, stop[,stop]) - range(start, stop, step)구간에서 랜덤하게 요소 생성
    
def randomModule():
    import random
    print(random.randint(1,6))
    
    print(random.random()*100)

    list = ['d','c','b','a']
    print(random.choice(list))

    list2 = [[x] for x in range(10)]
    random.shuffle(list2)
    print(list2)

    for i in range(3):
        print(random.randrange(0,101,3))
        
#randomModule()



#os 모듈
    #system("calc") - 계산기 실행
    #os.getcwd(), os.chdir(path) 현재 작업 디렉터리 위치를 변경하거나 가져온다
    #os.listdir(path) 해당 경로에 존재하는 파일과 디렉터리를 리스트로 반환
    #os.mkdir(path) <path>에 해당하는 디렉터리를 생성한다.
def osModule():
    import os
    os.system("calc")

    print(os.getcwd())
    os.chdir("C:\\Users")
    print(os.getcwd())

    os.listdir(".")

    #os.mkdir("file") 생성하기 싫어서 안함
    #os.listdir(".")


#osModule()



#sys 모듈
#파이썬 인터프리터에 대한 다양한 정보 제공
def sysModule():
    import sys
    print(sys.prefix) #파이썬이 설치된 경로

    print(sys.executable)
    #sys.exit() 인터프리터 종료
    #print(sys.modules) 설치되어 있는 모듈을 보여준다.
    #print(sys.path) 모듈을 참조할 때 사용하는 경로
    #print(sys.version) 파이썬의 버전을 보여준다.

#sysModule()



#time 모듈
#프로그램이 실행되는데 얼마나 시간이 걸리는지 측정 가능하다.
#time.time()을 사용한다. 프로그램이 시작할때 끝날때 변수로 저장해서 그 차를 구한다
    #time() - 현재시간을 반환한다. 컴퓨터의 방식으로 반환
    #asctime() - 현재 날짜와 시간을 문자열로 반환
        #만약 특정 날자를 asctime에 주려면 튜플로 생성한다.
        #(연도, 월, 일, 시간, 분, 초 ,요일, 0, 0)형태이다.
    #localtime() - 현재 날짜와 시간을 튜플 객체 형태로 반환
    #sleep() - 동작중인 프로세스를 지정된 시간만큼 정지시킨다
        #프로그램을 약간 천천히 실행하고자 할 때 사용
    
def timeModule():
    import time
    print(time.time())
    
    print(time.asctime())

    t = (2016, 4, 29, 12, 10, 30, 5, 0, 0)
    print(time.asctime(t))

    print(time.localtime())#연도와 월 추출 가능
    localt = time.localtime()
    year = localt[0]
    month = localt[1]
    
    for i in range(10,0,-1):
        print(i, end = " ")
        time.sleep(1)
    print("발사")

#timeModule()



#calendar 모듈
#달력 출력가능
def calendarModule():
    import calendar
    cal = calendar.month(2016,8)
    print(cal)

calendarModule()





















