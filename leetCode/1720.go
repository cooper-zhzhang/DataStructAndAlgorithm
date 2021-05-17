func decode(encoded []int, first int) []int {
    result := make([]int, len(encoded)+1, len(encoded)+1)

    result[0] = first
    
    for i, encodValue := range encoded {
        result[i+1] =  encodValue ^ result[i]
    }

    return result

}