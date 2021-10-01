class ListNode:
    def __setNode(self, Node):
        self.data = Node[0]
        self.next = ListNode(Node[1:]) if len(Node) > 1 else None


    def __init__(self, *args):  # sequence=None, Data=0, Next=None
        if isinstance(args[0], list):
            self.__setNode(args[0])
        else:
            self.data = args[0]
            self.next = args[1] if len(args) > 1 else None

    def count(self):
        if self.next:
            return 1 + self.next.count()
        else:
            return 1

    def __len__(self):
        return self.count()

    def __str__(self):
        def print(node):
            if node:
                if node.next:
                    return str(node.data) + " -> " + print(node.next)
                return str(node.data)
        return print(self)
