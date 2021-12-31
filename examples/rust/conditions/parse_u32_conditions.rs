/* Generated by re2c */
// re2rust $INPUT -o $OUTPUT -c


const YYC_INIT: usize = 0;
const YYC_BIN: usize = 14;
const YYC_DEC: usize = 21;
const YYC_HEX: usize = 28;
const YYC_OCT: usize = 39;



const ERROR: u64 = std::u32::MAX as u64 + 1;

fn add(num: u64, dgt: u8, base: u64) -> u64 {
    return std::cmp::min(num * base + dgt as u64, ERROR)
}

fn parse_u32(s: &[u8]) -> Option<u32> {
    let mut cur = 0;
    let mut mar = 0;
    let mut cond = YYC_INIT;
    let mut num = 0u64;

    'lex : loop {
{
	#[allow(unused_assignments)]
	let mut yych : u8 = 0;
	let mut yystate : usize = cond;
	loop {
		match yystate {
			0 => {
				yych = unsafe {*s.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x30 => {
						yystate = 3;
						continue;
					}
					0x31 ..= 0x39 => {
						yystate = 5;
						continue;
					}
					_ => {
						yystate = 1;
						continue;
					}
				}
			}
			1 => { return None; }
			3 => {
				mar = cur;
				yych = unsafe {*s.get_unchecked(cur)};
				match yych {
					0x42 |
					0x62 => {
						cur += 1;
						yystate = 7;
						continue;
					}
					0x58 |
					0x78 => {
						cur += 1;
						yystate = 9;
						continue;
					}
					_ => {
						yystate = 4;
						continue;
					}
				}
			}
			4 => {
				cond = YYC_OCT;
				yystate = YYC_OCT;
				continue;
			}
			5 => {
				cur = (cur as isize + -1) as usize;
				cond = YYC_DEC;
				yystate = YYC_DEC;
				continue;
			}
			7 => {
				yych = unsafe {*s.get_unchecked(cur)};
				match yych {
					0x30 ..= 0x31 => {
						cur += 1;
						yystate = 10;
						continue;
					}
					_ => {
						yystate = 8;
						continue;
					}
				}
			}
			8 => {
				cur = mar;
				yystate = 4;
				continue;
			}
			9 => {
				yych = unsafe {*s.get_unchecked(cur)};
				match yych {
					0x30 ..= 0x39 |
					0x41 ..= 0x46 |
					0x61 ..= 0x66 => {
						cur += 1;
						yystate = 12;
						continue;
					}
					_ => {
						yystate = 8;
						continue;
					}
				}
			}
			10 => {
				cur = (cur as isize + -1) as usize;
				cond = YYC_BIN;
				yystate = YYC_BIN;
				continue;
			}
			12 => {
				cur = (cur as isize + -1) as usize;
				cond = YYC_HEX;
				yystate = YYC_HEX;
				continue;
			}
			14 => {
				yych = unsafe {*s.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x00 => {
						yystate = 15;
						continue;
					}
					0x30 ..= 0x31 => {
						yystate = 19;
						continue;
					}
					_ => {
						yystate = 17;
						continue;
					}
				}
			}
			15 => {
            return if num < ERROR { Some(num as u32) } else { None };
        }
			17 => { return None; }
			19 => { num = add(num, s[cur-1] - 48, 2);  continue 'lex; }
			21 => {
				yych = unsafe {*s.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x00 => {
						yystate = 22;
						continue;
					}
					0x30 ..= 0x39 => {
						yystate = 26;
						continue;
					}
					_ => {
						yystate = 24;
						continue;
					}
				}
			}
			22 => {
            return if num < ERROR { Some(num as u32) } else { None };
        }
			24 => { return None; }
			26 => { num = add(num, s[cur-1] - 48, 10); continue 'lex; }
			28 => {
				yych = unsafe {*s.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x00 => {
						yystate = 29;
						continue;
					}
					0x30 ..= 0x39 => {
						yystate = 33;
						continue;
					}
					0x41 ..= 0x46 => {
						yystate = 35;
						continue;
					}
					0x61 ..= 0x66 => {
						yystate = 37;
						continue;
					}
					_ => {
						yystate = 31;
						continue;
					}
				}
			}
			29 => {
            return if num < ERROR { Some(num as u32) } else { None };
        }
			31 => { return None; }
			33 => { num = add(num, s[cur-1] - 48, 16); continue 'lex; }
			35 => { num = add(num, s[cur-1] - 55, 16); continue 'lex; }
			37 => { num = add(num, s[cur-1] - 87, 16); continue 'lex; }
			39 => {
				yych = unsafe {*s.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x00 => {
						yystate = 40;
						continue;
					}
					0x30 ..= 0x37 => {
						yystate = 44;
						continue;
					}
					_ => {
						yystate = 42;
						continue;
					}
				}
			}
			40 => {
            return if num < ERROR { Some(num as u32) } else { None };
        }
			42 => { return None; }
			44 => { num = add(num, s[cur-1] - 48, 8);  continue 'lex; }
			_ => {
				panic!("internal lexer error")
			}
		}
	}
}
}
}

fn main() {
    assert_eq!(parse_u32(b"1234567890\0"), Some(1234567890));
    assert_eq!(parse_u32(b"0b1101\0"), Some(13));
    assert_eq!(parse_u32(b"0x7Fe\0"), Some(2046));
    assert_eq!(parse_u32(b"0644\0"), Some(420));
    assert_eq!(parse_u32(b"9999999999\0"), None);
    assert_eq!(parse_u32(b"\0"), None);
}
