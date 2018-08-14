package main

import (
	"fmt"
)

type Cell struct {
	info int
	next *Cell
}

type Stack struct {
	top *Cell
}

func (list *Stack) Push(i int) {
	data := &Cell{info: i}
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

func (list *Stack) Destory() {
	list.top = nil
}

func main() {
	node := &Cell{info: 1}
	stack := &Stack{top: node}
	stack.Push(2)
	stack.Push(1)
	stack.Push(3)
	x := stack.getItems()
	fmt.Print(x)
}
