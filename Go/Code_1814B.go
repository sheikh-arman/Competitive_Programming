package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var tcase = 0
	fmt.Fscan(in, &tcase)
	var test = 0
	for test < tcase {
		var (
			n = 0
			k = 0
		)
		fmt.Fscan(in, &n)
		fmt.Fscan(in, &k)
		var tm = 0
		if n < k {
			tm = n
			n = k
			k = tm
		}
		var ans = 99999999999999
		var rang = n + k
		if rang > 100000 {
			rang = 100000
		}
		var i = 1
		for i <= rang {
			var cnt = (n / i) + (i - 1)
			if n%i!=0 {
				cnt+=1
			}
			if i >= k {
				cnt += 1
			} else {
				cnt += (k / i) 
				if k%i!=0 {
					cnt+=1
				}
			}
			if cnt < ans {
				ans = cnt
			}
			i+=1
		}
		fmt.Printf("%v\n", ans)
		test = test + 1
	}

}
