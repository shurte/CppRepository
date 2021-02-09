#pragma once

#include <string>

struct Link
{
	Link(const std::string & value, Link * prev, Link * next)
		: value(value)
		, prev(prev)
		, next(next)
	{}

	Link * next;
	Link * prev;
	std::string value;
};

Link * insert(Link * newLink, Link * linkAfter)
{
	if (linkAfter == 0) return newLink;
	if (newLink == 0) return linkAfter;

	if (linkAfter->prev != 0)
	{
		linkAfter->prev->next = newLink;
	}

	newLink->prev = linkAfter->prev;
	linkAfter->prev = newLink;
	newLink->next = linkAfter;

	return newLink;
};