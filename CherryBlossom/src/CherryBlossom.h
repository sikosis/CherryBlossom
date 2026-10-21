/*
 * Copyright (c) 2010, Bryce Groff.
 * Copyright (c) 2026, Cherry Blossom contributors.
 * Distributed under the terms of the MIT licence.
 */

#ifndef CHERRY_BLOSSOM_H
#define CHERRY_BLOSSOM_H

#include <Application.h>
#include <Window.h>


extern const char* const kApplicationSignature;


class CherryBlossom : public BApplication {
public:
	CherryBlossom();
	virtual ~CherryBlossom();

	virtual void ReadyToRun();

private:
	BWindow* fMainWindow;
};


#endif
