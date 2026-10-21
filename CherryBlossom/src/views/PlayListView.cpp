/*
 * Copyright (c) 2010, Bryce Groff.
 * Copyright (c) 2026, Cherry Blossom contributors.
 * Distributed under the terms of the MIT licence.
 */

#include "PlayListView.h"

#include <LayoutBuilder.h>
#include <ListView.h>
#include <ScrollView.h>
#include <StringItem.h>


PlayListView::PlayListView(const char* name)
	: BView(name, B_WILL_DRAW),
	fListView(new BListView("playlist list")) {
	SetViewUIColor(B_PANEL_BACKGROUND_COLOR);
	fListView->AddItem(new BStringItem("Library"));
	fListView->Select(0);

	BLayoutBuilder::Group<>(this, B_VERTICAL, 0)
		.SetInsets(B_USE_DEFAULT_SPACING)
		.Add(new BScrollView("playlist scroll view", fListView, 0, false, true));
}
//---------------------------------------------------------------------------------------------------------------------------------//


PlayListView::~PlayListView() {
}
//---------------------------------------------------------------------------------------------------------------------------------//


void
PlayListView::AddPlaylist(const char* name) {
	if (name == NULL || name[0] == '\0')
		return;

	fListView->AddItem(new BStringItem(name));
	fListView->Select(fListView->CountItems() - 1);
}
//---------------------------------------------------------------------------------------------------------------------------------//

