def pygame_get():
    for event_ in pygame.event.get():
        # 方向键改变事件
        elif event_.type == pygame.JOYHATMOTION:
            hats = joystick.get_numhats()
            # 获取所有方向键状态信息
            for i in range(hats):
                hat = joystick.get_hat(i)
                print(str(hat))
                if str(hat) == "(0, 1)":
		    run()
		elif str(hat) == "(0, -1)":
		    back()
		elif str(hat) == "(1, 0)":
		    right()
		elif str(hat) == "(-1, 0)":
		    left()
		else:
		    brake()