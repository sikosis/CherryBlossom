#!/bin/sh

set -eu

project_directory=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)

for source_file in \
	"$project_directory/src/CherryBlossom.cpp" \
	"$project_directory/src/CherryBlossomWindow.cpp" \
	"$project_directory/src/views/MusicView.cpp" \
	"$project_directory/src/views/PlayListView.cpp"
do
	test -s "$source_file"
done

if grep -R -n -E '[[:blank:]]+$' \
		"$project_directory/README.md" \
		"$project_directory/Jamfile" \
		"$project_directory/src/CherryBlossom.cpp" \
		"$project_directory/src/CherryBlossom.h" \
		"$project_directory/src/CherryBlossomWindow.cpp" \
		"$project_directory/src/CherryBlossomWindow.h" \
		"$project_directory/src/views/MusicView.cpp" \
		"$project_directory/src/views/MusicView.h" \
		"$project_directory/src/views/PlayListView.cpp" \
		"$project_directory/src/views/PlayListView.h"
then
	echo "Trailing whitespace found in maintained source files." >&2
	exit 1
fi

if command -v findpaths >/dev/null 2>&1
then
	make -C "$project_directory/src"
else
	echo "Source checks passed; Haiku build skipped because findpaths is unavailable."
fi
