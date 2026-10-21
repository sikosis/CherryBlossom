/*
 * Copyright (c) 2010, Bryce Groff.
 * Copyright (c) 2026, Cherry Blossom contributors.
 * Distributed under the terms of the MIT licence.
 */

#include "MusicView.h"

#include <Box.h>
#include <LayoutBuilder.h>
#include <SplitView.h>
#include <StringView.h>


static BBox*
CreateCategoryView(const char* label) {
	BBox* box = new BBox(label);
	box->SetLabel(label);
	BLayoutBuilder::Group<>(box, B_VERTICAL)
		.SetInsets(B_USE_DEFAULT_SPACING)
		.Add(new BStringView("empty category", "No music in the library"))
		.AddGlue();
	return box;
}
//---------------------------------------------------------------------------------------------------------------------------------//


MusicView::MusicView(const char* name)
	: BView(name, B_WILL_DRAW) {
	SetViewUIColor(B_PANEL_BACKGROUND_COLOR);

	BSplitView* categories = new BSplitView(B_HORIZONTAL, 1.0f);
	categories->AddChild(CreateCategoryView("Artists"));
	categories->AddChild(CreateCategoryView("Albums"));
	categories->AddChild(CreateCategoryView("Genres"));

	BBox* songs = CreateCategoryView("Songs");
	BSplitView* content = new BSplitView(B_VERTICAL, 1.0f);
	content->AddChild(categories);
	content->AddChild(songs);

	BLayoutBuilder::Group<>(this, B_VERTICAL, 0)
		.SetInsets(B_USE_DEFAULT_SPACING)
		.Add(content);
}
//---------------------------------------------------------------------------------------------------------------------------------//


MusicView::~MusicView() {
}
//---------------------------------------------------------------------------------------------------------------------------------//

