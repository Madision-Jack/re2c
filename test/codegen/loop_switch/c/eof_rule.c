/* Generated by re2c */
// re2c $INPUT -o $OUTPUT --loop-switch -i
#include <assert.h>

// expect a null-terminated string
static int lex(const char *str, unsigned int len)
{
    const char *YYCURSOR = str, *YYLIMIT = str + len, *YYMARKER;
    int count = 0;

loop:
    
{
	char yych;
	unsigned int yystate = 0;
	for (;;) {
		switch (yystate) {
			case 0:
				yych = *YYCURSOR;
				switch (yych) {
					case ' ':
						++YYCURSOR;
						yystate = 3;
						continue;
					case '\'':
						++YYCURSOR;
						yystate = 6;
						continue;
					default:
						if (YYLIMIT <= YYCURSOR) {
							yystate = 12;
							continue;
						}
						++YYCURSOR;
						yystate = 1;
						continue;
				}
			case 1:
				yystate = 2;
				continue;
			case 2:
				{ return -1; }
			case 3:
				yych = *YYCURSOR;
				switch (yych) {
					case ' ':
						++YYCURSOR;
						yystate = 3;
						continue;
					default:
						yystate = 5;
						continue;
				}
			case 5:
				{ goto loop; }
			case 6:
				YYMARKER = YYCURSOR;
				yych = *YYCURSOR;
				if (yych >= 0x01) {
					yystate = 8;
					continue;
				}
				if (YYLIMIT <= YYCURSOR) {
					yystate = 2;
					continue;
				}
				++YYCURSOR;
				yystate = 7;
				continue;
			case 7:
				yych = *YYCURSOR;
				yystate = 8;
				continue;
			case 8:
				switch (yych) {
					case '\'':
						++YYCURSOR;
						yystate = 9;
						continue;
					case '\\':
						++YYCURSOR;
						yystate = 11;
						continue;
					default:
						if (YYLIMIT <= YYCURSOR) {
							yystate = 13;
							continue;
						}
						++YYCURSOR;
						yystate = 7;
						continue;
				}
			case 9:
				{ ++count; goto loop; }
			case 11:
				yych = *YYCURSOR;
				if (yych <= 0x00) {
					if (YYLIMIT <= YYCURSOR) {
						yystate = 13;
						continue;
					}
					++YYCURSOR;
					yystate = 7;
					continue;
				}
				++YYCURSOR;
				yystate = 7;
				continue;
			case 12:
				{ return count; }
			case 13:
				YYCURSOR = YYMARKER;
				yystate = 2;
				continue;
		}
	}
}

}

#define TEST(s, r) assert(lex(s, sizeof(s) - 1) == r)
int main()
{
    TEST("", 0);
    TEST("'qu\0tes' 'are' 'fine: \\'' ", 3);
    TEST("'unterminated\\'", -1);
    return 0;
}
