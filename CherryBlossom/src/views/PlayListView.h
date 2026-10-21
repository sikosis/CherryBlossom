/*
 * Copyright (c) 2010, Bryce Groff.
 * Copyright (c) 2026, Cherry Blossom contributors.
 * Distributed under the terms of the MIT licence.
 */

#ifndef PLAY_LIST_VIEW_H
#define PLAY_LIST_VIEW_H

#include <View.h>


class BListView;


class PlayListView : public BView {
public:
	explicit PlayListView(const char* name);
	virtual ~PlayListView();

	void AddPlaylist(const char* name);

private:
	BListView* fListView;
};


#endif
