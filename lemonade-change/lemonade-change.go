func lemonadeChange(bills []int) bool {
    var five, ten int
    for i := 0; i < len(bills); i++ {
        if bills[i] == 5 {
            five++
        } else if bills[i] == 10 && five > 0 {
            five--
            ten++
        } else if bills[i] == 20 && five > 0 && ten > 0 {
            five--
            ten--
        } else if bills[i] == 20 && five > 2 {
            five -= 3
        } else {
            return false
        }
    }
    return true
}
