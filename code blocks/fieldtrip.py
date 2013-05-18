import psyco
psyco.full()
import math

tc = int(raw_input())
for cases in range(tc):
    temp=int(raw_input())
    if temp==2:
        print temp
        continue
    
    prime=0
    #i=long(1)
    while prime==0:
        if temp%2==0 and temp !=2:
            temp=temp-1
            continue
        if temp%3==0 and temp !=3:
            temp=temp-1
            continue
        if temp%5==0 and temp !=5:
            temp=temp-1
            continue
        if temp%7==0 and temp !=7:
            temp=temp-1
            continue
        if temp%11==0 and temp !=11:
            temp=temp-1
            continue
        if temp%13==0 and temp !=13:
            temp=temp-1
            continue
        prime=1
        sqrt=int(math.sqrt(temp))+1
        for i in xrange(13,sqrt):
            if temp%i==0:
                temp=temp-2
                prime=0
                break
        if prime==1:
            print temp
            break
