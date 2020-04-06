func threeSum(nums []int) [][]int {
    sn := qsort(nums)
    // sn := nums
    // sort.Ints(sn)
    ln := len(nums)

    rn := make([][]int, 0, 20)

    for x := 0; x < ln - 2; x++ {

        if sn[x] > 0 {
            break
        }

        if x > 0 && sn[x] == sn[x-1] {
            continue
        }

        y := x + 1
        z := ln - 1
        for ;y < z; {
            if sn[x] > 0 && sn[y] > 0 {
                break
            }
            t := sn[x] + sn[y] + sn[z]
            if t > 0 {
                z--
            } else if t < 0 {
                y++
            } else {
                en := []int{sn[x], sn[y], sn[z]}
                rn = append(rn, en)

                for y = y + 1; y < z; y++ {
                    if sn[y] != sn[y-1] {
                        break
                    }
                }
                for z = z - 1; y < z; z-- {
                    if sn[z] != sn[z+1] {
                        break
                    }
                }
            }
        }
    }
    return rn
}

func qsort(nums []int) []int {

    l := len(nums)

    if l < 2 {
        return nums
    }

    a := make([]int, 0, l - 1)
    b := make([]int, 0, l - 1)
    r := make([]int, 0, l)
    // r := nums[0:0]

    t := l / 2
    for i := 0; i < l; i++ {
        if i == t {
            continue
        }
        if nums[i] < nums[t] {
            a = append(a, nums[i])
        } else {
            b = append(b, nums[i])
        }
    }

    a = qsort(a)
    b = qsort(b)

    r = append(r, a...)
    r = append(r, nums[t])
    r = append(r, b...)

    return r
}
