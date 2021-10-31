public Node flatten(Node head) {
    if (head == null) return head;

    Node pseudoHead = new Node(0, null, head, null);
    Node curr, prev = pseudoHead;

    Deque<Node> stack = new ArrayDeque<>();
    stack.push(head);

    while (!stack.isEmpty()) {
      curr = stack.pop();
      prev.next = curr;
      curr.prev = prev;

      if (curr.next != null) stack.push(curr.next);
      if (curr.child != null) {
        stack.push(curr.child);
        // don't forget to remove all child pointers.
        curr.child = null;
      }
      prev = curr;
    }
    // detach the pseudo node from the result
    pseudoHead.next.prev = null;
    return pseudoHead.next;
  }