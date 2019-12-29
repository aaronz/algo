"""
A binary search tree
"""


class Node:
    def __init__(self, value, parent):
        self.value = value
        self.parent = parent
        self.left = None
        self.right = None

    def __repr__(self):
        from pprint import pformat

        if self.left is None and self.right is None:
            return str(self.value)
        return pformat({"%s" % (self.value): (self.left, self.right)}, indent=1,)


class BinarySearchTree:
    def __init__(self, root=None):
        self.root = root

    def __str__(self):
        return str(self.root)

    def __reassign_nodes(self, node, newChildren):
        if newChildren is not None:
            newChildren.parent = node.parent
        if node.parent is not None:
            if self.is_right(node):
                node.parent.right = newChildren
            else:
                node.parent.left = newChildren
        else:
            self.root = newChildren

    def is_right(self, node):
        return node == node.parent.right

    def empty(self):
        return self.root is None

    def __insert(self, value):
        new_node = Node(value, None)
        if self.empty():
            self.root = new_node
        else:
            parent_node = self.root
            while True:
                if value < parent_node.value:
                    if parent_node.left is None:
                        parent_node.left = new_node
                        break
                    else:
                        parent_node = parent_node.left
                else:
                    if parent_node.right is None:
                        parent_node.right = new_node
                        break
                    else:
                        parent_node = parent_node.right
            new_node.parent = parent_node

    def insert(self, *values):
        for value in values:
            self.__insert(value)
        return self

    def search(self, value):
        if self.empty():
            return IndexError("Warning: Tree is empty.")
        else:
            node = self.root
            while node is not None and node.value is not value:
                node = node.left if value < node.value else node.right
            return node

    def get_max(self, node=None):
        if node is None:
            node = self.root
        if not self.empty():
            while node.right is not None:
                node = node.right
        return node

    def get_min(self, node=None):
        if node is None:
            node = self.root
        if not self.empty():
            while node.left is not None:
                node = node.left
        return node

    def remove(self, value):
        node = self.search(value)
        if node is not None:
            if node.left is None and node.right is None:
                self.__reassign_nodes(node, None)
                node = None
            elif node.left is None:
                self.__reassign_nodes(node, node.right)
            elif node.right is None:
                self.__reassign_nodes(node, node.left)
            else:
                # get the max value node from the left child
                # and make it the current node, then remove it
                # from left child
                temp_node = self.get_max(node.left)
                self.remove(temp_node)
                node.value = temp_node.value

    def preorder_traverse(self, node):
        if node is not None:
            yield node
            yield self.preorder_traverse(node.left)
            yield self.preorder_traverse(node.right)

    def traversal_tree(self, traversalFunction=None):
        if traversalFunction is None:
            return self.preorder_traverse(self.root)
        else:
            return traversalFunction(self.root)

def postorder(current_node):
    node_list = list()
    if current_node is not None:
        node_list = postorder(current_node.left) + \
            postorder(current_node.right) + [current_node]
        return node_list

def binary_search_tree():
    test_list = (8,3,6,1,10,14,13,4,7)
    t = BinarySearchTree()
    for i in test_list:
        t.insert(i)

    print(t)

    if t.search(6) is not None:
        print("The value 6 exists")
    else:
        print("The value 6 does not exist")

    if t.search(-1) is not None:
        print("The value -1 exists")
    else:
        print("The value -1 does not exist")

    if not t.empty():
        print("Max value: ", t.get_max().value)
        print("Min value: ", t.get_min().value)

    for i in test_list:
        t.remove(i)
        print(t)

if __name__ == "__main__":
    import doctest

    doctest.testmod()
    binary_search_tree()