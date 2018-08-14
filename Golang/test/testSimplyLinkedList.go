package main

import (
	"fmt"
)

type Cell struct {
	info int
	next *Cell
}

type LinkedList struct {
	head *Cell
}

func (list *LinkedList) insertFirst(i int) {
	data := &Cell{info: i}
	if list.head == nil {
		list.head = data
		return
	}
	data.next = list.head
	list.head = data
}

func (list *LinkedList) insertLast(i int) {
	data := &Cell{info: i}
	if list.head == nil {
		list.head = data
		return
	}
	current := list.head
	for current.next != nil {
		current = current.next
	}
	current.next = data
}

func (list *LinkedList) removeByIndex(i int) bool {
	if list.head == nil {
		return false
	}
	if i < 0 {
		return false
	}
	if i == 0 {
		list.head = list.head.next
		return true
	}
	current := list.head
	for u := 1; u < i; u++ {
		if current.next.next == nil {
			return false
		}
		current = current.next
	}
	current.next = current.next.next
	return true
}

func (list *LinkedList) removeByValue(i int) bool {
	if list.head == nil {
		return false
	}
	if list.head.info == i {
		list.head = list.head.next
		return true
	}
	current := list.head

	for current.next != nil {
		if current.next.info == i {
			current.next = current.next.next
		}
		current = current.next
	}
	return false
}

func (list *LinkedList) searchValue(i int) bool {
	if list.head == nil {
		return false
	}
	current := list.head
	for current != nil {
		if current.info == i {
			return true
		}
		current = current.next
	}
	return false
}

func (list *LinkedList) getFirst() (int, bool) {
	if list.head == nil {
		return 0, false
	}
	return list.head.info, true
}

func (list *LinkedList) getLast() (int, bool) {
	if list.head == nil {
		return 0, false
	}
	current := list.head
	for current.next != nil {
		current = current.next
	}
	return current.info, true
}

func (list *LinkedList) getSize() int {
	if list.head == nil {
		return 0
	}
	count := 0
	current := list.head
	for current != nil {
		count++
		current = current.next
	}
	return count
}

func (list *LinkedList) getItems() []int {
	var items []int
	current := list.head
	for current != nil {
		items = append(items, current.info)
		current = current.next
	}
	return items
}

func main() {
	newNode := &Cell{info: 2}

	list := &LinkedList{head: newNode}

	list.insertFirst(4)
	list.insertLast(2)
	list.insertLast(21)
	list.insertLast(222)
	list.insertLast(21)
	list.insertLast(222)

	y := list.removeByValue(2)
	x := list.getItems()
	//x, _ := list.getLast()
	fmt.Println(x)
	fmt.Println(y)

}
