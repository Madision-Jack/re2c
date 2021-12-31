/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -cfi --loop-switch -Wno-nondeterministic-tags

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum YYCONDTYPE {
	yycmedia_type = 0,
	yycheader = 29,
};


struct mtag {
    struct mtag* prev;
    int          dist;
};

struct mtagpool {
    struct mtag* head;
    struct mtag* next;
    struct mtag* last;
};

enum con_status {
    CON_STATUS_WAITING,
    CON_STATUS_DONE,
    CON_STATUS_END,
    CON_STATUS_ERROR
};

#define CON_STATE_SIZE  (4096-32)
typedef struct con_state {
    unsigned char*  cur;
    unsigned char*  mar;
    unsigned char*  tok;
    unsigned char*  lim;
    int             cond;
    int             state;
    struct mtagpool mtp;
    	unsigned char*		yyt1;
	unsigned char*		yyt2;

    	struct mtag				*yytm1;
	struct mtag				*yytm10;
	struct mtag				*yytm2;
	struct mtag				*yytm3;
	struct mtag				*yytm4;
	struct mtag				*yytm5;
	struct mtag				*yytm6;
	struct mtag				*yytm7;
	struct mtag				*yytm8;
	struct mtag				*yytm9;

    size_t          buf_size;
    unsigned char*  buf;
    unsigned char   static_buf[];
} con_state;
#define CON_READ_BUF_LEN  (CON_STATE_SIZE - sizeof(struct con_state) - 1) // -1: ensure a sentinel at the end of buf

static void mtagpool_init(struct mtagpool* mtp)
{
    static const unsigned size = 1024 * 1024;
    mtp->head = (struct mtag*)malloc(size * sizeof(struct mtag));
    mtp->next = mtp->head;
    mtp->last = mtp->head + size;
}

static void mtagpool_free(struct mtagpool* mtp)
{
    free(mtp->head);
    mtp->head = mtp->next = mtp->last = NULL;
}

static struct mtag* mtagpool_next(struct mtagpool* mtp)
{
    unsigned     size;
    struct mtag* head;

    if (mtp->next < mtp->last) return mtp->next++;

    size = mtp->last - mtp->head;
    head = (struct mtag*)malloc(2 * size * sizeof(struct mtag));
    memcpy(head, mtp->head, size * sizeof(struct mtag));
    free(mtp->head);
    mtp->head = head;
    mtp->next = head + size;
    mtp->last = head + size * 2;

    return mtp->next++;
}

static void mtag(struct mtag** pmt, const unsigned char* b, const unsigned char* t, struct mtagpool* mtp)
{
    struct mtag* mt = mtagpool_next(mtp);
    mt->prev = *pmt;
    mt->dist = t - b;
    *pmt = mt;
}

static enum con_status parse_con_req(struct con_state* c)
{
    unsigned int        yych, yyaccept;
    const unsigned char *l1, *l2;
    struct mtag         *f1, *f2, *p1, *p2, *p3, *p4;

    

	int yystate = c->state;
	for (;;) {
		switch (yystate) {
			case -1:
			case 0:
				yych = *c->cur;
				switch (yych) {
					case '!':
					case '#':
					case '$':
					case '%':
					case '&':
					case '\'':
					case '*':
					case '+':
					case '-':
					case '.':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '^':
					case '_':
					case '`':
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case '|':
					case '~':
						c->yyt1 = c->cur;
						++c->cur;
						yystate = 3;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 57;
							return CON_STATUS_WAITING;
						}
						++c->cur;
						yystate = 1;
						continue;
				}
			case 1:
				yystate = 2;
				continue;
			case 2:
				c->state = yycmedia_type;
				{ return CON_STATUS_ERROR; }
			case 3:
				c->mar = c->cur;
				yych = *c->cur;
				switch (yych) {
					case '!':
					case '#':
					case '$':
					case '%':
					case '&':
					case '\'':
					case '*':
					case '+':
					case '-':
					case '.':
					case '/':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '^':
					case '_':
					case '`':
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case '|':
					case '~':
						yystate = 5;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 58;
							return CON_STATUS_WAITING;
						}
						yystate = 2;
						continue;
				}
			case 4:
				yych = *c->cur;
				yystate = 5;
				continue;
			case 5:
				switch (yych) {
					case '!':
					case '#':
					case '$':
					case '%':
					case '&':
					case '\'':
					case '*':
					case '+':
					case '-':
					case '.':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '^':
					case '_':
					case '`':
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case '|':
					case '~':
						++c->cur;
						yystate = 4;
						continue;
					case '/':
						++c->cur;
						yystate = 7;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 59;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 6:
				c->cur = c->mar;
				yystate = 2;
				continue;
			case 7:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case '\t':
					case '\r':
					case ' ':
					case ';':
						if (c->lim <= c->cur) {
							c->state = 60;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
					default:
						yystate = 9;
						continue;
				}
			case 8:
				yych = *c->cur;
				yystate = 9;
				continue;
			case 9:
				switch (yych) {
					case '\t':
					case ' ':
						c->yytm6 = c->yytm10;
						mtag(&c->yytm6, c->tok, NULL, &c->mtp);
						c->yytm5 = c->yytm9;
						mtag(&c->yytm5, c->tok, NULL, &c->mtp);
						c->yytm4 = c->yytm8;
						mtag(&c->yytm4, c->tok, NULL, &c->mtp);
						c->yytm3 = c->yytm7;
						mtag(&c->yytm3, c->tok, NULL, &c->mtp);
						c->yyt2 = c->cur;
						++c->cur;
						yystate = 10;
						continue;
					case '\r':
						c->yytm6 = c->yytm10;
						mtag(&c->yytm6, c->tok, NULL, &c->mtp);
						c->yytm5 = c->yytm9;
						mtag(&c->yytm5, c->tok, NULL, &c->mtp);
						c->yytm4 = c->yytm8;
						mtag(&c->yytm4, c->tok, NULL, &c->mtp);
						c->yytm3 = c->yytm7;
						mtag(&c->yytm3, c->tok, NULL, &c->mtp);
						c->yyt2 = c->cur;
						++c->cur;
						yystate = 12;
						continue;
					case '!':
					case '#':
					case '$':
					case '%':
					case '&':
					case '\'':
					case '*':
					case '+':
					case '-':
					case '.':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '^':
					case '_':
					case '`':
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case '|':
					case '~':
						++c->cur;
						yystate = 8;
						continue;
					case ';':
						c->yyt2 = c->cur;
						++c->cur;
						yystate = 13;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 61;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 10:
				yych = *c->cur;
				switch (yych) {
					case '\t':
					case ' ':
						++c->cur;
						yystate = 10;
						continue;
					case '\r':
						++c->cur;
						yystate = 12;
						continue;
					case ';':
						++c->cur;
						yystate = 13;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 62;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 12:
				yych = *c->cur;
				switch (yych) {
					case '\n':
						++c->cur;
						yystate = 15;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 63;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 13:
				yych = *c->cur;
				switch (yych) {
					case '\t':
					case ' ':
						++c->cur;
						yystate = 13;
						continue;
					case '!':
					case '#':
					case '$':
					case '%':
					case '&':
					case '\'':
					case '*':
					case '+':
					case '-':
					case '.':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '^':
					case '_':
					case '`':
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case '|':
					case '~':
						mtag(&c->yytm7, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 17;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 64;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 15:
				l1 = c->yyt1;
				l2 = c->yyt2;
				p1 = c->yytm3;
				p2 = c->yytm4;
				p3 = c->yytm5;
				p4 = c->yytm6;
				c->state = yycmedia_type;
				{
            struct mtag*    pname_start = p1;
            struct mtag*    pname_end   = p2;
            struct mtag*    pval_start  = p3;
            struct mtag*    pval_end    = p4;

            printf("media type: %.*s\n", (int)(l2-l1), l1);

            while (0 && pname_start) {
                printf("\t(%.*s) = (%.*s)\n",
                    pname_end->dist - pname_start->dist, c->tok + pname_start->dist,
                    pval_end->dist - pval_start->dist, c->tok + pval_start->dist);

                pname_start = pname_start->prev;
                pname_end = pname_end->prev;
                pval_start = pval_start->prev;
                pval_end = pval_end->prev;
            }

            return CON_STATUS_DONE;
        }
			case 17:
				yych = *c->cur;
				switch (yych) {
					case '!':
					case '#':
					case '$':
					case '%':
					case '&':
					case '\'':
					case '*':
					case '+':
					case '-':
					case '.':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '^':
					case '_':
					case '`':
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case '|':
					case '~':
						++c->cur;
						yystate = 17;
						continue;
					case '=':
						mtag(&c->yytm8, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 19;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 65;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 19:
				yych = *c->cur;
				switch (yych) {
					case '!':
					case '#':
					case '$':
					case '%':
					case '&':
					case '\'':
					case '*':
					case '+':
					case '-':
					case '.':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '^':
					case '_':
					case '`':
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case '|':
					case '~':
						mtag(&c->yytm9, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 20;
						continue;
					case '"':
						mtag(&c->yytm9, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 22;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 66;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 20:
				yych = *c->cur;
				switch (yych) {
					case '\t':
					case ' ':
						mtag(&c->yytm10, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 24;
						continue;
					case '\r':
						c->yytm3 = c->yytm7;
						c->yytm4 = c->yytm8;
						c->yytm5 = c->yytm9;
						c->yytm6 = c->yytm10;
						mtag(&c->yytm6, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 12;
						continue;
					case '!':
					case '#':
					case '$':
					case '%':
					case '&':
					case '\'':
					case '*':
					case '+':
					case '-':
					case '.':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '^':
					case '_':
					case '`':
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case '|':
					case '~':
						++c->cur;
						yystate = 20;
						continue;
					case ';':
						mtag(&c->yytm10, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 13;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 67;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 22:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case '\r':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x1F:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 68;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
					case '"':
						++c->cur;
						yystate = 26;
						continue;
					case '\\':
						++c->cur;
						yystate = 27;
						continue;
					default:
						++c->cur;
						yystate = 22;
						continue;
				}
			case 24:
				yych = *c->cur;
				switch (yych) {
					case '\t':
					case ' ':
						++c->cur;
						yystate = 24;
						continue;
					case '\r':
						c->yytm3 = c->yytm7;
						c->yytm4 = c->yytm8;
						c->yytm5 = c->yytm9;
						c->yytm6 = c->yytm10;
						++c->cur;
						yystate = 12;
						continue;
					case ';':
						++c->cur;
						yystate = 13;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 69;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 26:
				yych = *c->cur;
				switch (yych) {
					case '\t':
					case ' ':
						mtag(&c->yytm10, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 24;
						continue;
					case '\r':
						c->yytm3 = c->yytm7;
						c->yytm4 = c->yytm8;
						c->yytm5 = c->yytm9;
						c->yytm6 = c->yytm10;
						mtag(&c->yytm6, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 12;
						continue;
					case ';':
						mtag(&c->yytm10, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 13;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 70;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
				}
			case 27:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case '\r':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 71;
							return CON_STATUS_WAITING;
						}
						yystate = 6;
						continue;
					default:
						++c->cur;
						yystate = 22;
						continue;
				}
			case 28:
				c->state = yycmedia_type;
				{ return CON_STATUS_END; }
			case 29:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\t':
					case '\n':
					case '\v':
					case '\f':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 72;
							return CON_STATUS_WAITING;
						}
						++c->cur;
						yystate = 30;
						continue;
					case '\r':
						mtag(&c->yytm1, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 32;
						continue;
					default:
						++c->cur;
						yystate = 33;
						continue;
				}
			case 30:
				yystate = 31;
				continue;
			case 31:
				c->state = yycheader;
				{ return CON_STATUS_ERROR; }
			case 32:
				yyaccept = 0;
				c->mar = c->cur;
				yych = *c->cur;
				switch (yych) {
					case '\n':
						++c->cur;
						yystate = 34;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 73;
							return CON_STATUS_WAITING;
						}
						yystate = 31;
						continue;
				}
			case 33:
				yyaccept = 0;
				c->mar = c->cur;
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 74;
							return CON_STATUS_WAITING;
						}
						yystate = 31;
						continue;
					case '\t':
						++c->cur;
						yystate = 36;
						continue;
					case '\r':
						mtag(&c->yytm1, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 38;
						continue;
					default:
						++c->cur;
						yystate = 39;
						continue;
				}
			case 34:
				yych = *c->cur;
				switch (yych) {
					case '\t':
					case ' ':
						++c->cur;
						yystate = 41;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 75;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
				}
			case 35:
				c->cur = c->mar;
				if (yyaccept == 0) {
					yystate = 31;
					continue;
				} else {
					yystate = 48;
					continue;
				}
			case 36:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case '\r':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 76;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
					case '\t':
						++c->cur;
						yystate = 36;
						continue;
					case ' ':
						++c->cur;
						yystate = 39;
						continue;
					default:
						++c->cur;
						yystate = 43;
						continue;
				}
			case 38:
				yych = *c->cur;
				switch (yych) {
					case '\n':
						++c->cur;
						yystate = 34;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 77;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
				}
			case 39:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 78;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
					case '\t':
						++c->cur;
						yystate = 36;
						continue;
					case '\r':
						mtag(&c->yytm1, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 38;
						continue;
					default:
						++c->cur;
						yystate = 39;
						continue;
				}
			case 41:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 79;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
					case '\t':
					case ' ':
						++c->cur;
						yystate = 41;
						continue;
					case '\r':
						mtag(&c->yytm3, c->tok, c->cur, &c->mtp);
						c->yytm2 = c->yytm1;
						mtag(&c->yytm2, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 44;
						continue;
					default:
						mtag(&c->yytm3, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 45;
						continue;
				}
			case 43:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\t':
					case '\n':
					case '\v':
					case '\f':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 80;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
					case '\r':
						mtag(&c->yytm1, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 38;
						continue;
					default:
						++c->cur;
						yystate = 39;
						continue;
				}
			case 44:
				yych = *c->cur;
				switch (yych) {
					case '\n':
						++c->cur;
						yystate = 47;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 81;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
				}
			case 45:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 82;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
					case '\t':
						++c->cur;
						yystate = 49;
						continue;
					case '\r':
						c->yytm2 = c->yytm1;
						mtag(&c->yytm2, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 44;
						continue;
					default:
						++c->cur;
						yystate = 45;
						continue;
				}
			case 47:
				yyaccept = 1;
				c->mar = c->cur;
				yych = *c->cur;
				switch (yych) {
					case '\t':
					case ' ':
						c->yytm1 = c->yytm2;
						++c->cur;
						yystate = 41;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 83;
							return CON_STATUS_WAITING;
						}
						yystate = 48;
						continue;
				}
			case 48:
				f1 = c->yytm1;
				f2 = c->yytm3;
				c->state = yycheader;
				{
            struct mtag*    fold_start  = f1;
            struct mtag*    fold_end    = f2;

            while (fold_start) {
                memset(c->tok + fold_start->dist, ' ', fold_end->dist - fold_start->dist);
                fold_start  = fold_start->prev;
                fold_end    = fold_end->prev;
            }

            return CON_STATUS_DONE;
        }
			case 49:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 84;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
					case '\t':
						++c->cur;
						yystate = 49;
						continue;
					case '\r':
						++c->cur;
						yystate = 51;
						continue;
					case ' ':
						++c->cur;
						yystate = 45;
						continue;
					default:
						++c->cur;
						yystate = 52;
						continue;
				}
			case 51:
				yych = *c->cur;
				switch (yych) {
					case '\n':
						++c->cur;
						yystate = 53;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 85;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
				}
			case 52:
				yych = *c->cur;
				switch (yych) {
					case 0x00:
					case 0x01:
					case 0x02:
					case 0x03:
					case 0x04:
					case 0x05:
					case 0x06:
					case 0x07:
					case 0x08:
					case '\n':
					case '\v':
					case '\f':
					case 0x0E:
					case 0x0F:
					case 0x10:
					case 0x11:
					case 0x12:
					case 0x13:
					case 0x14:
					case 0x15:
					case 0x16:
					case 0x17:
					case 0x18:
					case 0x19:
					case 0x1A:
					case 0x1B:
					case 0x1C:
					case 0x1D:
					case 0x1E:
					case 0x7F:
						if (c->lim <= c->cur) {
							c->state = 86;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
					case '\t':
						++c->cur;
						yystate = 54;
						continue;
					case '\r':
						c->yytm2 = c->yytm1;
						mtag(&c->yytm2, c->tok, c->cur, &c->mtp);
						++c->cur;
						yystate = 44;
						continue;
					default:
						++c->cur;
						yystate = 45;
						continue;
				}
			case 53:
				yystate = 48;
				continue;
			case 54:
				yych = *c->cur;
				switch (yych) {
					case '\t':
					case ' ':
						++c->cur;
						yystate = 54;
						continue;
					case '\r':
						++c->cur;
						yystate = 51;
						continue;
					default:
						if (c->lim <= c->cur) {
							c->state = 87;
							return CON_STATUS_WAITING;
						}
						yystate = 35;
						continue;
				}
			case 56:
				c->state = yycheader;
				{ return CON_STATUS_END; }
			case 57:
				if (c->lim <= c->cur) {
					yystate = 28;
					continue;
				}
				yystate = 0;
				continue;
			case 58:
				if (c->lim <= c->cur) {
					yystate = 2;
					continue;
				}
				yystate = 3;
				continue;
			case 59:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 4;
				continue;
			case 60:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 7;
				continue;
			case 61:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 8;
				continue;
			case 62:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 10;
				continue;
			case 63:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 12;
				continue;
			case 64:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 13;
				continue;
			case 65:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 17;
				continue;
			case 66:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 19;
				continue;
			case 67:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 20;
				continue;
			case 68:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 22;
				continue;
			case 69:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 24;
				continue;
			case 70:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 26;
				continue;
			case 71:
				if (c->lim <= c->cur) {
					yystate = 6;
					continue;
				}
				yystate = 27;
				continue;
			case 72:
				if (c->lim <= c->cur) {
					yystate = 56;
					continue;
				}
				yystate = 29;
				continue;
			case 73:
				if (c->lim <= c->cur) {
					yystate = 31;
					continue;
				}
				yystate = 32;
				continue;
			case 74:
				if (c->lim <= c->cur) {
					yystate = 31;
					continue;
				}
				yystate = 33;
				continue;
			case 75:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 34;
				continue;
			case 76:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 36;
				continue;
			case 77:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 38;
				continue;
			case 78:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 39;
				continue;
			case 79:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 41;
				continue;
			case 80:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 43;
				continue;
			case 81:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 44;
				continue;
			case 82:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 45;
				continue;
			case 83:
				if (c->lim <= c->cur) {
					yystate = 48;
					continue;
				}
				yystate = 47;
				continue;
			case 84:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 49;
				continue;
			case 85:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 51;
				continue;
			case 86:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 52;
				continue;
			case 87:
				if (c->lim <= c->cur) {
					yystate = 35;
					continue;
				}
				yystate = 54;
				continue;
		}
	}

}

int feed(struct con_state* c, const unsigned char* chunk, int len)
{
    const size_t shift = c->tok - c->buf;
    const size_t free = c->buf_size - (c->lim - c->tok);

    if (free < len) {
        fprintf(stderr, "Token too long for receive buffer: %ld\n", c->buf_size);
        return 1;
    }

    if (shift) {
        memmove(c->buf, c->tok, c->buf_size - shift);
        c->lim -= shift;
        c->cur -= shift;
        c->mar -= shift;
        c->tok -= shift;
        			if (c->yyt1) c->yyt1 -= shift;
			if (c->yyt2) c->yyt2 -= shift;

    }

    memcpy(c->lim, chunk, len);

    c->lim += len;
    c->lim[0] = 0;  // Append sentinel

    return 0;
}

int main(int argc, char** argv)
{
    int rc = 0;
    int i;
    struct con_state* c = NULL;
    static const char* chunks[] = {
        "ap",
        "plication/j",
        "son;",
        " charset=\"",
        "utf\\\"-8\"\r",
        "\n",
        "",
        NULL
    };

    c = (con_state*)malloc(CON_STATE_SIZE);
    c->buf = c->static_buf;
    c->cur = c->mar = c->tok = c->lim = c->buf + CON_READ_BUF_LEN;
    c->lim[0] = 0; // sentinel
    c->state = -1;
    c->buf_size = CON_READ_BUF_LEN;
    	c->yyt1 = 0;
	c->yyt2 = 0;

    	c->yytm1 = NULL;
	c->yytm10 = NULL;
	c->yytm2 = NULL;
	c->yytm3 = NULL;
	c->yytm4 = NULL;
	c->yytm5 = NULL;
	c->yytm6 = NULL;
	c->yytm7 = NULL;
	c->yytm8 = NULL;
	c->yytm9 = NULL;

    mtagpool_init(&c->mtp);

    for (i=0;;) {
        switch (parse_con_req(c)) {
            case CON_STATUS_WAITING:
                printf("waiting\n");
                rc = feed(c, (const unsigned char*)chunks[i], strlen(chunks[i]));
                ++i;
                if (rc) goto finally;
                break;
            case CON_STATUS_DONE:
                printf("done\n");
                break;
            case CON_STATUS_END:
                printf("end\n");
                goto finally;
            case CON_STATUS_ERROR:
                printf("error\n");
                rc = 1;
                goto finally;
        }
    }

finally:
    if (c) {
        mtagpool_free(&c->mtp);
        free(c);
        c = NULL;
    }
    if (rc) fprintf(stderr, "Error exit: %d\n", rc);
    return rc;
}
codegen/loop_switch/c/storable_state_with_conditions.re:135:41: warning: tag 'p1' in condition 'media_type' has 2nd degree of nondeterminism [-Wnondeterministic-tags]
codegen/loop_switch/c/storable_state_with_conditions.re:135:41: warning: tag 'p2' in condition 'media_type' has 2nd degree of nondeterminism [-Wnondeterministic-tags]
codegen/loop_switch/c/storable_state_with_conditions.re:135:41: warning: tag 'p3' in condition 'media_type' has 2nd degree of nondeterminism [-Wnondeterministic-tags]
codegen/loop_switch/c/storable_state_with_conditions.re:135:41: warning: tag 'p4' in condition 'media_type' has 2nd degree of nondeterminism [-Wnondeterministic-tags]
codegen/loop_switch/c/storable_state_with_conditions.re:157:42: warning: tag 'f1' in condition 'header' has 2nd degree of nondeterminism [-Wnondeterministic-tags]
codegen/loop_switch/c/storable_state_with_conditions.re:157:42: warning: tag 'f2' in condition 'header' has 3rd degree of nondeterminism [-Wnondeterministic-tags]
