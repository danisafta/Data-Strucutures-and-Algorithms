package main

import (
	"fmt"
	"os"
)

func main() {
	var nrElem int
	elems := make([]int, 100)
	fin, err := os.Open("date.in")
	if err != nil {
		panic(err)
	}
	fmt.Fscanf(fin, "%d", &nrElem)

	for i := 0; i < nrElem; i++ {
		fmt.Fscanf(fin, "%d", &elems[i])
	}
	fmt.Print(Kadane(elems))
}

func Kadane(v []int) int {
	localMax := 0
	globalMax := 0

	for _, el := range v {
		localMax += el
		if localMax < 0 {
			localMax = 0
		}
		if globalMax < localMax {
			globalMax = localMax
		}

	}
	return globalMax
}
