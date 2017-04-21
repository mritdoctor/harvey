/*
 * Copyright 2015 - 2017 cinap_lenrek <cinap_lenrek@felloff.net>
 * Copyright 2017 HarveyOS
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "os.h"
#include <mp.h>
#include "dat.h"

mpint*
mpfield(mpint *N){
	Mfield *f;

	if(N == nil || N->flags & (MPfield|MPstatic))
		return N;
	if((f = cnfield(N)) != nil)
		goto Exchange;
	if((f = gmfield(N)) != nil)
		goto Exchange;
	return N;
Exchange:
	setmalloctag(f, getcallerpc());
	mpfree(N);
	return &(f->mpi);
}