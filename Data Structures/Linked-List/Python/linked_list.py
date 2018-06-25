class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def print_list(self):
        cur_node = self.head
        while cur_node:
            print(cur_node.data)
            cur_node = cur_node.next

    def insert_to_end(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        last_node =  self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def insert_to_begin(self, data):
        new_node = Node(data)

        new_node.next = self.head
        self.head = new_node

    def insert_after_node(self, prev_node, data):

        if not prev_node:
            print("Previous node is not in the list")
            return

        new_node = Node(data)

        new_node.next = prev_node.next
        prev_node.next = new_node

    def delete_node(self, key):
        cur_node = self.head

        if cur_node and cur_node.data == key:
            self.head == cur_node.next
            cur_node = None
            return

        prev = None
        while cur_node and cur_node.data != key:
            prev = cur_node
            cur_node = cur_node.next

        if cur_node is None:
            return

        prev.next = cur_node.next
        cur_node = None

    def delete_node_at_pos(self, pos):
        cur_node = self.head

        if pos == 0:
            self.head = cur_node.next
            cur_node = None
            return

        prev = None
        count = 1
        while cur_node and count != pos:
            prev = cur_node
            cur_node = cur_node.next
            count +=1

        if cur_node is None:
            return

        prev.next = cur_node.next
        cur_node = None

    def len_iterative(self):
        count = 0
        cur_node = self.head

        while cur_node:
            count += 1
            cur_node = cur_node.next
        return count

    def len_recursive(self, node):
        if node is None:
            return 0
        return 1 + self.len_recursive(node.next)

    def sum_two_lists(self, llist):
        p = self.head
        q = llist.head

        sum_llist = LinkedList()

        carry = 0
        while p or q:
            if not p:
                i = 0
            else:
                i = p.data
            if not q:
                j = 0
            else:
                j = q.data
            s = i + j + carry
            if s >= 10:
                carry = 1
                remainder = s % 10
                sum_llist.insert_to_end(remainder)
            else:
                carry = 0
                sum_llist.insert_to_end(s)
            if p:
                p = p.next
            if q:
                q = q.next
        sum_llist.print_list()
# 3 6 5 
#   4 2 
# ------
#  


llist = LinkedList()
llist.insert_to_end("A")
llist.insert_to_end("B")
llist.insert_to_end("C")
llist.insert_to_end("D")
#llist.delete_node("B")
print(llist.len_recursive(llist.head))
print(llist.len_iterative())
llist.print_list()

# llist1 = LinkedList()
# llist1.insert_to_end(5)
# llist1.insert_to_end(6)
# llist1.insert_to_end(3)

# llist2 = LinkedList()
# llist2.insert_to_end(8)
# llist2.insert_to_end(4)
# llist2.insert_to_end(2)


# llist1.sum_two_lists(llist2)




