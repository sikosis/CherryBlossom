/*
 * Copyright (c) 2010, Bryce Groff.
 * Copyright (c) 2026, Cherry Blossom contributors.
 * Distributed under the terms of the MIT licence.
 */

#include "CherryBlossomWindow.h"

#include "views/MusicView.h"
#include "views/PlayListView.h"

#include <Application.h>
#include <LayoutBuilder.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <Message.h>
#include <SplitView.h>
#include <String.h>


enum {
	MSG_NEW_PLAYLIST = 'nwpl'
};


CherryBlossomWindow::CherryBlossomWindow()
	: BWindow(BRect(30, 30, 900, 600), "Cherry Blossom", B_TITLED_WINDOW,
		B_AUTO_UPDATE_SIZE_LIMITS),
	fPlaylistView(NULL),
	fMusicView(NULL),
	fPlaylistCount(0) {
	_CreateGUI();
}
//---------------------------------------------------------------------------------------------------------------------------------//


CherryBlossomWindow::~CherryBlossomWindow() {
}
//---------------------------------------------------------------------------------------------------------------------------------//


void
CherryBlossomWindow::MessageReceived(BMessage* message) {
	switch (message->what) {
		case MSG_NEW_PLAYLIST:
		{
			BString name("Untitled Playlist");
			fPlaylistCount++;
			if (fPlaylistCount > 1)
				name << " " << fPlaylistCount;
			fPlaylistView->AddPlaylist(name.String());
			break;
		}

		default:
			BWindow::MessageReceived(message);
			break;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------//


bool
CherryBlossomWindow::QuitRequested() {
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}
//---------------------------------------------------------------------------------------------------------------------------------//


void
CherryBlossomWindow::_CreateGUI() {
	fPlaylistView = new PlayListView("playlists");
	fMusicView = new MusicView("music");

	BSplitView* content = new BSplitView(B_HORIZONTAL, 1.0f);
	content->AddChild(fPlaylistView);
	content->AddChild(fMusicView);
	fPlaylistView->SetExplicitMinSize(BSize(150, B_SIZE_UNSET));
	fPlaylistView->SetExplicitMaxSize(BSize(260, B_SIZE_UNLIMITED));

	BLayoutBuilder::Group<>(this, B_VERTICAL, 0)
		.Add(_CreateMainMenu())
		.Add(content);

	SetSizeLimits(640, B_SIZE_UNLIMITED, 400, B_SIZE_UNLIMITED);
}
//---------------------------------------------------------------------------------------------------------------------------------//


BMenuBar*
CherryBlossomWindow::_CreateMainMenu() {
	BMenuBar* menuBar = new BMenuBar("main menu");
	BMenu* fileMenu = new BMenu("File");
	fileMenu->AddItem(new BMenuItem("New Playlist",
		new BMessage(MSG_NEW_PLAYLIST), 'N'));
	fileMenu->AddSeparatorItem();
	fileMenu->AddItem(new BMenuItem("Quit",
		new BMessage(B_QUIT_REQUESTED), 'Q'));
	menuBar->AddItem(fileMenu);
	return menuBar;
}
//---------------------------------------------------------------------------------------------------------------------------------//

