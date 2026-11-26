/*
    RenkuBASIC --- yab compatibility layer, internal interface.

    Only what the interpreter core calls; a program never sees these. The
    public C bridge is rk_yab.h.
*/

#ifndef RK_YAB_RUNTIME_H
#define RK_YAB_RUNTIME_H

struct command;

/* Execute one cYAB* opcode: pop its arguments and call the bridge. */
void rk_yab_command(struct command *cmd);

/* Raise a BASIC runtime error when the last bridge call failed. Function
   results have no opcode to report through, so function.c calls this after
   every getter. */
void rk_yab_check(void);

/* Record the font a program selected with `draw set`, so yabasic's own
   peek$("font") reports it. A yab program picks its font with the draw command,
   not with yabasic's `font` command, and g0103 reads it back. */
void rk_yab_note_font(const char *spec);

#endif /* RK_YAB_RUNTIME_H */
