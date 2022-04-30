import demo_init as math_acl

def lear_math(x, y, oper):
    r = 0
    if oper == "+":
        r = math_acl.add_demo.add(x, y)
    elif oper == "-":
        r = math_acl.sub_demo.sub(x, y)
    elif oper == "*":
        r = math_acl.mul_demo.mul(x, y)
    else:
        r = math_acl.dev_demo.dev(x, y)

    print("{} {} {} = {}".format(x, oper, y, r))

x, y = 2022, 1314

lear_math(x, y, "+")
lear_math(x, y, "-")
lear_math(x, y, "*")
lear_math(x, y, "/")