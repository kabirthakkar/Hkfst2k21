class BinaryTree:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __str__(self):
        def print(self):
            if self.left:
                return str(self.data) + " " + self.left.print(self.data)


a = BinaryTree(0)
print(a.data)
