def draw_room(w, h, x, y):
    # print the top wall
    print("+" + w * "-" + "+")
    for i in range(h):
        if i == y:
            print("|" + x*"." + "@" + (w - x - 1)*"." + "|")
        else:
            print("|" + w*"." + "|")
    # print the bottom wall
    print("+" + w * "-" + "+")