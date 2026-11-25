# Creating RenkuBASIC - Planning document

RenkuBASIC is a programming langage based on yabasic, that can access both ncurses and the Haiku/RenkuOS API (see AGENTS.md)

RenkuBASIC code will be lagely backwards-compatible with yab, but rebased on version  2.92.1 of yabasic and by modular design able to be updated easily as new versions of the underlying yabasic become available.

From a discussion forum post (https://forum.desktoponfire.com/d/97-embracing-extending-but-not-extinguishing-yab):

```

I believe that we do need an easy entryway into RenkuOS development. We have yab, and for now that will do. But in the longer run, we need something of our own.

Yab was forked from yabasic many years ago. But yabasic has not stood still. For example, it can now directly use C libraries. That sort of development never made it into yab.

I have successfully compiled the latest yabasic to run in Haiku, although the "graphic-window" remains a problem. But with a little [cough] external [cough] assistance, I think it would be possible to create a new dialect of BASIC that is

- Unique to RenkuOS
- backwards-compatible with yab, at least for now
- based on the latest version of yabasic, and easily patched to match new yabasic versions.
- able to create both CLI and GUI programs (ncurses compiled back in)
- Interpreter-only. The circumstances that created two forms of pseudo-compilation don't exist any more. That was a different software universe. It will be easy enough to create a little C++ stub launcher if it is important that every program shows up under its own icon in the Deskbar.
- supplied with its own IDE
- and with better documentation. To have the yab and yabasic commands in different documents after all these years is becoming a bit ridiculous.

```

Sources: https://github.com/marcIhm/yabasic 
https://github.com/bbjimmy/YAB
https://github.com/lorglas/yab

The yabasic and yab directories in this project are for reference purposes, shoud be read together with the sources above, and will be deleted upon completion. Build the new program in a directory called /src. Ignore the branch naming conventions in AGENTS.md. Since this is neither a BeOS conversion nor a QT4 conversion, all code may be pushed to the main branch.

Phase 0: Refine this planning document (keep a copy of the original document). create tests from the yabasic and  yab example directories. New/changed abilities:
- add "haiku" and renkuos" as operating systems detected, in addition to "windows" and "unix"
- Remove ability to "bind" programs from code and from documentation
- yabasic's graphic-mode needs to be rewritten to work with TrueType/OpenType fonts, since Haiku/RenkuOS does not come with bitmap fonts.
- take note of any windows-only or unix-only abilities and ask permission to remove them.
- all references to "yab" or "yabasic" to be changed to "RenkuBASIC", except where there is a historical context to be preserved e.g. "RenkuBASIC is based on yabasic".
- If any requested feature removal above would lead to major cascading changes in the code, it is acceptable to leave it in the code as cruft and remove it from the online help and documentation. Make a note of it for future rounds of refactoring. In case of uncertainty of what would be "major", ask the user.
- Create test suites for CLI and graphical modes
- The planning document and test suites may be added to, adapted or deleted from as the development process proceeds.

We will NOT be writing an IDE in this round of development.
 
Phase 1: compile yabasic with above modifications. Push modifications, User will compile and run CLI test suite
-iterate until faultless compilation 

Phase 2: add Haiku/RenkuOS API access.  Push modifications, User will compile and run CLI test suite
-iterate until faultless compilation 

Phase 3: Write unified documentation in markdown format. 

Phase 4: Clean up unused files. 

Phase 5: write a document of about 500 words listing the steps taken to create this build. Name it ./BUILDREPORT.md

