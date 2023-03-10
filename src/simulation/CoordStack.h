/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <cstdlib>
#include <exception>

class CoordStackOverflowException: public std::exception
{
public:
	CoordStackOverflowException() { }
	const char* what() const throw() override
	{
		return "Maximum number of entries in the coordinate stack was exceeded";
	}
	~CoordStackOverflowException() throw() {}
};

class CoordStack
{
private:
	unsigned short (*stack)[2];
	int stack_size;
	const static int stack_limit = XRES*YRES;
public:
	CoordStack() :
		stack(NULL),
		stack_size(0)
	{
		stack = new unsigned short[stack_limit][2];
	}
	~CoordStack()
	{
		delete[] stack;
	}
	void push(int x, int y)
	{
		if (stack_size>=stack_limit)
			throw CoordStackOverflowException();
		stack[stack_size][0] = x;
		stack[stack_size][1] = y;
		stack_size++;
	}
	void pop(int& x, int& y)
	{
		stack_size--;
		x = stack[stack_size][0];
		y = stack[stack_size][1];
	}
	int getSize() const
	{
		return stack_size;
	}
	void clear()
	{
		stack_size = 0;
	}
};
