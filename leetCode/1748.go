package main

import "fmt"

func sumOfUnique(nums []int) int {

    var s = make(map[int]int)

    for _, value := range nums {
        s[value] += 1
    }

    var sum int
    for key, value := range s {

        if value < 2 {
            sum += key
        }
    }

    return sum
}

func main() {
    nums := [...]int{1,2,3,2}

    result := sumOfUnique(nums[:])

    fmt.Println(result)
}