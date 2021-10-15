 servo1=Servo(2)
    servo2=Servo_pwm(2)
    i = 0
    servo2.servocontrol(50,100)    
    servo1.servocontrol(-10, 100)
    time.sleep(3)
    servo2.servocontrol(0,100)
    time.sleep(3)
    servo1.servocontrol(-85, 100)
    print("-85,100")
    time.sleep(3)

 while not logger.stopped():
        time, value, type_, number = js.read()
        if js.type(type_) == "button":
            print("button:{} state: {}".format(number, value))
            if number == 6 and value == 1:
                logger.start()
            if number == 7 and value == 1:
                logger.stop()
            if number == 4 and value == 1:
                i = i + 10
                if i > 90:
                    i = 90
                print(i)
            elif number == 0 and value == 1:
                i = i - 10
                if i < 10:
                    i = 10
                print(i)
        if js.type(type_) == "axis":
            print("axis:{} state: {}".format(number, value))
            if number == 7 and value > 32760:
                c.back(i)
            elif number == 7 and value < -32760:
                c.run(i)
            elif number == 6 and value > 32760:
                c.right(i)
            elif number == 6 and value < -32760:
                c.left(i)          
            else:
                c.brake() 