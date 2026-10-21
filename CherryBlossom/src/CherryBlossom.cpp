/*
 * Copyright (c) 2010, Bryce Groff.
 * Copyright (c) 2026, Cherry Blossom contributors.
 * Distributed under the terms of the MIT licence.
 */

#include "CherryBlossom.h"

#include "CherryBlossomWindow.h"

#include <stdlib.h>


const char* const kApplicationSignature = "application/x-vnd.CherryBlossom";


CherryBlossom::CherryBlossom()
	: BApplication(kApplicationSignature),
	fMainWindow(NULL) {
}
//---------------------------------------------------------------------------------------------------------------------------------//


CherryBlossom::~CherryBlossom() {
}
//---------------------------------------------------------------------------------------------------------------------------------//


void
CherryBlossom::ReadyToRun() {
	if (fMainWindow == NULL)
		fMainWindow = new CherryBlossomWindow();

	fMainWindow->Show();
}
//---------------------------------------------------------------------------------------------------------------------------------//


int
main() {
	CherryBlossom application;
	application.Run();
	return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------------------------------------------------------------//

