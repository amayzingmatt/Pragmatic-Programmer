# Matt's Turtle Parser

def turtle_parser():
    print("Begin entering commands:")
    while(1):
        user_input = input()
        cmd, num = parse_input(user_input)
        match cmd:
            case 'P':
                print("Pen " + num + " Selected")
            case 'D':
                print("Pen down")
            case 'W':
                print("Draw West " + num + "cm")
            case 'N':
                print("Draw North " + num + "cm")
            case 'E':
                print("Draw East " + num + "cm")
            case 'S':
                print("Draw South " + num + "cm")
            case 'U':
                print("Pen up")
                return
            case _:
                print("Invalid Command")

def parse_input(user_input):
    input_str = str(user_input)
    cmd = input_str[0]
    num = ''
    if cmd != 'D' and cmd != 'U':
        num = input_str[2]
    return cmd, num

def main():
    turtle_parser()

if __name__ == '__main__':
    main()
