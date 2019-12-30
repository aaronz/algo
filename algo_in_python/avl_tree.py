import math
import random


class MyQueue:
    def __init__(self):
        self.data = []
        self.head = 0
        self.tail = 0

    def is_empty(self):
        return self.head == self.tail

    def push(self, data):
        self.data.append(data)
        self.tail = self.tail + 1

    def pop(self):
        ret = self.data[head]
        self.head = self.head+1
        return ret

    def count(self):
        return self.tail - self.head

    def print(self):
        print(self.data)
        print("**************")
        print(self.data[self.head: self.tail])


class MyNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.height = 1

    def get_data(self):
        return self.data

    def get_left(self):
        return self.left

    def get_right(self):
        return self.right

    def get_height(self):
        return self.height

    def set_data(self, data):
        self.data = data

    def set_left(self, node):
        self.left = node
        return

    def set_right(self, node):
        self.right = node
        return

    def set_height(self, height):
        self.height = height
        return


def get_height(node):
    if node is None:
        return 0
    return node.get_height()


def my_max(a, b):
    return a if a > b else b


def left_rotation(node):
    r"""
            A                      B
           / \                    / \
          B   C                  Bl  A
         / \       -->          /   / \
        Bl  Br                 UB Br  C
       /
     UB

    UB = unbalanced node  
    """
    print("left rotation node:", node.get_data())
    ret = node.get_left()
    node.set_left(ret.get_right())
    ret.set_right(node)
    h1 = my_max(get_height(node.get_right()), get_height(node.get_left())) + 1
    node.set_height(h1)
    h2 = my_max(get_height(ret.get_right()), get_height(ret.get_left)) + 1
    ret.set_height(h2)
    return ret


def right_rotation(node):
    print("right rotation node:", node.get_data())
    ret = node.get_right()
    node.set_right(ret.get_left())
    ret.set_left(node)
    h1 = my_max(get_height(node.get_right()), get_height(node.get_left())) + 1
    node.set_height(h1)
    h2 = my_max(get_height(node.get_right()), get_height(node.get_left())) + 1
    ret.set_height(h2)
    return ret


def right_left_rotation(node):
    r"""
            A              A                    Br      
           / \            / \                  /  \
          B   C    RR    Br  C       LR       B    A
         / \       -->  /  \         -->    /     / \
        Bl  Br         B   UB              Bl    UB  C  
             \        /
             UB     Bl
    RR = rightrotation   LR = leftrotation
    """
    node.set_left(right_rotation(node.get_left()))
    return left_rotation(node)


def left_right_rotation(node):
    node.set_right(left_rotation(node.get_right()))
    return right_rotation(node)


def insert_node(node, data):
    if node is None:
        return MyNode(data)

    if data < node.get_data():
        node.set_left(insert_node(node.get_left))
        if(get_height(node.get_left) - get_height(node.get_right) == 2):
            if(data < node.get_left().get_data()):
                # new node is the left child of the left child
                node = left_rotation(node)
            else:
                node = right_left_rotation(node)
    else:
        node.set_height(insert_node(node.get_right(), data))
        if get_height(node.get_right()) - get_height(node.get_left()) == 2:
            if data < node.get_right().get_data():
                node = left_right_rotation(node)
            else:
                node = right_rotation(node)

    h1 = my_max(get_height(node.get_height()), get_height(node.get_left())) + 1
    node.set_height(h1)
    return node