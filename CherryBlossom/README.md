# Cherry Blossom

Cherry Blossom is a native music library and media player for Haiku. This tree
is the maintained successor to the historical prototype in
`../CherryBlossom-Original`.

The first modernisation pass preserves the original split library layout and
reusable native controls while removing the obsolete TagLib build dependency.
It currently provides the application shell, library categories, and playlist
creation. Media scanning, metadata, persistence, and playback still need to be
implemented.

## Build

On Haiku, build with the platform's Generic Makefile engine:

```sh
cd src
make
```

The resulting `CherryBlossom` application is written to the `src` directory.

Run all checks (and the build when running on Haiku) with:

```sh
./scripts/check.sh
```

## Historical source

The original source remains unchanged in `CherryBlossom-Original`. Code moved
into this maintained tree keeps the original copyright and MIT licence.
