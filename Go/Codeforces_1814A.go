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
		if n%k == 0 || n%2 == 0 || k%2 != 0 {
			fmt.Printf("YES\n")
		} else {
			fmt.Printf("NO\n")
		}
		test = test + 1
	}
}
