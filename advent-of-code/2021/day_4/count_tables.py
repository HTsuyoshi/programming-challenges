with open("input1.txt", "r") as f:
    f.readline()
    f.readline()

    i = 0
    random_text = "a"
    try:
        while True:
            random_text = next(f)
            if random_text == "\n":
                i += 1
    except StopIteration:
        print(i)
