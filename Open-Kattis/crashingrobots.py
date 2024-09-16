K = int(input())

for _ in range(K):
    A, B = map(int, input().split())
    N, M = map(int, input().split())

    robot_to_position = dict()
    position_to_robot = dict()
    for i in range(1, N + 1):
        *xy, dir = input().split()
        x, y = map(int, xy)
        
        if dir == "N":
            dir = 0
        elif dir == "E":
            dir = 1
        elif dir == "S":
            dir = 2
        else:
            dir = 3
        
        robot_to_position[i] = [x, y, dir]
        position_to_robot[x, y] = i
    
    do_print = True
    for _ in range(M):
        robot, action, rep = input().split()
        robot = int(robot)
        rep = int(rep)

        if not do_print:
            continue

        x, y, dir = robot_to_position[robot]
        if action == "L":
            new_dir = (dir - rep) % 4
            robot_to_position[robot][2] = new_dir
        elif action == "R":
            new_dir = (dir + rep) % 4
            robot_to_position[robot][2] = new_dir
        else:
            del position_to_robot[x, y]

            for _ in range(rep):
                if dir == 0:
                    y += 1
                elif dir == 1:
                    x += 1
                elif dir == 2:
                    y -= 1
                else:
                    x -= 1
                
                if do_print and (x == 0 or x == A + 1 or y == 0 or y == B + 1):
                    print(f"Robot {robot} crashes into the wall")
                    do_print = False
                elif do_print and (x, y) in position_to_robot:
                    print(f"Robot {robot} crashes into robot {position_to_robot[x, y]}")
                    do_print = False
            
            robot_to_position[robot][:2] = [x, y]
            position_to_robot[x, y] = robot

    if do_print:
        print("OK")
