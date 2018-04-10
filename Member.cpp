#include "Member.h"

using namespace std;

int Member::totalUsers = 0;
/**
*default constructor
*/
Member::Member() {
	//Increase number of the user.
	totalUsers++;
}

/**
* The destructor go through sets followers and following of the object that deleted
* and deletes this member from the sets followers and following of the other members.
*/
Member::~Member() {
	totalUsers--;

	set<Member*>::iterator pointer;
	for (pointer = following.begin(); pointer != following.end(); pointer++)
	{
		(*pointer)->followers.erase(this);
	}
	for (pointer = followers.begin(); pointer != followers.end(); pointer++)
	{
		(*pointer)->following.erase(this);
	}
}

int Member::count() {
	return totalUsers;
}

int Member::numFollowers() const {
	int numFollowers = followers.size();
	return numFollowers;
}

int Member::numFollowing() const {
	int numFollowing = following.size();
	return numFollowing;
}

void Member::addToFollowers(Member& o) {//o is for other
	followers.insert(&o);
}

void Member::deleteFromFollowers(Member& o) {//o is for other
	followers.erase(&o);
}


void Member::follow(Member& o) {//o is for other

	if (&o == this)
		return;

	if (following.find(&o) == following.end()) {
		following.insert(&o);
		o.addToFollowers(*this);
	}
}


void Member::unfollow(Member& o) {//o is for other

	if (&o == this)
		return;

	if (following.find(&o) != following.end())
	{
		following.erase(&o);
		o.deleteFromFollowers(*this);
	}
}
