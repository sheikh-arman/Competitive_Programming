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
		var tm=0
        if n<k{
            tm=n
            n=k
            k=tm
        }
        var ans=99999999999999
        var ma=0
        for 
		test = test + 1
	}
}
