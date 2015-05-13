#ifndef _range_h
#define _range_h

#include <iostream>

#include "src/util/c99_stdint.h"
#include "src/util/forbid_copy.h"
#include "src/util/free_list.h"

namespace re2c
{

class Range
{

public:
	Range		*next;
	uint32_t	lb, ub;	// [lb,ub)

	static free_list<Range*> vFreeList;

public:
	Range(uint32_t l, uint32_t u) : next(NULL), lb(l), ub(u)
	{
		vFreeList.insert(this);
	}

	Range(Range &r) : next(NULL), lb(r.lb), ub(r.ub)
	{
		vFreeList.insert(this);
	}

	~Range()
	{
		vFreeList.erase(this);
	}

	FORBID_COPY (Range);
};

Range *doUnion(Range *r1, Range *r2);
Range *doDiff(Range *r1, Range *r2);

} // end namespace re2c

#endif
