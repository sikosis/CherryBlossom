/*
 * Copyright (c) 2010, Bryce Groff.
 * Copyright (c) 2026, Cherry Blossom contributors.
 * Distributed under the terms of the MIT licence.
 */

#ifndef CHERRY_BLOSSOM_WINDOW_H
#define CHERRY_BLOSSOM_WINDOW_H

#include <Window.h>


class BMenuBar;
class MusicView;
class PlayListView;


class CherryBlossomWindow : public BWindow {
public:
	CherryBlossomWindow();
	virtual ~CherryBlossomWindow();

	virtual void MessageReceived(BMessage* message);
	virtual bool QuitRequested();

private:
	BMenuBar* _CreateMainMenu();
	void _CreateGUI();

	PlayListView* fPlaylistView;
	MusicView* fMusicView;
	uint32 fPlaylistCount;
};


#endif
