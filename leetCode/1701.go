package main

import (
	"fmt"
)

func averageWaitingTime(customers [][]int) float64 {

	curTime := customers[0][0]// 记录当前时间点
	var waitingTime int64

    for _, customer := range customers {
			if customer[0] < curTime {
				// 排队的时间
				waitingTime += int64(curTime) - int64(customer[0])
			} else {
				// 厨师在等待
				curTime = customer[0]
			}

			curTime += customer[1]
			waitingTime += int64(customer[1])//做食物的时间
	}

	return (float64(waitingTime)) / float64(len(customers))
}

func main() {
	customers := [][]int {
		{2,3},//
		{6,3},// 
		{7,5},
		{11,3},
		{15,2},
		{18,1},
	}

	result := averageWaitingTime(customers)
	fmt.Println(result)
}