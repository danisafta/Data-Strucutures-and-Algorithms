package StackLinkedList

type Node struct {
	info int
	next *Node
}

type Stack struct {
	top *Node
}

func (list *Stack) Push(i int) {
	data := &Node{info: i}
	if list.top != nil {
		data.next = list.top
	}
	list.top = data
}

func (list *Stack) Pop() (int, bool) {
	if list.top == nil {
		return 0, false
	}
	i := list.top.info
	list.top = list.top.next

	return i, true
}

func (list *Stack) Top() (int, bool) {
	if list.top == nil {
		return 0, false
	}
	return list.top.info, true
}

func (list *Stack) getItems() []int {
	var items []int
	current := list.top
	for current != nil {
		items = append(items, current.info)
		current = current.next
	}
	return items
}

func (list *Stack) isEmpty() bool {
	return list.top == nil
}

func (list *Stack) Destory() bool {
	return list.top=nil
}
