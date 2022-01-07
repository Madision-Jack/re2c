//go:generate re2go $INPUT -o $OUTPUT
package main

import "reflect"

type SemVer struct { major, minor, patch int }

func s2n(s string) int { // convert pre-parsed string to a number
	n := 0
	for _, c := range s { n = n*10 + int(c-'0') }
	return n
}

func parse(str string) *SemVer {
	var cur, mar int

	// User-defined tag variables that are available in semantic action.
	var t1, t2, t3, t4, t5 int

	// Autogenerated tag variables used by the lexer to track tag values.
	/*!stags:re2c format = 'var @@ int'; separator = "\n\t"; */

	/*!re2c
		re2c:yyfill:enable = 0;
		re2c:define:YYCTYPE     = byte;
		re2c:define:YYPEEK      = "str[cur]";
		re2c:define:YYSKIP      = "cur += 1";
		re2c:define:YYBACKUP    = "mar = cur";
		re2c:define:YYRESTORE   = "cur = mar";
		re2c:define:YYSTAGP     = "@@{tag} = cur";
		re2c:define:YYSTAGN     = "@@{tag} = -1";
		re2c:define:YYSHIFTSTAG = "@@{tag} += @@{shift}";
		re2c:tags = 1;

		num = [0-9]+;

		@t1 num @t2 "." @t3 num @t4 ("." @t5 num)? [\x00] {
			major := s2n(str[t1:t2])
			minor := s2n(str[t3:t4])
			patch := 0
			if t5 != -1 { patch = s2n(str[t5:cur-1]) }
			return &SemVer{major, minor, patch}
		}
		* { return nil }
	*/
}

func main() {
	assert_eq := func(x, y *SemVer) {
		if !reflect.DeepEqual(x, y) { panic("error") }
	}
	assert_eq(parse("23.34\000"), &SemVer{23, 34, 0})
	assert_eq(parse("1.2.9999\000"), &SemVer{1, 2, 9999})
	assert_eq(parse("1.a\000"), nil)
}
