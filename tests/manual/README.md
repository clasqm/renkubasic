# Manual (interactive) tests

These programs need a person in front of the screen. They cover the parts of the
yab compatibility layer that cannot be checked without clicking: modal alerts,
the file and save panels, popup menus, and the exact text of the messages that
widgets send.

They are **not** part of `--suite all`. Run one at a time:

```sh
tests/run-tests.sh --suite manual --filter m0100 --verbose
```

`tests/run-tests.sh` treats the exit status as the verdict, so a program that
ends because you closed its window passes, and a program that crashes fails.

| Test | What to do | What to look for |
| --- | --- | --- |
| `m0100-alerts.yab` | click each of the five alert buttons, then Quit | five different icons; readable text; Quit ends the program |
| `m0101-filepanel-popupmenu.yab` | Load file, Save file, Popup, then close the window | panels open on `/boot/home`, cancelling changes nothing, the chosen file/menu entry is shown |
| `m0102-widget-messages.yab` | use every widget, type into the text control | each action prints a message in the view; the text format matches yab 1.8.3; closing ends the program |

## Why these are separate

Automated GUI tests (`tests/gui/`) create every widget, change its state through
the documented setters, read the state back through the getters and take a
screenshot. That covers the widget layer without a person, but it cannot prove
that a modal panel behaves well, and it cannot prove that a mouse click produces
the message string a yab program expects. Those two things are checked here.

## Sound and media

`mediasound` and `sound` are left to the maintainer's own check with a real
media file: the reference examples use `Examples/yab_testsong.mp3`, which is not
part of this repository. The commands are exercised automatically only to the
extent that they parse (see `tests/gui/g0114-slider-status.yab` for the volume
poke and `docs/platform-inventory.md` §5 for the command list).
